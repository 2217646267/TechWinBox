#include "serialport.h"
#include <QFile>
#include <QDebug>
#include <QSerialPortInfo>

#define UART_BAUD_RATE 115200

#ifdef __ARM__
#define UART_PORT_NAME "/dev/ttyS4"
#else
#define UART_PORT_NAME "/dev/ttyUSB2"
#endif

SerialPort::SerialPort(QObject* parent) : QObject(parent) {
    serial = new QSerialPort(this);
    sendTmr.setInterval(50);
    connect(&sendTmr, SIGNAL(timeout()), SLOT(onSendTmrout()));
}

bool SerialPort::isOpen() {
    return (serial && serial->isOpen());
}

void SerialPort::listAvailablePorts() {
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    qDebug() << "可用串口列表：";
    for (const QSerialPortInfo &port : ports) {
        qDebug() << "串口名称：" << port.portName();
        emit onSendportName(port.portName());
        qDebug() << "描述：" << port.description();
        qDebug() << "制造商：" << port.manufacturer();
        qDebug() << "----------------------------------------";
    }
}

bool SerialPort::open(QString portName, int baudRate) {

    qDebug() << "正在检查串口" << portName << "是否存在...";
    listAvailablePorts();
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    bool portExists = false;
    for (const QSerialPortInfo &port : ports) {
        if (port.portName() == portName) {
            portExists = true;
            break;
        }
    }
    if (!portExists) {
        qDebug() << "串口" << portName << "不存在。";
        emit error(portName, QSerialPort::DeviceNotFoundError, "设备未找到");
        return false;
    } else {
        qDebug() << "串口" << portName << "存在。";
    }

    if (serial->isOpen()) {
        disconnect(serial, nullptr, nullptr, nullptr);
        serial->close();
    }

    if (portName.isEmpty()) {
        portName = UART_PORT_NAME;
    }

    qDebug() << "Opening port:" << portName << "Baudrate:" << baudRate;
    serial->setPortName(portName);
    serial->setBaudRate(baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);

    //sudo chmod 666 /dev/ttyUSB0
    //ls -l /dev/ttyUSB0
    if (serial->open(QIODevice::ReadWrite)) {
        serial->clearError();
        serial->clear();
        connect(serial, &QSerialPort::readyRead, this, &SerialPort::onReadyRead);
        connect(serial, QOverload<QSerialPort::SerialPortError>::of(&QSerialPort::error),
                this, &SerialPort::handleError);
        emit connected(portName);
        return true;
    } else {
        emit error(portName, serial->error(), serial->errorString());
        return false;
    }
}

void SerialPort::close() {
    if (serial->isOpen()) {
        serial->close();
        disconnect(serial, nullptr, nullptr, nullptr);
        emit disconnected();
    } else {
        emit status("Not connected");
    }
}

void SerialPort::writeData(const QString str)
{
    QByteArray data;
    data.append(str);
    writeData(data);
}

void SerialPort::writeData(const QByteArray &data, bool direct) {
    if (direct) {
        writePort(data);
    } else {
        sendList.append(data);
        if (!sendTmr.isActive()) {
            sendTmr.start();
        }
    }
}

void SerialPort::writeData(const char *data, int len) {
    if (serial->isOpen()) {
        qint64 bytesWritten = serial->write(data, len);
        if (bytesWritten == -1) {
            qDebug() << "Write error:" << serial->errorString();
            emit error(serial->portName(), serial->error(), serial->errorString());
        }
    } else {
        emit status("Not connected");
    }
}

QByteArray SerialPort::readData() {
    QByteArray buf;
    buf.clear();
    while (serial->bytesAvailable() > 0) {
        buf.append(serial->readAll());
    }
    if (buf.length() > 0) {
        emit read(buf);
    } else {
        qDebug() << "Buffer is empty.";
    }
    return buf;
}

void SerialPort::handleError() {
    if (serial->error()) {
        qDebug() << "Error:" << serial->error();
        if (serial->error() == QSerialPort::ResourceError) {
            emit error(serial->portName(), (int)serial->error(), serial->errorString());
        }
    }
}

void SerialPort::onReadyRead() {
    readData();
}

void SerialPort::onSendTmrout() {
    if (sendList.isEmpty()) {
        sendTmr.stop();
        return;
    }

    QByteArray data = sendList.at(0);
    sendList.removeAt(0);
    writePort(data);
}

void SerialPort::writePort(const QByteArray &data) {
    if (serial->isOpen()) {
        qint64 bytesWritten = serial->write(data);
        if (bytesWritten == -1) {
            qDebug() << "Write error:" << serial->errorString();
            emit error(serial->portName(), static_cast<int>(serial->error()), serial->errorString());
        }
    } else {
        qDebug() << "Port not connected.";
        emit status("Not connected");
    }
}



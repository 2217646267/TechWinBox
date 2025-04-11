#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QSerialPort>



class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject* parent = nullptr);
    bool isOpen();

signals:
    void connected(QString portName);
    void error(QString portName, int  errorType, QString errorString);
    void disconnected();
    void read(QByteArray data);
    void status(QString msg);
    void onSendportName(QString portName);
public slots:
    bool open(QString portName = QString(), int baudRate = QSerialPort::Baud9600);
    void close();
    QByteArray readData();

    void handleError();

    void writeData(const QByteArray&data,bool direct = false);
    void writeData(const QString str);
    void writeData(const char* xdata,int len);

 private slots:
     void onReadyRead();
     void onSendTmrout();

private:
    void writePort(const QByteArray & data);
    void listAvailablePorts();
private:
    QThread myThread;
    QSerialPort *serial;
    QTimer sendTmr;
    QList<QByteArray>sendList;


};

#endif // SERIALPORT_H

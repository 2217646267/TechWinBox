#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    port = new SerialPort(this);

    init();
}

Widget::~Widget()
{
    delete ui;
}

std::vector<std::pair<int, int>> Widget::find_hex_pairs(int decimal_value) {
    std::vector<std::pair<int, int>> hex_pairs;
    // 遍历所有可能的8位十六进制数作为第二个数（0x00到0xff）
    for (int b = 0x00; b <= 0xff; ++b) {
        // 计算第一个数：将decimal_value右移8位，然后与0xff进行按位与运算
        int a = (decimal_value >> 8) & 0xff;
        // 检查按位或运算结果是否等于decimal_value
        if (((a << 8) | b) == decimal_value) {

            hex_pairs.emplace_back(a, b);
        }
    }
    return hex_pairs;

}

void Widget::SendData(QString strdata)
{
    QByteArray data;
    QString str = strdata;
    for (int i = 0; i < str.length(); ++i) {
        data.append(static_cast<char>(str[i].toLatin1()));
    }
    data.append(0x0D);   // CR的ASCII码
    data.append(0x0A);   // LF的ASCII码
    port->writeData(data);
}

void Widget::init()
{
    ui->transmissionTemperature_slider->setMaximum(250);
    ui->Coolant_Temperature_slider->setMaximum(250);
    ui->Intake_Air_Temperature_slider->setMaximum(250);
    ui->Engine_Calculated_Load_slider->setMaximum(100);
    ui->RPM_slider->setMaximum(10000);
    initConnect();
    initGaugeConnect();
    initVechicleConnect();
    initPaikingConnect();
    initParkingAssistConnect();
    initSwCButtonConnect();
}

void Widget::initConnect()
{
    connect(ui->open_btn,&QPushButton::clicked, this, [=](){
        bool bOpen = port->open("ttyUSB0",115200);
        bOpen == true ? ui->open_btn->setText("Ok") : ui->open_btn->setText("error");
        qDebug() << bOpen;
    });
    connect(port, &SerialPort::read,[=](QByteArray data){
        QString string = QString::fromUtf8(data);
        //ui->textEdit->clear();
        ui->textEdit->append(string);
        // qDebug() << string;

    });
    connect(ui->clear_edit,&QPushButton::clicked, this, [=](){
        ui->textEdit->clear();
    });
    connect(ui->close_btn,&QPushButton::clicked, this, [=](){
        port->close();
    });
}

void Widget::initGaugeConnect()
{
    connect(ui->transmissionTemperature_slider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" <<  ui->transmissionTemperature_slider->value();
        int decimal_input = ui->transmissionTemperature_slider->value() + 100;
        auto hex_pairs = find_hex_pairs(decimal_input);
        // 输出所有可能的十六进制数对
        for (const auto& pair : hex_pairs) {
            qDebug() << "0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'))  << " 和 0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'));
            QString type1 = QString("%1").arg(pair.first, 2, 16, QLatin1Char('0')) ;
            QString type2 = QString("%1").arg(pair.second, 2, 16, QLatin1Char('0')) ;
            QString strdata = QString("EID 19 12 %1").arg(type1);
            SendData(strdata);
            QString strdata2 = QString("EID 19 13 %1").arg(type2);
            SendData(strdata2);
            SendData("SID 19");
        }
    });
    connect(ui->transmissionTemperature_slider,&QSlider::sliderMoved, this, [=](int value){
        ui->label_6->clear();
        ui->label_6->setText(QString("Transmission Temperature %1").arg(value));
    });

    connect(ui->Coolant_Temperature_slider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" <<  ui->Coolant_Temperature_slider->value();
        int decimal_input = ui->Coolant_Temperature_slider->value() + 100;
        auto hex_pairs = find_hex_pairs(decimal_input);
        // 输出所有可能的十六进制数对
        for (const auto& pair : hex_pairs) {
            qDebug() << "0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'))  << " 和 0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'));
            QString type1 = QString("%1").arg(pair.first, 2, 16, QLatin1Char('0')) ;
            QString type2 = QString("%1").arg(pair.second, 2, 16, QLatin1Char('0')) ;
            QString strdata = QString("EID 19 14 %1").arg(type1);
            SendData(strdata);
            QString strdata2 = QString("EID 19 15 %1").arg(type2);
            SendData(strdata2);
            SendData("SID 19");
        }
    });
    connect(ui->Coolant_Temperature_slider,&QSlider::sliderMoved, this, [=](int value){
        ui->label_5->clear();
        ui->label_5->setText(QString("Coolant Temperature %1").arg(value));
    });

    connect(ui->Intake_Air_Temperature_slider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" <<  ui->Intake_Air_Temperature_slider->value();
        int decimal_input = ui->Intake_Air_Temperature_slider->value() + 100;
        auto hex_pairs = find_hex_pairs(decimal_input);
        // 输出所有可能的十六进制数对
        for (const auto& pair : hex_pairs) {
            qDebug() << "0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'))  << " 和 0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'));
            QString type1 = QString("%1").arg(pair.first, 2, 16, QLatin1Char('0')) ;
            QString type2 = QString("%1").arg(pair.second, 2, 16, QLatin1Char('0')) ;
            QString strdata = QString("EID 19 19 %1").arg(type1);
            SendData(strdata);
            QString strdata2 = QString("EID 19 1a %1").arg(type2);
            SendData(strdata2);
            SendData("SID 19");
        }
    });
    connect(ui->Intake_Air_Temperature_slider,&QSlider::sliderMoved, this, [=](int value){
        ui->label_4->clear();
        ui->label_4->setText(QString("Intake Air Temperature %1").arg(value));
    });

    connect(ui->Engine_Calculated_Load_slider,&QSlider::sliderReleased, this, [=](){
        int decimal_input = ui->Engine_Calculated_Load_slider->value();
        QString str =  QString("%1").arg(decimal_input, 2, 16, QLatin1Char('0'));
        qDebug() << "-----------" <<str;
        QString strdata2 = QString("EID 19 1b %1").arg(str);
        SendData(strdata2);
        SendData("SID 19");

    });
    connect(ui->Engine_Calculated_Load_slider,&QSlider::sliderMoved, this, [=](int value){
        ui->label_3->clear();
        ui->label_3->setText(QString("Engine Calculated Load %1").arg(value));
    });

    connect(ui->RPM_slider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" <<  ui->RPM_slider->value();
        int decimal_input = ui->RPM_slider->value();
        auto hex_pairs = find_hex_pairs(decimal_input);
        // 输出所有可能的十六进制数对
        for (const auto& pair : hex_pairs) {
            qDebug() << "0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'))  << " 和 0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'));
            QString type1 = QString("%1").arg(pair.first, 2, 16, QLatin1Char('0')) ;
            QString type2 = QString("%1").arg(pair.second, 2, 16, QLatin1Char('0')) ;
            QString strdata = QString("EID 06 07 %1").arg(type1);
            SendData(strdata);
            QString strdata2 = QString("EID 06 08 %1").arg(type2);
            SendData(strdata2);
            SendData("SID 06");
        }
    });
    connect(ui->RPM_slider,&QSlider::sliderMoved, this, [=](int value){
        ui->label_2->clear();
        ui->label_2->setText(QString("RPM %1").arg(value));
    });


}

void Widget::initVechicleConnect()
{
    m_vechMap.insert(ui->Press_LF, 27);
    m_vechMap.insert(ui->Press_RF, 28);
    m_vechMap.insert(ui->Press_RR, 29);
    m_vechMap.insert(ui->Press_LR, 30);
    m_vechMap.insert(ui->Temp_LF, 41);
    m_vechMap.insert(ui->Temp_RF, 42);
    m_vechMap.insert(ui->Temp_RR, 43);
    m_vechMap.insert(ui->Temp_LR, 44);

    buttonGroup = new QButtonGroup(this);
    QMapIterator<QRadioButton*,int> it(m_vechMap);
    while (it.hasNext()) {
        it.next();
        buttonGroup->addButton(it.key(),it.value());
    }
    buttonGroup->addButton(ui->battery);
    connect(ui->VechicleSlider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" << ui->VechicleSlider->value();
        QString str = "";
        QString strID = "";
        if (buttonGroup->checkedButton() == ui->Press_LF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_LF), 2, 16, QLatin1Char('0'));
            strID = 06;
        } else if (buttonGroup->checkedButton() == ui->Press_RF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_LF), 2, 16, QLatin1Char('0'));
            strID = 06;

        } else if (buttonGroup->checkedButton() == ui->Press_RR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_RR), 2, 16, QLatin1Char('0'));
            strID = 06;

        } else if (buttonGroup->checkedButton() == ui->Press_LR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_LR), 2, 16, QLatin1Char('0'));
            strID = 06;

        } else if (buttonGroup->checkedButton() == ui->Temp_LF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_LF), 2, 16, QLatin1Char('0'));
            strID = 19;

        } else if (buttonGroup->checkedButton() == ui->Temp_RF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_RF), 2, 16, QLatin1Char('0'));
            strID = 19;

        } else if (buttonGroup->checkedButton() == ui->Temp_RR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_RR), 2, 16, QLatin1Char('0'));
            strID = 19;

        } else if (buttonGroup->checkedButton() == ui->Temp_LR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_LR), 2, 16, QLatin1Char('0'));
            strID = 19;
        } else if (buttonGroup->checkedButton() == ui->battery) {
            int decimal_input = ui->VechicleSlider->value() * 100;
            auto hex_pairs = find_hex_pairs(decimal_input);
            // 输出所有可能的十六进制数对
            for (const auto& pair : hex_pairs) {
                qDebug() << "0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'))  << " 和 0x" << QString("%1").arg(pair.first, 2, 16, QLatin1Char('0'));
                QString type1 = QString("%1").arg(pair.first, 2, 16, QLatin1Char('0')) ;
                QString type2 = QString("%1").arg(pair.second, 2, 16, QLatin1Char('0')) ;
                QString strdata = QString("EID 19 0c %1").arg(type1);
                SendData(strdata);
                QString strdata2 = QString("EID 19 0d %1").arg(type2);
                SendData(strdata2);
                SendData("SID 19");
            }
        }
        if(buttonGroup->checkedButton() != ui->battery)
            {
            int decimal_input = ui->VechicleSlider->value();
            QString str2 =  QString("%1").arg(decimal_input, 2, 16, QLatin1Char('0'));
            qDebug() << "-----------" << str<< str2;
            QString strdata2 = QString("EID %1 %2 %3").arg(strID).arg(str).arg(str2);
            SendData(strdata2);
            SendData(QString("SID %1").arg(strID));
        }

    });

    buttonGroup_2 = new QButtonGroup(this);
    buttonGroup_2->addButton(ui->door_F);
    buttonGroup_2->addButton(ui->door_LF);
    buttonGroup_2->addButton(ui->door_LR);
    buttonGroup_2->addButton(ui->door_R);
    buttonGroup_2->addButton(ui->door_RF);
    buttonGroup_2->addButton(ui->door_RR);

    // 连接buttonToggled信号到槽函数
    connect(buttonGroup_2, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
            [=](QAbstractButton *button, bool checked){
                qDebug() << "Button" << button->text()
                         << "toggled to state:" << (checked ? "Checked" : "Unchecked");
        QString str = "";
        if (buttonGroup_2->checkedButton() == ui->door_F) {
            str = "EID 19 04 01";
         }
        else if (buttonGroup_2->checkedButton() == ui->door_R) {
             str = "EID 19 04 02";
        }
         else if (buttonGroup_2->checkedButton() == ui->door_LF) {
             str = "EID 19 04 04";
         }
        else if (buttonGroup_2->checkedButton() == ui->door_RF) {
            str = "EID 19 04 08";
        }
         else if (buttonGroup_2->checkedButton() == ui->door_LR) {
             str = "EID 19 04 10";
         }
        else if (buttonGroup_2->checkedButton() == ui->door_RR) {
            str = "EID 19 04 20";
        }
        qDebug() << "-----------" <<str;
        SendData(str);
        SendData("SID 19");

     });

}

void Widget::initPaikingConnect()
{
    QButtonGroup * parkingbuttonGroup = new QButtonGroup(this);
    parkingbuttonGroup->addButton(ui->FL_Outer);
    parkingbuttonGroup->addButton(ui->FL_Inner);
    parkingbuttonGroup->addButton(ui->FR_Inner);
    parkingbuttonGroup->addButton(ui->FR_Outer);
    parkingbuttonGroup->addButton(ui->RL_Outer);
    parkingbuttonGroup->addButton(ui->RL_Inner);
    parkingbuttonGroup->addButton(ui->RR_Inner);
    parkingbuttonGroup->addButton(ui->RR_Outer);
    parkingbuttonGroup->addButton(ui->L_Blind_spot);
    parkingbuttonGroup->addButton(ui->R_Blind_spot);

    // 连接buttonToggled信号到槽函数
    connect(parkingbuttonGroup, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
            [=](QAbstractButton *button, bool checked){
                qDebug() << "Button" << button->text()
                         << "toggled to state:" << (checked ? "Checked" : "Unchecked");
        QString str = "";
        QString strValue = "";
        if (parkingbuttonGroup->checkedButton() == ui->FL_Outer) {
            str = "EID 2a 04 01";
         }
        else if (parkingbuttonGroup->checkedButton() == ui->FL_Inner) {
             str = "EID 2a 04 02";
        }
         else if (parkingbuttonGroup->checkedButton() == ui->FR_Inner) {
             str = "EID 2a 04 03";
         }
        else if (parkingbuttonGroup->checkedButton() == ui->FR_Outer) {
            str = "EID 2a 04 04";
        }
         else if (parkingbuttonGroup->checkedButton() == ui->RL_Outer) {
             str = "EID 2a 04 05";
         }
        else if (parkingbuttonGroup->checkedButton() == ui->RL_Inner) {
            str = "EID 2a 04 06";
        }
         else if (parkingbuttonGroup->checkedButton() == ui->RR_Inner) {
             str = "EID 2a 04 07";
         }
        else if (parkingbuttonGroup->checkedButton() == ui->RR_Outer) {
            str = "EID 2a 04 08";
        }
         else if (parkingbuttonGroup->checkedButton() == ui->L_Blind_spot) {
             str = "EID 2a 04 09";
         }
        else if (parkingbuttonGroup->checkedButton() == ui->R_Blind_spot) {
            str = "EID 2a 04 0A";
        }
        strValue = ui->lineEdit->text();
        qDebug() << "-----------" <<str;
        SendData(str);
        SendData(QString("EID 2a 05 0%1").arg(strValue));
        SendData("SID 2a");
    });
}

void Widget::initParkingAssistConnect()
{
    QButtonGroup * parkingbuttonGroup = new QButtonGroup(this);
    parkingbuttonGroup->addButton(ui->Vehicle_Properties);
    parkingbuttonGroup->addButton(ui->HVAC);
    parkingbuttonGroup->addButton(ui->Customization_menu);
    parkingbuttonGroup->addButton(ui->Home);
    parkingbuttonGroup->addButton(ui->Radio_settings);

    // 连接buttonToggled信号到槽函数
    connect(parkingbuttonGroup, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
            [=](QAbstractButton *button, bool checked){
                qDebug() << "Button" << button->text()
                         << "toggled to state:" << (checked ? "Checked" : "Unchecked");
                QString str = "";
                QString strValue = "";
                if (parkingbuttonGroup->checkedButton() == ui->Vehicle_Properties) {
                    str = "EID 17 04 01";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->HVAC) {
                    str = "EID 17 04 02";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->Customization_menu) {
                    str = "EID 17 04 03";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->Home) {
                    str = "EID 17 04 04";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->Radio_settings) {
                    str = "EID 17 04 05";
                }
                qDebug() << "-----------" <<str;
                SendData(str);
                SendData("SID 17");
            });
}

void Widget::initSwCButtonConnect()
{
    QButtonGroup * parkingbuttonGroup = new QButtonGroup(this);
    parkingbuttonGroup->addButton(ui->VOLUP);
    parkingbuttonGroup->addButton(ui->VOLDWN);
    parkingbuttonGroup->addButton(ui->SEEKU);
    parkingbuttonGroup->addButton(ui->SEEKD);
    parkingbuttonGroup->addButton(ui->MODE);
    parkingbuttonGroup->addButton(ui->MUTE);
    parkingbuttonGroup->addButton(ui->PRESETU);
    parkingbuttonGroup->addButton(ui->PRESETD);

    parkingbuttonGroup->addButton(ui->PWR);
    parkingbuttonGroup->addButton(ui->BAND);
    parkingbuttonGroup->addButton(ui->PLAY_ENT);
    parkingbuttonGroup->addButton(ui->PTT);
    parkingbuttonGroup->addButton(ui->ONHOOK);
    parkingbuttonGroup->addButton(ui->OFFHOOk);
    parkingbuttonGroup->addButton(ui->Screen_Off);

    // 连接buttonToggled信号到槽函数
    connect(parkingbuttonGroup, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
            [=](QAbstractButton *button, bool checked){
                qDebug() << "Button" << button->text()
                         << "toggled to state:" << (checked ? "Checked" : "Unchecked");
                QString str = "";
                SendData("EID 08 04 00");
                SendData("EID 08 05 00");
                if (parkingbuttonGroup->checkedButton() == ui->VOLUP) {
                    str = "EID 08 04 80";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->VOLDWN) {
                    str = "EID 08 04 40";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->SEEKU) {
                    str = "EID 08 04 20";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->SEEKD) {
                    str = "EID 08 04 10";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->MODE) {
                    str = "EID 08 04 08";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->MUTE) {
                    str = "EID 08 04 04";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->PRESETU) {
                    str = "EID 08 04 02";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->PRESETD) {
                    str = "EID 08 04 01";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->PWR) {
                    str = "EID 08 05 80";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->BAND) {
                    str = "EID 08 05 40";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->PLAY_ENT) {
                    str = "EID 08 05 20";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->PTT) {
                    str = "EID 08 05 10";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->ONHOOK) {
                    str = "EID 08 05 08";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->OFFHOOk) {
                    str = "EID 08 05 04";
                }
                else if (parkingbuttonGroup->checkedButton() == ui->Screen_Off) {
                    str = "EID 08 05 02";
                }
                qDebug() << "-----------" <<str;
                SendData(str);
                SendData("SID 08");
            });
}

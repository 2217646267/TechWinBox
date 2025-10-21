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
    ui->transmissionTemperature_slider->setMaximum(251);
    ui->Coolant_Temperature_slider->setMaximum(251);
    ui->Intake_Air_Temperature_slider->setMaximum(251);
    ui->Engine_Calculated_Load_slider->setMaximum(101);
    ui->RPM_slider->setMaximum(10001);
    ui->VechicleSlider->setMaximum(255);
    initConnect();
    initGaugeConnect();
    initVechicleConnect();
    initPaikingConnect();
    initParkingAssistConnect();
    initSwCButtonConnect();
    initInfoWidget();


}

void Widget::initConnect()
{
    connect(ui->open_btn,&QPushButton::clicked, this, [=](){

        bool bOpen = port->open(ui->lineEdit_3->text(),115200);
        bOpen == true ? ui->open_btn->setText("Ok") : ui->open_btn->setText("error");
        qDebug() << bOpen;
    });
    connect(port, &SerialPort::onSendportName,[=](QString portname)
    {
        ui->plainTextEdit->appendPlainText(portname);
    });
    connect(port, &SerialPort::read,[=](QByteArray data){
        QString string = QString::fromUtf8(data);
        //ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText(string);
        // qDebug() << string;

    });
    connect(ui->clear_edit,&QPushButton::clicked, this, [=](){
        ui->plainTextEdit->clear();
    });
    connect(ui->close_btn,&QPushButton::clicked, this, [=](){
        port->close();
    });
    connect(ui->about_btn,&QPushButton::clicked, this, [=](){
        SendData("?");
    });
    connect(ui->time,&QPushButton::clicked, this, [=](){
        SendData("EID 06 0F 32");
        SendData("EID 06 10 34");
        SendData("EID 06 11 30");
        SendData("EID 06 12 34");
        SendData("EID 06 13 30");
        SendData("EID 06 14 35");
        SendData("EID 06 15 31");
        SendData("EID 06 16 32");
        SendData("EID 06 17 31");
        SendData("EID 06 18 32");
        SendData("EID 06 19 31");
        SendData("EID 06 1A 32");

        SendData("SID 06");
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

     QButtonGroup *buttonGroup = new QButtonGroup(this);
    QMapIterator<QRadioButton*,int> it(m_vechMap);
    while (it.hasNext()) {
        it.next();
        buttonGroup->addButton(it.key(),it.value());
    }
    buttonGroup->addButton(ui->battery);
    ui->Malfunction_Indicator->setCheckable(true);
    connect(ui->Malfunction_Indicator,&QPushButton::clicked, this,[=](bool b)
            {

        QString strdata = QString("EID 06 1f 0%1").arg(b);
                SendData(strdata);
                SendData("SID 06");
                qDebug() << "-----------" <<strdata;
            });

    connect(ui->VechicleSlider,&QSlider::sliderReleased, this, [=](){
        qDebug() << "-----------" << ui->VechicleSlider->value();
        ui->current_label_press->clear();
        ui->current_label_Tmod->clear();
        ui->current_label_MIL->clear();
        QString str = "";
        QString strID = "";
        if (buttonGroup->checkedButton() == ui->Press_LF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_LF), 2, 16, QLatin1Char('0'));
            strID = "06";
             ui->current_label_press->setText("当前胎压:"+QString::number(ui->VechicleSlider->value()));
        } else if (buttonGroup->checkedButton() == ui->Press_RF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_RF), 2, 16, QLatin1Char('0'));
            strID = "06";
             ui->current_label_press->setText("当前胎压:"+QString::number(ui->VechicleSlider->value()));

        } else if (buttonGroup->checkedButton() == ui->Press_RR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_RR), 2, 16, QLatin1Char('0'));
            strID = "06";
             ui->current_label_press->setText("当前胎压:"+QString::number(ui->VechicleSlider->value()));

        } else if (buttonGroup->checkedButton() == ui->Press_LR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Press_LR), 2, 16, QLatin1Char('0'));
            strID = "06";
            ui->current_label_press->setText("当前胎压:"+QString::number(ui->VechicleSlider->value()));

        } else if (buttonGroup->checkedButton() == ui->Temp_LF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_LF), 2, 16, QLatin1Char('0'));
            strID = "19";
            ui->current_label_Tmod->setText("当前胎温:"+QString::number(ui->VechicleSlider->value() - 40));

        } else if (buttonGroup->checkedButton() == ui->Temp_RF) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_RF), 2, 16, QLatin1Char('0'));
            strID = "19";
            ui->current_label_Tmod->setText("当前胎温:"+QString::number(ui->VechicleSlider->value() - 40));
        } else if (buttonGroup->checkedButton() == ui->Temp_RR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_RR), 2, 16, QLatin1Char('0'));
            strID = "19";
            ui->current_label_Tmod->setText("当前胎温:"+QString::number(ui->VechicleSlider->value() - 40));
        } else if (buttonGroup->checkedButton() == ui->Temp_LR) {
            str =  QString("%1").arg(m_vechMap.value(ui->Temp_LR), 2, 16, QLatin1Char('0'));
            strID = "19";
            ui->current_label_Tmod->setText("当前胎温:"+QString::number(ui->VechicleSlider->value() - 40));
        } else if (buttonGroup->checkedButton() == ui->battery) {

            int decimal_input = ui->VechicleSlider->value() * 100;
            ui->current_label_MIL->setText("当前电池:"+QString::number(decimal_input/10));
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
        qDebug() << "---- 444444-------" <<strID;
        if(buttonGroup->checkedButton() != ui->battery)
            {
            int decimal_input = ui->VechicleSlider->value();
             qDebug() << "---- 555555-------" <<strID;
            QString str2 =  QString("%1").arg(decimal_input, 2, 16, QLatin1Char('0'));
            qDebug() << "-----------" << str<< str2;
            QString strdata2 = QString("EID %1 %2 %3").arg(strID).arg(str).arg(str2);

            SendData(strdata2);
            SendData(QString("SID %1").arg(strID));
            qDebug() << "---- 77777-------" <<strdata2;
            qDebug() << "---- 88888-------" <<QString("SID %1").arg(strID) << strID;

        }        
    });

    QButtonGroup *buttonGroup_2 = new QButtonGroup(this);
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
        QString string = "传感器值由 Metra 接口以厘米为单位发送。主机应根据距离值决定点亮多少个 GUI 元素：\n\
                                 阈值由主机自行设定，建议如下：\n\
                                 ≤30 cm – 障碍物非常近\n\
                                 30 cm–90 cm – 障碍物中等距离\n\
                                 91 cm–150 cm – 障碍物较远\n\
                                 ＞150 cm – 无障碍物";
        ui->plainTextEdit->appendPlainText(string);
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
        bool ok = false;
        int intValue =  ui->lineEdit->text().toInt(&ok);
      //  strValue = strValue, 2, 16, QLatin1Char('0');
        strValue =  QString("%1").arg(intValue, 2, 16, QLatin1Char('0'));
        SendData(str);
        QString hex = QString::number(intValue, 16).toUpper();
        qDebug() << "-----------" <<str << intValue << hex << strValue;
        SendData(QString("EID 2a 05 %1").arg(strValue));
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
    connect(parkingbuttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            [=](QAbstractButton *button){
                qDebug() << "Button" << button->text()
                         /*<< "toggled to state:" << (checked ? "Checked" : "Unchecked")*/;
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

void Widget::onButtonClicked(QAbstractButton *button) {
    SendData(button->text());
    qDebug() << "-----------" << button->text();
}

void Widget::initInfoWidget()
{
    QButtonGroup * parkingbuttonGroup = new QButtonGroup(this);
    parkingbuttonGroup->addButton(ui->pushButton_3);
    parkingbuttonGroup->addButton(ui->pushButton_2);
    parkingbuttonGroup->addButton(ui->pushButton);
    parkingbuttonGroup->addButton(ui->pushButton_4);
    parkingbuttonGroup->addButton(ui->pushButton_5);
    parkingbuttonGroup->addButton(ui->pushButton_6);
    parkingbuttonGroup->addButton(ui->about_btn);
    connect(parkingbuttonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &Widget::onButtonClicked);

    connect(ui->R_btn,&QPushButton::clicked,this, [=]()
{
        SendData(ui->R_btn->text());
});

    connect(ui->H_btn,&QPushButton::clicked,this, [=]()
{
    SendData(ui->H_btn->text());
});

connect(ui->RAW_btn,&QPushButton::clicked,this, [=]()
        {
            SendData(ui->RAW_btn->text());
        });


}



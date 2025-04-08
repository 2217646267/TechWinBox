/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *about_btn;
    QPushButton *open_btn;
    QTextEdit *textEdit;
    QPushButton *close_btn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *Gauge;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSlider *transmissionTemperature_slider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSlider *Coolant_Temperature_slider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSlider *Intake_Air_Temperature_slider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *Engine_Calculated_Load_slider;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *RPM_slider;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clear_edit;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *Gauge_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *Press_LF;
    QRadioButton *Press_RF;
    QRadioButton *Press_RR;
    QRadioButton *Press_LR;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *Temp_LF;
    QRadioButton *Temp_RF;
    QRadioButton *Temp_RR;
    QRadioButton *Temp_LR;
    QRadioButton *battery;
    QSlider *VechicleSlider;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *door_RR;
    QRadioButton *door_LR;
    QRadioButton *door_RF;
    QRadioButton *door_LF;
    QRadioButton *door_R;
    QRadioButton *door_F;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1161, 679);
        about_btn = new QPushButton(Widget);
        about_btn->setObjectName(QString::fromUtf8("about_btn"));
        about_btn->setGeometry(QRect(640, 110, 89, 25));
        open_btn = new QPushButton(Widget);
        open_btn->setObjectName(QString::fromUtf8("open_btn"));
        open_btn->setGeometry(QRect(640, 60, 89, 25));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 601, 151));
        close_btn = new QPushButton(Widget);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setGeometry(QRect(810, 60, 89, 25));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 180, 621, 281));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Gauge = new QLabel(widget);
        Gauge->setObjectName(QString::fromUtf8("Gauge"));
        Gauge->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(17);
        Gauge->setFont(font);

        verticalLayout->addWidget(Gauge);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(200, 0));

        horizontalLayout_5->addWidget(label_6);

        transmissionTemperature_slider = new QSlider(widget);
        transmissionTemperature_slider->setObjectName(QString::fromUtf8("transmissionTemperature_slider"));
        transmissionTemperature_slider->setMinimumSize(QSize(150, 40));
        transmissionTemperature_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(transmissionTemperature_slider);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(label_5);

        Coolant_Temperature_slider = new QSlider(widget);
        Coolant_Temperature_slider->setObjectName(QString::fromUtf8("Coolant_Temperature_slider"));
        Coolant_Temperature_slider->setMinimumSize(QSize(0, 40));
        Coolant_Temperature_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(Coolant_Temperature_slider);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(label_4);

        Intake_Air_Temperature_slider = new QSlider(widget);
        Intake_Air_Temperature_slider->setObjectName(QString::fromUtf8("Intake_Air_Temperature_slider"));
        Intake_Air_Temperature_slider->setMinimumSize(QSize(0, 40));
        Intake_Air_Temperature_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Intake_Air_Temperature_slider);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(label_3);

        Engine_Calculated_Load_slider = new QSlider(widget);
        Engine_Calculated_Load_slider->setObjectName(QString::fromUtf8("Engine_Calculated_Load_slider"));
        Engine_Calculated_Load_slider->setMinimumSize(QSize(0, 40));
        Engine_Calculated_Load_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Engine_Calculated_Load_slider);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(label_2);

        RPM_slider = new QSlider(widget);
        RPM_slider->setObjectName(QString::fromUtf8("RPM_slider"));
        RPM_slider->setMinimumSize(QSize(0, 40));
        RPM_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(RPM_slider);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        clear_edit = new QPushButton(Widget);
        clear_edit->setObjectName(QString::fromUtf8("clear_edit"));
        clear_edit->setGeometry(QRect(640, 10, 89, 25));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(630, 180, 521, 251));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Gauge_2 = new QLabel(widget_2);
        Gauge_2->setObjectName(QString::fromUtf8("Gauge_2"));
        Gauge_2->setMinimumSize(QSize(0, 40));
        Gauge_2->setFont(font);

        verticalLayout_2->addWidget(Gauge_2);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_6 = new QHBoxLayout(widget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Press_LF = new QRadioButton(widget_3);
        Press_LF->setObjectName(QString::fromUtf8("Press_LF"));

        horizontalLayout_6->addWidget(Press_LF);

        Press_RF = new QRadioButton(widget_3);
        Press_RF->setObjectName(QString::fromUtf8("Press_RF"));

        horizontalLayout_6->addWidget(Press_RF);

        Press_RR = new QRadioButton(widget_3);
        Press_RR->setObjectName(QString::fromUtf8("Press_RR"));

        horizontalLayout_6->addWidget(Press_RR);

        Press_LR = new QRadioButton(widget_3);
        Press_LR->setObjectName(QString::fromUtf8("Press_LR"));

        horizontalLayout_6->addWidget(Press_LR);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_7 = new QHBoxLayout(widget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Temp_LF = new QRadioButton(widget_4);
        Temp_LF->setObjectName(QString::fromUtf8("Temp_LF"));

        horizontalLayout_7->addWidget(Temp_LF);

        Temp_RF = new QRadioButton(widget_4);
        Temp_RF->setObjectName(QString::fromUtf8("Temp_RF"));

        horizontalLayout_7->addWidget(Temp_RF);

        Temp_RR = new QRadioButton(widget_4);
        Temp_RR->setObjectName(QString::fromUtf8("Temp_RR"));

        horizontalLayout_7->addWidget(Temp_RR);

        Temp_LR = new QRadioButton(widget_4);
        Temp_LR->setObjectName(QString::fromUtf8("Temp_LR"));

        horizontalLayout_7->addWidget(Temp_LR);

        battery = new QRadioButton(widget_4);
        battery->setObjectName(QString::fromUtf8("battery"));

        horizontalLayout_7->addWidget(battery);


        verticalLayout_2->addWidget(widget_4);

        VechicleSlider = new QSlider(widget_2);
        VechicleSlider->setObjectName(QString::fromUtf8("VechicleSlider"));
        VechicleSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(VechicleSlider);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_8 = new QHBoxLayout(widget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        door_RR = new QRadioButton(widget_5);
        door_RR->setObjectName(QString::fromUtf8("door_RR"));

        horizontalLayout_8->addWidget(door_RR);

        door_LR = new QRadioButton(widget_5);
        door_LR->setObjectName(QString::fromUtf8("door_LR"));

        horizontalLayout_8->addWidget(door_LR);

        door_RF = new QRadioButton(widget_5);
        door_RF->setObjectName(QString::fromUtf8("door_RF"));

        horizontalLayout_8->addWidget(door_RF);

        door_LF = new QRadioButton(widget_5);
        door_LF->setObjectName(QString::fromUtf8("door_LF"));

        horizontalLayout_8->addWidget(door_LF);

        door_R = new QRadioButton(widget_5);
        door_R->setObjectName(QString::fromUtf8("door_R"));

        horizontalLayout_8->addWidget(door_R);

        door_F = new QRadioButton(widget_5);
        door_F->setObjectName(QString::fromUtf8("door_F"));

        horizontalLayout_8->addWidget(door_F);


        verticalLayout_2->addWidget(widget_5);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        about_btn->setText(QCoreApplication::translate("Widget", "?", nullptr));
        open_btn->setText(QCoreApplication::translate("Widget", "open", nullptr));
        close_btn->setText(QCoreApplication::translate("Widget", "close", nullptr));
        Gauge->setText(QCoreApplication::translate("Widget", "Gauge", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Transmission Temperature", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Coolant Temperature", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Intake Air Temperature", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Engine Calculated Load", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "RPM", nullptr));
        clear_edit->setText(QCoreApplication::translate("Widget", "clear_edit", nullptr));
        Gauge_2->setText(QCoreApplication::translate("Widget", "Vechicle information", nullptr));
        Press_LF->setText(QCoreApplication::translate("Widget", "Press_LF", nullptr));
        Press_RF->setText(QCoreApplication::translate("Widget", "Press_RF", nullptr));
        Press_RR->setText(QCoreApplication::translate("Widget", "Press_RR", nullptr));
        Press_LR->setText(QCoreApplication::translate("Widget", "Press_LR", nullptr));
        Temp_LF->setText(QCoreApplication::translate("Widget", "Temp_LF", nullptr));
        Temp_RF->setText(QCoreApplication::translate("Widget", "Temp_RF", nullptr));
        Temp_RR->setText(QCoreApplication::translate("Widget", "Temp_RR", nullptr));
        Temp_LR->setText(QCoreApplication::translate("Widget", "Temp_LR", nullptr));
        battery->setText(QCoreApplication::translate("Widget", "battery", nullptr));
        door_RR->setText(QCoreApplication::translate("Widget", "door_RR", nullptr));
        door_LR->setText(QCoreApplication::translate("Widget", "door_LR", nullptr));
        door_RF->setText(QCoreApplication::translate("Widget", "door_RF", nullptr));
        door_LF->setText(QCoreApplication::translate("Widget", "door_LF", nullptr));
        door_R->setText(QCoreApplication::translate("Widget", "door_R", nullptr));
        door_F->setText(QCoreApplication::translate("Widget", "door_F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

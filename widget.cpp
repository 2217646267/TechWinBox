#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
   QVBoxLayout* m_checkBoxLayout = new QVBoxLayout();
   QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
   m_checkBoxLayout->addWidget(widhte);
   setLayout(m_checkBoxLayout);

    QLabel* pp =  new QLabel(this);

   QString str = "3000";
   double num = str.toDouble()/100;
   QString str2 = "25";
   double num2 = str2.toDouble()/100;
   qDebug() << num;
   qDebug() << num2;
   pp->setText(QString("%1").arg(num));

}

Widget::~Widget() {}

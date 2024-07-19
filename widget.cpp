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

}

Widget::~Widget() {}

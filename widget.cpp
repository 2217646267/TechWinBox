#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
    widhte->resize(1000,600);
}

Widget::~Widget() {}

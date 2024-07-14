#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
}

Widget::~Widget() {}

#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>
#include "CpFileName.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{

    QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
    widhte->resize(1000,600);
    widhte->hide();
    CpFileName* Cpwidhte = new CpFileName(this);
    Cpwidhte->resize(1000,600);

}

Widget::~Widget() {}

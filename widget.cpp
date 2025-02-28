#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>
#include "CpFileName.h"
#include "Language/test1widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{

    // QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
    // widhte->resize(1000,600);

    test1widget* widget = new test1widget(this);
    widget->resize(1000,600);

}

Widget::~Widget() {}

#include "CpFileName.h"
#include <QDebug>

CpFileName::CpFileName(QWidget *parent) : QWidget(parent)
{
    init();
    connect();
}

void CpFileName::init()
{
    QHBoxLayout* MainLayout = new QHBoxLayout();
    m_pLeftWidget = new DragDropLabel(this);
    m_pLeftWidget->setStyleSheet("background-color: yellow;");
    m_pRightWidget = new DragDropLabel(this);
    m_pRightWidget->setStyleSheet("background-color: blue;");
    MainLayout->addWidget(m_pLeftWidget);
    MainLayout->addWidget(m_pRightWidget);
    this->setLayout(MainLayout);
    QObject::connect(m_pRightWidget, &DragDropLabel::signaldropEvent, this, &CpFileName::New);
    QObject::connect(m_pLeftWidget, &DragDropLabel::signaldropEvent, this, &CpFileName::Old);
}

void CpFileName::connect()
{

}

void CpFileName::New(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
   m_NewurlList = mimeData->urls() ;
    if (mimeData->hasUrls() && m_NewurlList.size() == OldurlList.size()) {


         qDebug() << "new" << m_NewurlList;

    }
}

void CpFileName::Old(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
        OldurlList = mimeData->urls();
        qDebug()  << "old"<<OldurlList;
    }
}

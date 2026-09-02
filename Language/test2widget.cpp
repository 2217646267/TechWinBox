#include "test2widget.h"
#include "Language/language.h"

test2widget::test2widget(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumSize(500,200);
    QVBoxLayout* m_MainBoxLayout = new QVBoxLayout();

    m_pNumLabel= new QLabel("0",this);
    m_pNumLabel->resize(800,50);
    m_pNumLabel->setWordWrap(true);
    Language::MySet(m_pNumLabel, HELLO_TEST1);

    QLabel *m_pNumLabel2= new QLabel("0",this);
    m_pNumLabel2->resize(800,50);
    m_pNumLabel2->setWordWrap(true);
    Language::MySet(m_pNumLabel2, HELLO_TEST2);

    m_pNumLabel3= new QLabel("0",this);
    m_pNumLabel3->resize(800,50);
    m_pNumLabel3->setWordWrap(true);
    Language::MySet(m_pNumLabel3, HELLO_TEST2);

    m_pLangugeLabel= new QLabel("0",this);
    m_pLangugeLabel->resize(800,50);
    m_pLangugeLabel->setWordWrap(true);
    Language::MySet(m_pLangugeLabel, HELLO_TEST3);

    m_pZhBtn = new QPushButton(this);
    m_pZhBtn->resize(100, 100);
    Language::MySet(m_pZhBtn, HELLO_TEST2);

    m_pEngBtn = new QPushButton(this);
    m_pEngBtn->resize(100, 100);
    Language::MySet(m_pEngBtn, HELLO_TEST2);

    m_MainBoxLayout->addWidget(m_pNumLabel);
    m_MainBoxLayout->addWidget(m_pNumLabel2);
    m_MainBoxLayout->addWidget(m_pNumLabel3);
    m_MainBoxLayout->addWidget(m_pLangugeLabel);
    m_MainBoxLayout->addWidget(m_pZhBtn);
    m_MainBoxLayout->addWidget(m_pEngBtn);
    setLayout(m_MainBoxLayout);

}

#include "test1widget.h"
#include "Language/language.h"
#include <QTranslator>

test1widget::test1widget(QWidget *parent)
    : QWidget{parent}
{

    this->setMinimumSize(500,200);
    QVBoxLayout* m_MainBoxLayout = new QVBoxLayout();

    m_pNumLabel= new QLabel("0",this);
    m_pNumLabel->resize(800,50);
    m_pNumLabel->setWordWrap(true);
    Language::MySet(m_pNumLabel, HELLO_TEST1);

    m_pZhBtn = new QPushButton(this);
    m_pZhBtn->resize(100, 100);
    m_pZhBtn->setText("中文");

    m_pEngBtn = new QPushButton(this);
    m_pEngBtn->resize(100, 100);
    m_pEngBtn->setText("English");

    m_MainBoxLayout->addWidget(m_pNumLabel);
    m_MainBoxLayout->addWidget(m_pZhBtn);
    m_MainBoxLayout->addWidget(m_pEngBtn);
    setLayout(m_MainBoxLayout);
}


void test1widget::switchLanguage(const QString& languageCode)
{
    // QTranslator* translator = new QTranslator;

    // // 加载QM文件
    // if (translator->load(":/translations/" + languageCode + ".qm")) {
    //     // 移除旧的翻译器
    //     qApp->removeTranslator(m_currentTranslator);
    //     // 安装新的翻译器
    //     qApp->installTranslator(translator);
    //     m_currentTranslator = translator;
    //     qDebug() << "Language switched to:" << languageCode;
    // } else {
    //     qWarning() << "Failed to load translation:" << languageCode;
    //     delete translator;
    // }
}

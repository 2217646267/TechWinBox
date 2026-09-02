#include "test1widget.h"
#include "Language/language.h"

#include <QDebug>
#include <QApplication>
#include "Language/language.h"
#include <QMap>

test1widget::test1widget(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumSize(500,200);
    QVBoxLayout* m_MainBoxLayout = new QVBoxLayout();

    m_pNumLabel= new QLabel("0",this);
    m_pNumLabel->resize(800,50);
    m_pNumLabel->setWordWrap(true);
    Language::MySet(m_pNumLabel, HELLO_TEST7);

    QLabel *m_pNumLabel2= new QLabel("0",this);
    m_pNumLabel2->resize(800,50);
    m_pNumLabel2->setWordWrap(true);
    Language::MySet(m_pNumLabel2, HELLO_TEST6);

    QLabel *m_pNumLabel44= new QLabel("0",this);
    m_pNumLabel44->resize(800,50);
    m_pNumLabel44->setWordWrap(true);
    Language::MySet(m_pNumLabel44, HELLO_TEST4);

    m_pNumLabel3= new QLabel("0",this);
    m_pNumLabel3->resize(800,50);
    m_pNumLabel3->setWordWrap(true);
    //Language::MySet(m_pNumLabel3, HELLO_TEST2);

    m_pLangugeLabel= new QLabel("0",this);
    m_pLangugeLabel->resize(800,50);
    m_pLangugeLabel->setWordWrap(true);

    // m_pZhBtn = new QPushButton(this);
    // m_pZhBtn->resize(100, 100);
    // m_pZhBtn->setText("中文");

    // m_pEngBtn = new QPushButton(this);
    // m_pEngBtn->resize(100, 100);
    // m_pEngBtn->setText("English");

    QPushButton* m_pWidgetBtn = new QPushButton(this);
    m_pWidgetBtn->resize(100, 100);
    m_pWidgetBtn->setText("test");

    m_MainBoxLayout->addWidget(m_pNumLabel);
    m_MainBoxLayout->addWidget(m_pNumLabel2);
    m_MainBoxLayout->addWidget(m_pNumLabel3);
    m_MainBoxLayout->addWidget(m_pNumLabel44);
    m_MainBoxLayout->addWidget(m_pLangugeLabel);
    m_MainBoxLayout->addWidget(m_pWidgetBtn);
    m_MainBoxLayout->addWidget(m_pZhBtn);
    m_MainBoxLayout->addWidget(m_pEngBtn);

    // 语言切换按钮组（38 种语言，6 列网格排列）
    QGroupBox* langBox = new QGroupBox(tr("语言切换 Language Switch"), this);
    QGridLayout* langGrid = new QGridLayout(langBox);
    setupLanguageButtons(langGrid);
    m_MainBoxLayout->addWidget(langBox);

    setLayout(m_MainBoxLayout);

    connect(m_pZhBtn, &QPushButton::clicked, this, [=](){
        qDebug() << "111";
        setLanguage("zh_CN");
    });
    connect(m_pEngBtn, &QPushButton::clicked, this, [=](){
        setLanguage("en_US");
    });
    connect(m_pWidgetBtn, &QPushButton::clicked, this, [=](){
        if(testwidget2==nullptr)
            testwidget2 = new test2widget();
        testwidget2->show();
    });
}

void test1widget::setLanguage(const QString& languageCode) {
    if (m_currentLang == languageCode) return;

    // 1. 卸载旧翻译
    qApp->removeTranslator(&m_translator);

    // 2. 加载新翻译文件
    QString path = QString("/home/liangtuqin/box/TechWinBox/translations/%1.qm").arg(languageCode);
    if (m_translator.load(path)) {
        qApp->installTranslator(&m_translator);
        m_currentLang = languageCode;

        qDebug() << "Language switched to:" << languageCode;
    } else {
        qWarning() << "Failed to load translation file:" << path;
    }
    Language::Update();
}

void test1widget::loadTranslation(QString languageCode)
{
    return;
    QString qmFilePath;
    // 创建翻译器
    QTranslator *translator;
    if (languageCode == "zh_CN") {
        qmFilePath = ":/translations/zh_CN.qm"; // 或者使用绝对路径
    } else if (languageCode == "en_US") {
        qmFilePath = ":/translations/en_US.qm"; // 或者使用绝对路径
    } else {
        qWarning() << "Unsupported language code:" << languageCode;
        return;
    }

    // 先卸载当前的翻译器
    if (qApp->removeTranslator(translator)) {
        qDebug() << "Removed current translator.";
    }

    // 加载新的翻译文件
    if (translator->load(qmFilePath)) {
        // 安装新的翻译器
        qApp->installTranslator(translator);
        qDebug() << "Translation loaded successfully:" << qmFilePath;
    } else {
        qWarning() << "Failed to load translation file:" << qmFilePath;
    }

    if (languageCode == "zh_CN") {
        qmFilePath = ":/translations/zh_CN.qm"; // 或者使用绝对路径
    } else if (languageCode == "en_US") {
        qmFilePath = ":/translations/en_US.qm"; // 或者使用绝对路径
    } else {
        qWarning() << "Unsupported language code:" << languageCode;
        return;
    }

    // 先卸载当前的翻译器
    if (qApp->removeTranslator(translator)) {
        qDebug() << "Removed current translator.";
    }
     m_pLangugeLabel->setText(qmFilePath);
    // 加载新的翻译文件
    if (translator->load(qmFilePath)) {
        // 安装新的翻译器
        qApp->installTranslator(translator);
        qDebug() << "Translation loaded successfully:" << qmFilePath;
    } else {
        qWarning() << "Failed to load translation file:" << qmFilePath;
    }

}

// 批量创建 38 种语言切换按钮（6 列网格排列）
void test1widget::setupLanguageButtons(QGridLayout* layout)
{
    // 语言代码 -> 按钮显示文本（用各语言原文显示，直观可辨）
    QList<QPair<QString, QString>> langs = {
        {"zh_CN", "中文(简)"},
        {"zh_TW", "中文(繁)"},
        {"en_US", "English"},
        {"fr_FR", "Français"},
        {"de_DE", "Deutsch"},
        {"ja_JP", "日本語"},
        {"ko_KR", "한국어"},
        {"ru_RU", "Русский"},
        {"es_ES", "Español"},
        {"it_IT", "Italiano"},
        {"pt_PT", "Português"},
        {"pt_BR", "Português(BR)"},
        {"ar_SA", "العربية"},
        {"he_IL", "עברית"},
        {"hi_IN", "हिन्दी"},
        {"th_TH", "ไทย"},
        {"vi_VN", "Tiếng Việt"},
        {"id_ID", "Bahasa Indonesia"},
        {"ms_MY", "Bahasa Melayu"},
        {"tr_TR", "Türkçe"},
        {"pl_PL", "Polski"},
        {"cs_CZ", "Čeština"},
        {"hu_HU", "Magyar"},
        {"ro_RO", "Română"},
        {"nl_NL", "Nederlands"},
        {"da_DK", "Dansk"},
        {"fi_FI", "Suomi"},
        {"sv_SE", "Svenska"},
        {"nb_NO", "Norsk"},
        {"hr_HR", "Hrvatski"},
        {"el_GR", "Ελληνικά"},
        {"uk_UA", "Українська"},
        {"bg_BG", "Български"},
        {"sk_SK", "Slovenčina"},
        {"sl_SI", "Slovenščina"},
        {"et_EE", "Eesti"},
        {"lv_LV", "Latviešu"},
        {"lt_LT", "Lietuvių"}
    };

    const int cols = 6;
    int row = 0, col = 0;
    for (const auto& lang : langs) {
        QPushButton* btn = new QPushButton(lang.second, this);
        btn->setMinimumSize(120, 30);
        btn->setCursor(Qt::PointingHandCursor);
        layout->addWidget(btn, row, col);
        m_langBtnMap.insert(btn, lang.first);
        connect(btn, &QPushButton::clicked, this, [this, btn](){
            setLanguage(m_langBtnMap.value(btn));
        });

        col++;
        if (col >= cols) { col = 0; row++; }
    }
}

test1widget::~test1widget()
{
    Language::RemoveObj(m_pNumLabel3);
    delete testwidget2;
}


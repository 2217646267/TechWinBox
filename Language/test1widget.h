#ifndef TEST1WIDGET_H
#define TEST1WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QMap>
#include <QTranslator>
#include "test2widget.h"

class test1widget : public QWidget
{
    Q_OBJECT
public:
    explicit test1widget(QWidget *parent = nullptr);    
private:
    QPushButton* m_pZhBtn = nullptr;
    QPushButton* m_pEngBtn = nullptr;
    QLabel* m_pNumLabel = nullptr;
    QLabel* m_pLangugeLabel = nullptr;
    QLabel *m_pNumLabel3 = nullptr;
    QMap<QPushButton*, QString> m_langBtnMap;   // 语言切换按钮 -> 语言代码
    void setLanguage(const QString& languageCode);
    void loadTranslation(QString str);
    void setupLanguageButtons(QGridLayout* layout);   // 批量创建语言按钮
    QTranslator m_translator;
    QString m_currentLang;
    test2widget * testwidget2 = nullptr;
    ~test1widget();
signals:
};

#endif // TEST1WIDGET_H

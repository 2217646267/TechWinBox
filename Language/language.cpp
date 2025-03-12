#include "language.h"
#include <QDebug>

QMap<int,QString> Language::m_EnumMap;
QMap<QLabel*, LANGUAGE_NUM> Language::m_pLabelMap;
QMap<QPushButton*,LANGUAGE_NUM> Language::m_pBtnMap;

void Language::InitLanguage()
{
    m_EnumMap.insert(HELLO_TEST1,tr("Hello_111"));
    m_EnumMap.insert(HELLO_TEST2,tr("Hello_222"));
    qDebug() <<"MyTr" <<tr("Hello_111");
    qDebug() <<"MyTr"  <<tr("Hello_222");
}

void Language::MySet(QObject *obj, LANGUAGE_NUM NumText)
{
    qDebug()  << "类型" << obj->metaObject()->className();
    if (obj->metaObject()->className() == QLatin1String("QLabel")) {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if (label && m_EnumMap.contains(NumText)) {
            label->setText(m_EnumMap.value(NumText));  // 调用 QLabel 的接口
           /* if(m_EnumMap.value(NumText).contains("Hello"))
            {
                QString str = m_EnumMap.value(NumText);
                str.replace("Hello", "hi");
                label->setText(str);
            }else
            {
                label->setText(m_EnumMap.value(NumText));  // 调用 QLabel 的接口
            }*/

            m_pLabelMap.insert(label,NumText);
        } else {
            qDebug() << "转换失败，对象不是 QLabel";
        }
    }

    if (obj->metaObject()->className() == QLatin1String("QPushButton")) {
        QPushButton* btn = qobject_cast<QPushButton*>(obj);
        if (btn && m_EnumMap.contains(NumText)) {
            btn->setText(m_EnumMap.value(NumText));  // 调用 QLabel 的接口
            m_pBtnMap.insert(btn,NumText);
        } else {
            qDebug() << "转换失败，对象不是 QPushButton";
        }
    }
}

void Language::Update()
{
    InitLanguage();
    for (auto it = m_pLabelMap.begin(); it != m_pLabelMap.end(); ++it) {
        QLabel* label = it.key();
        LANGUAGE_NUM num = it.value();
        MySet(label, num);
    }
    for (auto it = m_pBtnMap.begin(); it != m_pBtnMap.end(); ++it) {
        QPushButton* btn = it.key();
        LANGUAGE_NUM num = it.value();
        MySet(btn, num);
    }
}

void Language::RemoveObj(QObject *obj)
{
    if (obj->metaObject()->className() == QLatin1String("QLabel")) {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if(label != nullptr && m_pLabelMap.contains(label))
        {
            delete label;
            delete obj;
        }
    }
}


#include "language.h"
#include <QDebug>

QMap<int,QString> Language::m_EnumMap;
QMap<QString, QLabel*> Language::m_pLabelMap;
QMap<QString, QPushButton*> Language::m_pBtnMap;

Language::Language(QObject *parent)
    : QObject{parent}
{

}


void Language::InitLanguage()
{
    m_EnumMap.insert(HELLO_TEST1,tr("Hello_111"));
    m_EnumMap.insert(HELLO_TEST2,tr("Hello_222"));
}

void Language::MySet(QObject *obj, LANGUAGE_NUM NumText)
{
    //InitLanguage();
    m_EnumMap.insert(HELLO_TEST1,"Hello_111");
    m_EnumMap.insert(HELLO_TEST2,"Hello_222");
    qDebug()  << "类型" << obj->metaObject()->className();
    if (obj->metaObject()->className() == QLatin1String("QLabel")) {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if (label && m_EnumMap.contains(NumText)) {
            label->setText(m_EnumMap.value(NumText));  // 调用 QLabel 的接口
            m_pLabelMap.insert(label->objectName(),label);
        } else {
            qDebug() << "转换失败，对象不是 QLabel";
        }
    }

    if (obj->metaObject()->className() == QLatin1String("QPushButton")) {
        QPushButton* btn = qobject_cast<QPushButton*>(obj);
        if (btn) {
            if(m_EnumMap.contains(NumText))
            {
                btn->setText(m_EnumMap.value(NumText));  // 调用 QLabel 的接口
            }

        } else {
            qDebug() << "转换失败，对象不是 QLabel";
        }
    }
}

void Language::RemoveObj(QObject *obj)
{
    if (obj->metaObject()->className() == QLatin1String("QLabel")) {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if(label != nullptr && m_pLabelMap.contains(obj->objectName()))
        {
            delete label;
            delete obj;
        }
    }
}


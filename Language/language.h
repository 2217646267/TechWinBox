#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QObject>
#include <QMap>
#include <QLabel>
#include <QPushButton>

enum LANGUAGE_NUM
{
    HELLO_TEST1 = 0,
    HELLO_TEST2,
};
class Language : public QObject
{
    Q_OBJECT
public:
    static void MySet(QObject* obj,LANGUAGE_NUM NumText);
    static void RemoveObj(QObject* obj);
    static void Update();
private:
    static QMap<int,QString> m_EnumMap;
    static void InitLanguage();
    static QMap<QLabel*, LANGUAGE_NUM> m_pLabelMap;
    static QMap<QPushButton*,LANGUAGE_NUM> m_pBtnMap;

signals:
};

#endif // LANGUAGE_H

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
    explicit Language(QObject *parent = nullptr);
    static void MySet(QObject* obj,LANGUAGE_NUM NumText);
    void RemoveObj(QObject* obj);

private:
    static QMap<int,QString> m_EnumMap;

    static QMap<QString, QLabel*> m_pLabelMap;
    static QMap<QString, QPushButton*> m_pBtnMap;
    void InitLanguage();
signals:
};

#endif // LANGUAGE_H

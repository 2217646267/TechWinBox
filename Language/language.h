#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QObject>

class Language : public QObject
{
    Q_OBJECT
public:
    explicit Language(QObject *parent = nullptr);

signals:
};

#endif // LANGUAGE_H

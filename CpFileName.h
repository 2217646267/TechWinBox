#ifndef CPFILENAME_H
#define CPFILENAME_H

#include <QWidget>
#include <QBoxLayout>
#include <QList>
#include "DragDropLabel.h"
#include <QDropEvent>
#include <QMimeData>


class CpFileName : public QWidget
{
    Q_OBJECT
public:
    explicit CpFileName(QWidget *parent = nullptr);
private:
    void init();
    void connect();
    DragDropLabel* m_pLeftWidget;
    DragDropLabel* m_pRightWidget;
    QList<QUrl> OldurlList;
     QList<QUrl> m_NewurlList;
    QMap<QString, QString> m_MapOldNewName;
signals:

public slots:
     void New(QDropEvent *event);
    void Old(QDropEvent *event);
};

#endif // CPFILENAME_H

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

     QList<QUrl> m_urlList;
signals:

public slots:
     void test1(QDropEvent *event);
};

#endif // CPFILENAME_H

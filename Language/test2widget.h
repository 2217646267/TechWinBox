#ifndef TEST2WIDGET_H
#define TEST2WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>

class test2widget : public QWidget
{
    Q_OBJECT
public:
    explicit test2widget(QWidget *parent = nullptr);
private:
    QPushButton* m_pZhBtn = nullptr;
    QPushButton* m_pEngBtn = nullptr;
    QLabel* m_pNumLabel = nullptr;
    QLabel* m_pLangugeLabel = nullptr;
    QLabel *m_pNumLabel3 = nullptr;
signals:
};

#endif // TEST2WIDGET_H

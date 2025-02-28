#ifndef TEST1WIDGET_H
#define TEST1WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
class test1widget : public QWidget
{
    Q_OBJECT
public:
    explicit test1widget(QWidget *parent = nullptr);    
private:
    QPushButton* m_pZhBtn = nullptr;
    QPushButton* m_pEngBtn = nullptr;
    QLabel* m_pNumLabel = nullptr;
    void switchLanguage(const QString& languageCode);
signals:
};

#endif // TEST1WIDGET_H

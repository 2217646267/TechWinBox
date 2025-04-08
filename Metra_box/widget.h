#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "serialport.h"
#include <QRadioButton>
#include <QMap>
#include <QButtonGroup>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    SerialPort* port = nullptr;
    std::vector<std::pair<int, int>> find_hex_pairs(int decimal_value) ;
    void SendData(QString strdata);
    void init();
    void initConnect();
    void initGaugeConnect();
    void initVechicleConnect();
    QMap<QRadioButton*,int> m_vechMap;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;
};
#endif // WIDGET_H

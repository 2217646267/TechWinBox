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
private:
    Ui::Widget *ui;
    SerialPort* port = nullptr;
    std::vector<std::pair<int, int>> find_hex_pairs(int decimal_value) ;
    void SendData(QString strdata);
    void init();
    void initConnect();
    void initGaugeConnect();
    void initVechicleConnect();
    void initPaikingConnect();
    void initParkingAssistConnect();
    void initSwCButtonConnect();
    void initInfoWidget();
    void onButtonClicked(QAbstractButton *button);
    QMap<QRadioButton*,int> m_vechMap;

};
#endif // WIDGET_H

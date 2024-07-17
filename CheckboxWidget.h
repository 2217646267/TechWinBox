
#pragma once

#include <QWidget>
#include <QBoxLayout>
#include <QCheckBox>
#include <QMap>

class CheckboxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckboxWidget(QWidget *parent = nullptr);
    void InstallCheckbox(QVector<QString> vet);
    QString GetCurrentBox();
signals:
private:
    QHBoxLayout *m_checkBoxLayout;
    QMap<QString, QCheckBox*>m_MapCheckbox;
    void ClickedItem(int state);
    void ClickedParentBox(bool checked);
    int m_number = 0;
    QString m_strCurentBox;
    QCheckBox* m_pPaterBox;
};


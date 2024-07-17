#include "CheckboxWidget.h"
#include <QCheckBox>
#include <QDebug>

CheckboxWidget::CheckboxWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(1000,40);
    m_checkBoxLayout = new QHBoxLayout();

    setLayout(m_checkBoxLayout);


    // connect(value, &QCheckBox::stateChanged, this, [this, value](int state)
    //         {
    //             qDebug() << value->text();
    //             state == Qt::Checked ? m_number++ : m_number--;

    //             if (m_number == m_VctCheckbox.size())
    //             {
    //                 m_pPaterBox->setCheckState(Qt::Checked);
    //             }
    //             else if (m_number == 0)
    //             {
    //                 m_pPaterBox->setCheckState(Qt::Unchecked);
    //             }
    //             else
    //             {
    //                 m_pPaterBox->setCheckState(Qt::PartiallyChecked);
    //             }
    //         });

    // connect(m_pPaterBox, &QCheckBox::clicked, this, [this, value](bool checked)
    //         {
    //             checked == 0 ? value->setCheckState(Qt::Unchecked) : value->setCheckState(Qt::Checked);
    //         });
}

void CheckboxWidget::InstallCheckbox(QVector<QString> vet)
{
    m_pPaterBox =  new QCheckBox(this);
    m_pPaterBox->setText(QString::fromLocal8Bit("文件"));
    m_pPaterBox->resize(120,50);
    connect(m_pPaterBox, &QCheckBox::clicked, this,&CheckboxWidget::ClickedParentBox);
     m_checkBoxLayout->addWidget(m_pPaterBox);
    for(auto  val: vet)
    {
        QCheckBox* pCheckBox = new QCheckBox(this);
        pCheckBox->setText(val);
        pCheckBox->resize(120,50);
        m_MapCheckbox.insert(pCheckBox->text(),pCheckBox);
        m_checkBoxLayout->addWidget(pCheckBox);
        connect(pCheckBox, &QCheckBox::stateChanged, this, &CheckboxWidget::ClickedItem);
    }

}

QString CheckboxWidget::GetCurrentBox()
{
    return m_strCurentBox;
}

void CheckboxWidget::ClickedItem(int state)
{
     state == Qt::Checked ? m_number++ : m_number--;

    QCheckBox *Checkbox = qobject_cast<QCheckBox*>(sender());
     m_strCurentBox = Checkbox->text();

        if (state == 2)
        {
             m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::Checked);
        }
        else if (m_number == 0)
        {
            m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::Unchecked);
        }
        if(m_number == m_MapCheckbox.size())
        {
            m_pPaterBox->setCheckState(Qt::Checked);
        }
        else if(m_number == 0)
        {
            m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::Unchecked);
        }
        else
        {
            m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::PartiallyChecked);
        }

}

void CheckboxWidget::ClickedParentBox(bool checked)
{
    for(auto value : m_MapCheckbox)
    {
      checked == 0 ? value->setCheckState(Qt::Unchecked) : value->setCheckState(Qt::Checked);
    }
}

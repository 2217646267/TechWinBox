#include "CheckboxWidget.h"
#include <QCheckBox>
#include <QDebug>

CheckboxWidget::CheckboxWidget(QWidget *parent)
    : QWidget{parent}
{
    m_checkBoxLayout = new QHBoxLayout();

    setLayout(m_checkBoxLayout);
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

void CheckboxWidget::clearLayout()
{
    // 遍历布局中的所有项
    while (QLayoutItem *item = m_checkBoxLayout->takeAt(0)) {
        // 如果是一个小部件，移除并销毁它
        if (QWidget *widget = item->widget()) {
            widget->setParent(nullptr);  // 断开与布局的连接
            widget->deleteLater();       // 延迟删除以防止立即销毁
        }
        // 删除布局项
        delete item;
    }
}

QString CheckboxWidget::GetCurrentBox()
{
    return m_strCurentBox;
}

void CheckboxWidget::ClickedItem(int state)
{
    QCheckBox *Checkbox = qobject_cast<QCheckBox*>(sender());
    m_strCurentBox = Checkbox->text();

    state == Qt::Checked ? m_number++ : m_number--;
    state == 2 ? m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::Checked) :
                 m_MapCheckbox.value(m_strCurentBox)->setCheckState(Qt::Unchecked);

    if(m_number == m_MapCheckbox.size())
    {
        m_pPaterBox->setCheckState(Qt::Checked);
    }
    else if(m_number == 0)
    {
        m_pPaterBox->setCheckState(Qt::Unchecked);
    }
    else
    {
        m_pPaterBox->setCheckState(Qt::PartiallyChecked);
    }

}

void CheckboxWidget::ClickedParentBox(bool checked)
{
    for(auto value : m_MapCheckbox)
    {
      checked == 0 ? value->setCheckState(Qt::Unchecked) : value->setCheckState(Qt::Checked);
    }
}

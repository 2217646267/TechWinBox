#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QVector>
#include <QDir>
#include <QCheckBox>
#include "CheckboxWidget.h"

class QrcFeatureWidget : public QWidget
{
    Q_OBJECT

public:
    QrcFeatureWidget(QWidget *parent = Q_NULLPTR);
    ~QrcFeatureWidget();
private:
    void init();
    void initConnect();
private:
    QPushButton* m_pBtn = nullptr;
    QPushButton* m_pOkBtn = nullptr;
    QLabel* m_pFileLabel = nullptr;
    QLabel* m_pNumLabel = nullptr;

    void openFileDialog();
    void WriteQRCFile(const QString& strQRCFilePath);
    void listAllFilesAndFolders(const QDir& directory, QStringList& fileList);

    //存放处理的路径文件
    QVector<QString> m_VecProFileDir;
    //加载Pro文件
    void LoadProPathFile(const QString& strProFilePath);

    //资源工程pro文件
    QString m_strProFilePath;
    //子类节点容器
    QVector<QCheckBox*> m_VctCheckbox;
    //父类节点
    QCheckBox* m_pPaterBox = nullptr;
    int m_number = 0;
    CheckboxWidget* m_CheckboxWidget = nullptr;

    void slotOpenFile();
    void slotOk();
};

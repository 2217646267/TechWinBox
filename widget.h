#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QVector>
#include <QDir>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
private:
    QPushButton* m_pBtn = nullptr;
    QLabel* m_pFileLabel = nullptr;

    void openFileDialog();
    //
    void ReadImgProFile();
    void WriteQRCFile(const QString& strQRCFilePath,
        const QVector<QMap<QString, QString>>& VecPathInfo,
        const QVector<QMap<QString, QString>>& VecImgInfo);
    void WriteQRCFile(const QString& strQRCFilePath);
    bool bFileStart = false;
    bool bFileEnd = false;
    void listAllFilesAndFolders(const QDir& directory, QStringList& fileList);

    QVector<QMap<QString, QString>> m_VecPathInfo;
    QVector<QString> m_VecImgInfo;

    QVector<QString> m_VecQrcName;


    //存放处理的路劲文件
    QVector<QString> m_VecProFileDir;
    void LoadProPathFile(const QString& strRootPath);

    bool bFileContainsQrc(const QString& strFilePath);
    QString m_strProjectFilePath;

    QString m_strCurrentOperationPath = "";

    QMap<QString, QString> m_MapFileAndName;
};
#endif // WIDGET_H

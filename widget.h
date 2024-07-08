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
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QPushButton * m_pBtn = nullptr;
    QLabel* m_pFileLabel = nullptr;
    QString m_strFilePath = "";
    void openFileDialog();
    //
    void ReadQRCFile(const QString &strSource,const QString &strSourceCp);
    void WriteQRCFile(const QString &strQRCFilePath,
                      const QVector<QMap<QString,QString>> &VecPathInfo,
                      const QVector<QMap<QString,QString>> &VecImgInfo);
    void WriteQRCFile(const QString &strQRCFilePath);
    bool bFileStart = false;
    bool bFileEnd = false;
    void listAllFilesAndFolders(const QDir& directory, QStringList& fileList);

    QVector<QMap<QString,QString>> m_VecPathInfo;
    QVector<QString> m_VecImgInfo;

    QVector<QString> m_VecQrcName;
};
#endif // WIDGET_H

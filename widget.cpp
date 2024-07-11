#include "widget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    m_pBtn = new QPushButton(this);
    m_pBtn->setGeometry(50, 50, 100, 100);
    m_pBtn->setText("ProFile");
    m_pFileLabel = new QLabel("No file selected", this);
    m_pFileLabel->resize(800, 50);
    //  openFileDialog();

    connect(m_pBtn, &QPushButton::clicked, this, [this]()
        {
            openFileDialog();
            LoadProPathFile(m_strProjectFilePath);
            QFileInfo fileInfo(m_strProjectFilePath);
            QString strQrcFileName = fileInfo.absolutePath() +
             QString("/%1/%2.qrc").arg(m_VecProFileDir[0]).arg(m_VecProFileDir[0]);
            WriteQRCFile(strQrcFileName);

        });
}

void Widget::openFileDialog()
{
    // m_strProjectFilePath =QFileDialog::getExistingDirectory(this, "Select Folder", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_strProjectFilePath = QFileDialog::getOpenFileName(this,
        "Select File",
        "",
        "Text Files (*.pro)");
    if (!m_strProjectFilePath.isEmpty())
    {
        m_pFileLabel->setText(m_strProjectFilePath);
    }
    else
    {
        m_pFileLabel->setText("No file selected");
    }
}

void Widget::ReadImgProFile()
{
    //    QFile file("");
    //    QDir directory(strQRCFilePath);
    //    QStringList fileList = directory.entryList(QDir::Files);
    //    qDebug() <<fileList;
    //    return;
    //    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //        qDebug() << "Failed to open file:" << file.errorString();
    //        return;
    //    }
    //    // 获取当前目录中的所有子目录
    //    QStringList dirs = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    //    foreach (QString dir, dirs) {
    //        QDir subDir = directory;
    //        subDir.cd(dir);
    //    //    listAllFilesAndFolders(subDir, fileList);
    //    }

}

void Widget::listAllFilesAndFolders(const QDir& directory, QStringList& fileList) {
    // 获取当前目录中的所有文件
    QStringList files = directory.entryList(QDir::Files);
    foreach(QString file, files) {
        fileList << directory.absoluteFilePath(file);
        qDebug() << file;
        //strPath = file;
    }

    // 获取当前目录中的所有子目录
    QStringList dirs = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QString dir, dirs) {
        QDir subDir = directory;
        subDir.cd(dir);
        listAllFilesAndFolders(subDir, fileList);
    }
}

void Widget::LoadProPathFile(const QString& strRootPath)
{
    QFile file(strRootPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    // 使用 QTextStream 读取文件内容
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(line.contains("SUBDIRS += "))
        {
            line.remove("SUBDIRS += ");
            m_VecProFileDir.append(line);
        }
    }

}

bool Widget::bFileContainsQrc(const QString& strQRCFilePath)
{
    QDir directory(strQRCFilePath);

  // 获取当前目录中的所有文件
    QStringList files = directory.entryList(QDir::Files);
    foreach(QString file, files) {
        if (file.contains(".qrc"))
        {
            return true;
        }
        return false;
    }

}

void Widget::WriteQRCFile(const QString& strQRCFilePath)
{
     QFileInfo fileInfo(strQRCFilePath);

      QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QDir directory(fileInfo.absolutePath());
    // 创建文本流
    QTextStream out(&file);
    out.setCodec("UTF-8");

    QStringList fileList = directory.entryList(QDir::Files);
    qDebug() <<fileList;

    //文件
    out << "<RCC>" << "\n";
    QString strqresource = "/";
    QString strWrte = QString("    <qresource prefix = \"%1\">").arg(strqresource);
    out << strWrte <<"\n";

    QStringList files;
    listAllFilesAndFolders(directory, files);
    foreach(QString file, files) {
        if(file.contains("png") || file.contains("gif"))
        {

            QString strWirte = file.remove(0,fileInfo.absolutePath().length());
           qDebug() << strWirte;
            out <<"\t<file>" <<strWirte << "</file>" << "\n";
        }

    }

     out << "    </qresource>" << "\n";
    //文件结束
    out << "</RCC>" << "\n";
    file.close();

}

Widget::~Widget() {}

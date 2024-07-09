#include "QtWidgetsApplication8.h"
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
            //  openFileDialog();
             //QString sor = "~/Qt_Project/demo/Demo_3/untitled111/img.qrc";

             //QString sorcp = "~/Qt_Project/demo/Demo_3/untitled111/imgCp.qrc";
              // 获取用户主目录路径
            QString homePath = QDir::homePath();
            QString sor = homePath + "/img.qrc";
            QString sorcp = homePath + "/imgCp.qrc";


            openFileDialog();
            LoadProPathFile(m_strProjectFilePath);
            m_strCurrentOperationPath = m_strProjectFilePath + "/../aa";
            WriteQRCFile(m_strCurrentOperationPath);

        });
}

void Widget::openFileDialog()
{
    // m_strProjectFilePath =QFileDialog::getExistingDirectory(this, "Select Folder", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    m_strProjectFilePath = QFileDialog::getOpenFileName(this,
        "Select File",
        "",
        "All Files (*);;Text Files (*.txt)");
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
        m_VecProFileDir.append(line);
        qDebug() << "Line read:" << line;
        // 在这里可以对每行数据进行处理
    }

}

bool Widget::bFileContainsQrc(const QString& strQRCFilePath)
{
    QDir directory(strQRCFilePath);
    // (QDir::Dirs | QDir::NoDotAndDotDot);
    //(QDir::Files);

  // 获取当前目录中的所有文件
    QStringList files = directory.entryList(QDir::Files);
    foreach(QString file, files) {
        if (file.contains(".qrc"))
        {
            return true;
            // QString str33 = file.section('/', -1, -1);
            // m_VecQrcName.append(file.section('/', -1, -1));
           //  qDebug() <<str33;
        }
        return false;
    }

}

void Widget::WriteQRCFile(const QString& strQRCFilePath)
{
    //判断是否存在qrc文件
    if (!bFileContainsQrc(strQRCFilePath))
    {
        return;
    }


    QFile file("F:/img/aa/111.qrc");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QStringList strlist;
    QDir directory(strQRCFilePath);
    // 创建文本流
    QTextStream out(&file);
    out.setCodec("UTF-8");

    QStringList fileList = directory.entryList(QDir::Files);
    qDebug() <<fileList;

    //文件
    const QString& strQccHend = "<RCC>";
    out << strQccHend << "\n";

    QStringList files;
    listAllFilesAndFolders(directory, files);
    foreach(QString file, files) {
        out <<"<file>" << file << "</file>" << "\n";
    }


    //文件结束
    const QString& strQccTail = "</RCC>";
    out << strQccTail << "\n";
    file.close();

}

Widget::~Widget() {}

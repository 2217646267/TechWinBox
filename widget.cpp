#include "widget.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pBtn = new QPushButton(this);
    m_pBtn->setGeometry(50,50,100,100);
    m_pBtn->setText("ProFile");
    m_pFileLabel = new QLabel("No file selected", this);
    m_pFileLabel->resize(800, 50);
    openFileDialog();

    connect(m_pBtn, &QPushButton::clicked, this,[this]()
    {
      //  openFileDialog();
       //QString sor = "~/Qt_Project/demo/Demo_3/untitled111/img.qrc";

       //QString sorcp = "~/Qt_Project/demo/Demo_3/untitled111/imgCp.qrc";
        // 获取用户主目录路径
        QString homePath = QDir::homePath();
        QString sor = homePath + "/img.qrc";
        QString sorcp =homePath + "/imgCp.qrc";
        openFileDialog();
         //WriteQRCFile(m_strFilePath);
        QStringList fileList;
         listAllFilesAndFolders(m_strFilePath,fileList);
        foreach (QString file, fileList) {
          //  qDebug() << file;
            if(file.contains(".qrc"))
           {
              QString str33 = file.section('/', -1, -1);
              m_VecQrcName.append(file.section('/', -1, -1));
              qDebug() <<str33;
            }

        }
    });
}

void Widget::openFileDialog()
{
    m_strFilePath =QFileDialog::getExistingDirectory(this, "Select Folder", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!m_strFilePath.isEmpty())
    {
        m_pFileLabel->setText(m_strFilePath);


    }
    else
    {
        m_pFileLabel->setText("No file selected");
    }


}

void Widget::listAllFilesAndFolders(const QDir& directory, QStringList& fileList) {
    // 获取当前目录中的所有文件
    QStringList files = directory.entryList(QDir::Files);
    foreach (QString file, files) {
        fileList << directory.absoluteFilePath(file);
    }

    // 获取当前目录中的所有子目录
    QStringList dirs = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach (QString dir, dirs) {
        QDir subDir = directory;
        subDir.cd(dir);
        listAllFilesAndFolders(subDir, fileList);
    }
}

void Widget::WriteQRCFile(const QString &strQRCFilePath)
{
    QFile file(strQRCFilePath);
    QDir directory(strQRCFilePath);
    QStringList fileList = directory.entryList(QDir::Files);
    qDebug() <<fileList;
    return;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    // 创建文本流
    QTextStream out(&file);

    out.setCodec("UTF-8");
    //文件
    const QString & strQccHend = "<RCC>";
    //文件结束
    const QString & strQccTail = "</RCC>";
    out <<strQccHend;
    out <<"\n";
    for(auto val :m_VecPathInfo )
    {
        for (auto it = val.begin(); it != val.end(); ++it) {
            out << it.key() << "= " << it.value() << "\n";
        }
    }
    for(auto val :fileList )
    {
        for (auto it = val.begin(); it != val.end(); ++it) {
            out <<   "<file>" << val <<"</file>" << "\n";
        }
    }
    out <<strQccTail;
    out <<"\n";
    file.close();

}

Widget::~Widget() {}

#include "CpFileName.h"
#include <QDebug>

CpFileName::CpFileName(QWidget *parent) : QWidget(parent)
{
    init();
    connect();
}

void CpFileName::init()
{
    QHBoxLayout* MainLayout = new QHBoxLayout();
    m_pLeftWidget = new DragDropLabel(this);
    m_pLeftWidget->setStyleSheet("background-color: yellow;");
    m_pRightWidget = new DragDropLabel(this);
    m_pRightWidget->setStyleSheet("background-color: blue;");
    MainLayout->addWidget(m_pLeftWidget);
    MainLayout->addWidget(m_pRightWidget);
    this->setLayout(MainLayout);
    QObject::connect(m_pLeftWidget, &DragDropLabel::signaldropEvent, this, &CpFileName::test1);
}

void CpFileName::connect()
{

     QObject::connect(m_pRightWidget, &DragDropLabel::signaldropEvent, this, [this](QDropEvent *event)
    {
        const QMimeData *mimeData = event->mimeData();
        if (mimeData->hasUrls()) {
           QList<QUrl> urlList = mimeData->urls();
            qDebug()  << "old"<<urlList;
            for (int i = 0; i < urlList.size(); ++i) {
                    QString filePath = urlList.at(i).toLocalFile();
                    QFile file(filePath);
                       if (!file.exists()) {
                           qDebug() << "文件不存在：" << filePath;
                           return 1;
                       }

                       // 尝试重命名文件
                        QString newFileName = m_urlList.at(i).toLocalFile();
                         qDebug()  << "newFileName"<<newFileName;
                        if (file.rename(newFileName)) {
                                qDebug() << "文件重命名成功";
                            } else {
                                qDebug() << "文件重命名失败";
                                qDebug() << "错误代码：" << file.error();
                                qDebug() << "错误信息：" << file.errorString();
                            }

                        QFile newFile(newFileName);
                               if (newFile.exists() && newFile.remove()) {
                                   qDebug() << "删除已存在的目标文件：" << newFileName;
                                   // 重新尝试重命名
                                   if (file.rename(newFileName)) {
                                       qDebug() << "文件重命名成功";
                                   } else {
                                       qDebug() << "文件重命名仍然失败";
                                   }
                               }
               }
        }


    });
}

void CpFileName::test1(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()) {
       m_urlList = mimeData->urls();
         qDebug() << "new" << m_urlList;
//            if (m_urlList.length() > 0) {
//                QString filePath = m_urlList.at(0).toLocalFile();
//                this->setText("Dropped file:\n" + filePath); // 显示文件路径
//            }
    }
}

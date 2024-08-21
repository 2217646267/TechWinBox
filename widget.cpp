#include "widget.h"
#include "QrcFeatureWidget.h"
#include <QDebug>
#include "CpFileName.h"

bool renameAndMoveFile(const QString &oldFilePath, const QString &newFileName) {
    QFile file(oldFilePath);
    if (file.exists()) {
        // 获取旧文件的目录
        QDir dir = QFileInfo(oldFilePath).absoluteDir();
        // 生成新的文件路径
        QString newFilePath = dir.absoluteFilePath(newFileName);

        // 尝试重命名（包括路径的移动）
        if (file.rename(newFilePath)) {
            qDebug() << "File renamed and moved successfully.";
            return true;
        } else {
            qDebug() << "Failed to rename and move file.";
        }
    } else {
        qDebug() << "File does not exist.";
    }
    return false;
}

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    // QString oldFileName = "/home/liangtuqin/img.qrc";
    // QString newFileName = "img2.qrc";

    // renameAndMoveFile(oldFileName, newFileName);

    QrcFeatureWidget* widhte = new QrcFeatureWidget(this);
    widhte->resize(1000,600);
  // widhte->hide();
   // CpFileName* Cpwidhte = new CpFileName(this);
   // Cpwidhte->resize(1000,600);

}

Widget::~Widget() {}

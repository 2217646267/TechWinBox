#include "widget.h"

#include <QApplication>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建翻译器
    QTranslator translator;

    // 指定QM文件路径
    QString qmFilePath = ":/translations/zh_CN.qm"; // 假设QM文件在资源文件中
    qDebug() << "Resource path:" << qmFilePath;
    // 或者使用绝对路径：
    // QString qmFilePath = "C:/path/to/translations/zh_CN.qm";

    // 加载QM文件
    if (translator.load(qmFilePath)) {
        // 安装翻译器
        a.installTranslator(&translator);
        qDebug() << "Translation loaded successfully:" << qmFilePath;
    } else {
        qWarning() << "Failed to load translation file:" << qmFilePath;
    }

    Widget w;
    w.show();
    return a.exec();
}

#include "QrcFeatureWidget.h"
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

QrcFeatureWidget::QrcFeatureWidget(QWidget *parent)
	: QWidget(parent)
{
	init();
	initConnect();
}

void QrcFeatureWidget::init()
{
	m_pBtn = new QPushButton(this);
	m_pBtn->setGeometry(50, 50, 100, 100);
	m_pBtn->setText("ProFile");
	m_pFileLabel = new QLabel("No file selected", this);
	m_pFileLabel->resize(800, 50);
	m_pFileLabel->setWordWrap(true);
}


void QrcFeatureWidget::initConnect()
{
	connect(m_pBtn, &QPushButton::clicked, this, [this]()
		{
			openFileDialog();
			if (!m_strProFilePath.isEmpty())
			{
				LoadProPathFile(m_strProFilePath);
				QFileInfo fileInfo(m_strProFilePath);

				for (auto val : m_VecProFileDir)
				{
					if (!val.isEmpty())
					{
						QString strQrcFilePath = fileInfo.absolutePath() +
							QString("/%1/%2.qrc").arg(val).arg(val);
						WriteQRCFile(strQrcFilePath);
					}
				}
			}

		});
}

void QrcFeatureWidget::openFileDialog()
{
	m_strProFilePath = QFileDialog::getOpenFileName(this,
		"Select File",
		"",
		"Text Files (*.pro)");

	if (!m_strProFilePath.isEmpty())
	{
		m_pFileLabel->setText(m_strProFilePath);
	}
	else
	{
		m_pFileLabel->setText("No file selected");
	}
}

void QrcFeatureWidget::listAllFilesAndFolders(const QDir& directory, QStringList& fileList) {
	// 获取当前目录中的所有文件
	QStringList files = directory.entryList(QDir::Files);
	foreach(QString file, files) {
		fileList << directory.absoluteFilePath(file);
		qDebug() << file;
	}

	// 获取当前目录中的所有子目录
	QStringList dirs = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
	foreach(QString dir, dirs) {
		QDir subDir = directory;
		subDir.cd(dir);
		listAllFilesAndFolders(subDir, fileList);
	}
}

void QrcFeatureWidget::LoadProPathFile(const QString& strProFilePath)
{
	QFile file(strProFilePath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Failed to open file:" << file.errorString();
		return;
	}

	// 使用 QTextStream 读取文件内容
	QTextStream in(&file);
	m_VecProFileDir.clear();
	while (!in.atEnd()) {
		QString line = in.readLine();
		if (line.contains("SUBDIRS += "))
		{
			line.remove("SUBDIRS += ");
			m_VecProFileDir.append(line);
		}
	}

	for (auto val : m_VecProFileDir)
	{
		if (!val.isEmpty())
		{

		}
	}

}

void QrcFeatureWidget::WriteQRCFile(const QString& strQRCFilePath)
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
	qDebug() << fileList;

	//文件
	out << "<RCC>" << "\n";
	QString strqresource = "/";
	QString strWrte = QString("    <qresource prefix = \"%1\">").arg(strqresource);
	out << strWrte << "\n";

	QStringList files;
	listAllFilesAndFolders(directory, files);
	foreach(QString file, files) {
		if (file.contains("png") || file.contains("gif"))
		{

			QString strWirte = file.remove(0, fileInfo.absolutePath().length());
			qDebug() << strWirte;
			out << "\t<file>" << strWirte << "</file>" << "\n";
		}

	}

	out << "    </qresource>" << "\n";
	//文件结束
	out << "</RCC>" << "\n";
	file.close();

}

void QrcFeatureWidget::ReadImgProFile()
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


QrcFeatureWidget::~QrcFeatureWidget()
{
}

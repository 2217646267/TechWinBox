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

    m_pOkBtn = new QPushButton(this);
    m_pOkBtn->setGeometry(200, 50, 100, 100);
    m_pOkBtn->setText("ok");

	m_pFileLabel = new QLabel("No file selected", this);
	m_pFileLabel->resize(800, 50);
	m_pFileLabel->setWordWrap(true);

    m_CheckboxWidget = new CheckboxWidget(this);
    m_CheckboxWidget->hide();
    m_CheckboxWidget->move(0,400);
}

 void QrcFeatureWidget::slotsss()
{
     openFileDialog();
     LoadProPathFile(m_strProFilePath);
     m_CheckboxWidget->show();
     m_CheckboxWidget->InstallCheckbox(m_VecProFileDir);

     // if (!m_strProFilePath.isEmpty())
     // {

     //     QFileInfo fileInfo(m_strProFilePath);
     //     for (auto val : m_VecProFileDir)
     //     {
     //         if (!val.isEmpty())
     //         {
     //             QString strQrcFilePath = fileInfo.absolutePath() +
     //                                      QString("/%1/%2.qrc").arg(val).arg(val);
     //             WriteQRCFile(strQrcFilePath);
     //         }
     //     }

     // }

 }

  void QrcFeatureWidget::slotOk()
 {
      QString strBoxFile = m_CheckboxWidget->GetCurrentBox();
      if (!strBoxFile.isEmpty())
      {
          QFileInfo fileInfo(m_strProFilePath);
          QString strQrcFilePath = fileInfo.absolutePath() +
                                   QString("/%1/%2.qrc").arg(strBoxFile).arg(strBoxFile);
          WriteQRCFile(strQrcFilePath);
      }
  }
void QrcFeatureWidget::initConnect()
{
    connect(m_pBtn, &QPushButton::clicked, this,&QrcFeatureWidget::slotsss);
     connect(m_pOkBtn, &QPushButton::clicked, this,&QrcFeatureWidget::slotOk);

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

    /*for (auto val : m_VecProFileDir)
    {
        if (!val.isEmpty())
        {
            QCheckBox* pSonBox = new QCheckBox(this);
            pSonBox->setText(QString::fromLocal8Bit("%1").arg(val));
            m_VctCheckbox.append(pSonBox);
            connect(pSonBox, &QCheckBox::stateChanged, this, [this, pSonBox](int state)
                    {
                        state == Qt::Checked ? m_number++ : m_number--;

                        if (m_number == m_VctCheckbox.size())
                        {
                            m_pPaterBox->setCheckState(Qt::Checked);

                        }
                        else if (m_number == 0)
                        {
                            m_pPaterBox->setCheckState(Qt::Unchecked);
                        }
                        else
                        {
                            m_pPaterBox->setCheckState(Qt::PartiallyChecked);
                        }
                    });
        }
    }*/

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

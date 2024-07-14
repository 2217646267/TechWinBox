#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QVector>
#include <QDir>

class QrcFeatureWidget : public QWidget
{
	Q_OBJECT

public:
	QrcFeatureWidget(QWidget *parent = Q_NULLPTR);
	~QrcFeatureWidget();
private:
	void init();
	void initConnect();
private:
	QPushButton* m_pBtn = nullptr;
	QLabel* m_pFileLabel = nullptr;

	//暂时无用
	void ReadImgProFile();

	void openFileDialog();
	void WriteQRCFile(const QString& strQRCFilePath);
	void listAllFilesAndFolders(const QDir& directory, QStringList& fileList);

	//存放处理的路径文件
	QVector<QString> m_VecProFileDir;
	//加载Pro文件
	void LoadProPathFile(const QString& strProFilePath);

	//资源工程pro文件
	QString m_strProFilePath;
};

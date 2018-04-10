#pragma once

#include <QObject>

class Document : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString fileName READ fileName NOTIFY fileNameChanged)

public:
	enum DocumentType {
		HexagramType,		// ��س�����ĵ�
		AlgorithmType		// �㷨�ĵ�
	};
	Document(DocumentType type, const QString &fileName = QString(), QObject* parent = 0);
	DocumentType type() const { return mType; }
	QString fileName() const;

	virtual QString displayName() const = 0;
	virtual bool save(const QString &fileName, QString* error = 0) = 0;
	~Document();
signals:
	void fileNameChanged(const QString &fileName,
		const QString &oldFileName);

protected:
	DocumentType mType;
	QString mFileName;
};

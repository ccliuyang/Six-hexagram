#include "document.h"



Document::Document(DocumentType type, const QString &fileName,
	QObject *parent)
	: QObject(parent)
	, mType(type)
	, mFileName(fileName)
{
}

Document::~Document()
{
}

QString Document::fileName() const
{
	return mFileName;
}

#pragma once

#include <QObject>

class Editor : public QObject
{
	Q_OBJECT

public:
	Editor(QObject *parent);
	~Editor();
};

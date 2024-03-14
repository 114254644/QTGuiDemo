#pragma once

#include <QWidget>
#include "widget_base.h"
#include "ui_AppMain.h"

class CAppMain : public CWidgetBase
{
	Q_OBJECT

public:
	CAppMain(QWidget *parent = nullptr);
	~CAppMain();

private:
	Ui::CAppMainClass ui;
};

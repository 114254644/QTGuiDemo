#include "app_main.h"
#include "list_model.h"
#include "list_item_delegate.h"
CAppMain::CAppMain(QWidget *parent)
	: CWidgetBase(parent)
{
	ui.setupUi(this);
	addCaptionLayout(ui.caption_layout);
	addButtonLayout(ui.sys_btn_layout);
	setTitle(QString::fromUtf16((const ushort*)L"»ù´¡¿Ø¼þ»»Æ¤·ô"));
	auto closed__ = [this]()->void
	{
		close();
	};
	connect(this, &CWidgetBase::closed, this, closed__);
	ui.listView->setModel(new CListModel(ui.listView));
	ui.listView->setItemDelegate(new CListItemDelegate(ui.listView));
}

CAppMain::~CAppMain()
{

}

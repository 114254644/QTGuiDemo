#include "app_main.h"
#include "list_model.h"
#include "list_item_delegate.h"
#include <qtoolbutton.h>
CAppMain::CAppMain(QWidget *parent)
	: CWidgetBase(parent)
{
	ui.setupUi(this);
	addCaptionLayout(ui.caption_layout);
	addButtonLayout(ui.sys_btn_layout);
	setTitle(QString::fromUtf16((const ushort*)L"�����ؼ���Ƥ��"));
	auto closed__ = [this]()->void
	{
		close();
	};
	connect(this, &CWidgetBase::closed, this, closed__);
	ui.listView->setModel(new CListModel(ui.listView));
	ui.listView->setItemDelegate(new CListItemDelegate(ui.listView));
	if(m_btn_close != nullptr)
		m_btn_close->setToolTip(QString::fromUtf16((const ushort*)L"�ر�"));
	if (m_btn_max != nullptr)
		m_btn_max->setToolTip(QString::fromUtf16((const ushort*)L"���"));
	if (m_btn_restore != nullptr)
		m_btn_restore->setToolTip(QString::fromUtf16((const ushort*)L"��ԭ"));
	if (m_btn_min != nullptr)
		m_btn_min->setToolTip(QString::fromUtf16((const ushort*)L"��С��"));
}

CAppMain::~CAppMain()
{

}

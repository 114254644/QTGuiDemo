#include "widget_base.h"
#include <QStyleOption>
#include <QPainter>
#include <windowsx.h>
#include <windows.h>
#include <QLabel>
#include <QToolButton>
#include <QBoxLayout>
#include <qdebug.h>
#include <qguiapplication.h>
#include <QScreen>
CWidgetBase::CWidgetBase(QWidget* parent, WidgetFlags flags)
: QWidget(parent)
, m_flags(flags)
{
	setWindowFlags(Qt::FramelessWindowHint);
	m_lab_title = new QLabel(this);
	if (m_flags & WT_RoundMaskHint)
		setAttribute(Qt::WA_TranslucentBackground);
	
	if (m_flags & WT_MinButtonHint)
	{
		m_btn_min = new QToolButton(this);
		m_btn_min->setObjectName("btn_min");
		m_btn_min->setToolTip("btn_min");
		m_btn_min->hide();

		auto min__ = [this]()->void
		{
			showMinimized();
		};
		connect(m_btn_min, &QToolButton::clicked, this, min__);
	}

	if (m_flags & WT_CloseButtonHint)
	{
		m_btn_close = new QToolButton(this);
		m_btn_close->setObjectName("btn_close");
		m_btn_close->setToolTip("btn_close");
		m_btn_close->hide();
	
		connect(m_btn_close, SIGNAL(clicked()), this, SIGNAL(closed()));
	}

	if (m_flags & WT_MaxButtonHint)
	{
		m_btn_max = new QToolButton(this);
		m_btn_max->setObjectName("btn_max");
		m_btn_max->setToolTip("btn_max");
		m_btn_max->hide();

		auto max__ = [this]()->void
		{
			showMaximized();
			m_btn_max->hide();
			m_btn_restore->show();
		};
		connect(m_btn_max, &QToolButton::clicked, this, max__);
		m_btn_restore = new QToolButton(this);
		m_btn_restore->setObjectName("btn_restore");
		m_btn_restore->setToolTip("btn_restore");
		m_btn_restore->hide();

		auto restore__ = [this]()->void
		{
			showNormal();
			m_btn_restore->hide();
			m_btn_max->show();
		};
		connect(m_btn_restore, &QToolButton::clicked, this, restore__);
	}
}

CWidgetBase::~CWidgetBase()
{

}

//添加标题栏布局
void CWidgetBase::addCaptionLayout(QBoxLayout* layout)
{
	m_caption_layout = layout;
	if (m_lab_title != nullptr)
		layout->insertWidget(0,m_lab_title);
}

//添加系统按钮布局
void CWidgetBase::addButtonLayout(QBoxLayout* layout)
{
	if (nullptr == layout)
		return;

	m_btn_layout = layout;
	if (m_btn_min != nullptr)
	{
		layout->addWidget(m_btn_min);
		m_btn_min->show();
	}
		
	if (m_btn_max != nullptr)
	{
		layout->addWidget(m_btn_max);
		m_btn_max->show();
	}

	if (m_btn_restore != nullptr)
	{
		layout->addWidget(m_btn_restore);
	}

	if (m_btn_close != nullptr)
	{
		layout->addWidget(m_btn_close);
		m_btn_close->show();
	}
}

//设置标题
void CWidgetBase::setTitle(const QString& title)
{
	if (m_lab_title != nullptr)
		m_lab_title->setText(title);
}

void CWidgetBase::paintEvent(QPaintEvent* event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	paint(event);
}

bool CWidgetBase::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	MSG* pMsg = (MSG*)message;

	switch (pMsg->message)
	{
	case WM_NCHITTEST:
	{
		int x = GET_X_LPARAM(pMsg->lParam) - frameGeometry().x();
		int y = GET_Y_LPARAM(pMsg->lParam) - frameGeometry().y();

		if (m_caption_layout != nullptr)
		{
			if (m_caption_layout->geometry().contains(x, y))
			{
				*result = HTCAPTION;
				return true;
			}
		}

		if (m_flags & WT_BorderSizeHint)
		{
			if (m_btn_layout != nullptr && m_btn_layout->geometry().contains(x, y))
			{
				break;
			}

			if (windowState() & Qt::WindowMaximized)
			{
				break;
			}

			if (x < m_border && y >(height() - m_border) &&
				y < height())
				*result = HTBOTTOMLEFT;  //左下
			else if (x > (width() - m_border) && x < width() &&
				y >(height() - m_border) && y < height())
				*result = HTBOTTOMRIGHT;  //右下
			else if (x < m_border && y < m_border)
				*result = HTTOPLEFT;  //左上
			else if (x > (width() - m_border) && x < width() &&
				y < m_border)
				*result = HTTOPRIGHT;  //右上
			else if (x < m_border)
				*result = HTLEFT;  //左
			else if (x > (width() - m_border) && x < width())
				*result = HTRIGHT;  //右
			else if (y < m_border)
				*result = HTTOP;  //上
			else if (y > (height() - m_border) && y < height())
				*result = HTBOTTOM;  //下
			else
				*result = HTCLIENT;
			return true;
		}
	}
		break;
	case WM_NCLBUTTONDBLCLK:
	{
		if (m_flags & WT_MaxButtonHint)
		{
			if (windowState() & Qt::WindowMaximized)
			{
				showNormal();
				if (m_btn_max != nullptr)
					m_btn_max->show();
				if (m_btn_restore != nullptr)
					m_btn_restore->hide();
			}
			else
			{
				showMaximized();
				if (m_btn_max != nullptr)
					m_btn_max->hide();
				if (m_btn_restore != nullptr)
					m_btn_restore->show();
			}
			return true;
		}
	}
		break;
	default:
		break;
	}

	return QWidget::nativeEvent(eventType, message, result);
}



#ifndef __DEF_WIDGET_BASE_H__
#define __DEF_WIDGET_BASE_H__
// $_FILEHEADER_BEGIN *****************************************
// �ļ�˵����ʵ�ִ��ڵ���󻯡���С������ԭ���رա����칦�ܻ���
// $_FILEHEADER_END *****************************************

#include <QWidget>

class QLabel;
class QToolButton;
class QBoxLayout;
class CWidgetBase  : public QWidget
{
	Q_OBJECT
public:
	enum WidgetType
	{
		WT_MinButtonHint = 0x00000001,
		WT_MaxButtonHint = 0x00000002,
		WT_CloseButtonHint = 0x00000004,
		WT_BorderSizeHint  = 0x00000008,
		WT_RoundMaskHint   = 0x00000010,
		WT_SystemButtonHint = WT_MinButtonHint | WT_MaxButtonHint | WT_CloseButtonHint,
		WT_OverridesSystemHint = WT_SystemButtonHint | WT_BorderSizeHint,
	};
	Q_DECLARE_FLAGS(WidgetFlags, WidgetType)

public:
	CWidgetBase(QWidget *parent, WidgetFlags flags = WT_OverridesSystemHint);
	virtual~CWidgetBase();

Q_SIGNALS:
	//�ر��ź�
	void closed();

public:
	//��ӱ���������
	void addCaptionLayout(QBoxLayout* layout);
	//���ϵͳ��ť����
	void addButtonLayout(QBoxLayout* layout);
	//���ñ���
	void setTitle(const QString& title);
protected:
	virtual bool nativeEvent(const QByteArray& eventType, void* message, long* result);
	virtual void paintEvent(QPaintEvent* event);
	//ʵ���Զ������
	virtual void paint(QPaintEvent* event) {};
protected:
	QLabel*							m_lab_title	=	nullptr;
	QToolButton*					m_btn_min	=	nullptr;
	QToolButton*					m_btn_max	=	nullptr;
	QToolButton*					m_btn_close	=	nullptr;
	QToolButton*					m_btn_restore=	nullptr;

private:
	int								m_border = 4;
	WidgetFlags						m_flags;
	QBoxLayout*						m_btn_layout	=	nullptr;
	QBoxLayout*						m_caption_layout = nullptr;
};

#endif //  __DEF_WIDGET_BASE_H__
#include "list_item_delegate.h"

CListItemDelegate::CListItemDelegate(QObject *parent)
	: QAbstractItemDelegate(parent)
{
}

CListItemDelegate::~CListItemDelegate()
{
}

// painting
void CListItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

}

QSize CListItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	return QSize();
}
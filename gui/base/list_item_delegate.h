#ifndef __DEF_LIST_ITEM_DELEGATE_H__
#define __DEF_LIST_ITEM_DELEGATE_H__

#include <QAbstractItemDelegate>

class CListItemDelegate  : public QAbstractItemDelegate
{
	Q_OBJECT

public:
	CListItemDelegate(QObject *parent);
	virtual~CListItemDelegate();

public:
    // painting
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
};

#endif // __DEF_LIST_ITEM_DELEGATE_H__
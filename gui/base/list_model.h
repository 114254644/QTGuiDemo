#ifndef __DEF_LIST_MODEL_H__
#define __DEF_LIST_MODEL_H__
#include <QAbstractItemModel>

class CListModel  : public QAbstractItemModel
{
	Q_OBJECT

public:
	CListModel(QObject *parent);
	virtual~CListModel();

public:
	virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
	virtual QModelIndex parent(const QModelIndex& child) const;
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
};

#endif // __DEF_LIST_MODEL_H__
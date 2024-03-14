#include "list_model.h"

CListModel::CListModel(QObject *parent)
	: QAbstractItemModel(parent)
{}

CListModel::~CListModel()
{

}

QModelIndex CListModel::index(int row, int column, const QModelIndex& parent) const
{
	return QModelIndex();
}

QModelIndex CListModel::parent(const QModelIndex& child) const
{
	return QModelIndex();
}

int CListModel::rowCount(const QModelIndex& parent) const
{
	return 0;
}

int CListModel::columnCount(const QModelIndex& parent) const
{
	return 0;
}

QVariant CListModel::data(const QModelIndex& index, int role) const
{
	return QVariant();
}
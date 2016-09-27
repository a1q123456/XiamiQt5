#include "pch.h"
#include "functionlistmodel.h"
#include "functionlist.h"

FunctionListModel::FunctionListModel(QObject *parent) :
    QAbstractListModel(parent),
    function_list(FunctionList::function_list())
{
    row_count = function_list.length();
}

int FunctionListModel::rowCount(const QModelIndex & /*parent*/) const
{
   return row_count;
}

int FunctionListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}
QVariant FunctionListModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case Qt::DisplayRole:
        return function_list[index.row()];
    case Qt::TextAlignmentRole:
        return Qt::AlignVCenter + Qt::AlignHCenter;
    }
    return QVariant();
}

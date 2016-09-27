#ifndef FUNCTIONLISTMODEL_H
#define FUNCTIONLISTMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <QStringList>

class FunctionListModel: public QAbstractListModel
{
    Q_OBJECT
private:
    int row_count;
    const QStringList function_list;
public:

    FunctionListModel(QObject *parent);
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

#endif // FUNCTIONLISTMODEL_H

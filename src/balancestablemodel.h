#ifndef BALANCESTABLEMODEL_H
#define BALANCESTABLEMODEL_H

#include "unspentoutput.h"

#include "precompiled.h"

class BalancesTableModel : public QAbstractTableModel
{
public:
    BalancesTableModel(QObject* parent);
    ~BalancesTableModel();

    void setNewData(const QMap<QString, double>* balances, const QList<UnspentOutput>* outputs);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<std::tuple<QString, QString>>*    modeldata   = nullptr;    
    QList<UnspentOutput>*                   utxos       = nullptr;  
};

#endif // BALANCESTABLEMODEL_H
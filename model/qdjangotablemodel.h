#ifndef QDJANGOTABLEMODEL_H
#define QDJANGOTABLEMODEL_H

#include <QAbstractTableModel>

#include <QDjangoModel.h>
#include <QDjangoQuerySet.h>
#include <QDjangoWhere.h>

template<class Type>
class QDjangoTableModel : public QAbstractTableModel {
public:

    QDjangoTableModel(QObject *parent);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role) const;
    void setFilter(const QDjangoWhere &filter);

signals:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
private:
    QDjangoQuerySet<Type> _model;
    QDjangoQuerySet<Type> *_m_ptr;
};


template <class Type>
QDjangoTableModel<Type>::QDjangoTableModel(QObject *parent) : QAbstractTableModel(parent = 0) {
    _model = QDjangoQuerySet<Type>();
    _m_ptr = &_model;
}


template <class Type>
int QDjangoTableModel<Type>::rowCount(const QModelIndex &parent) const {
    return _model.count();
}


template <class Type>
int QDjangoTableModel<Type>::columnCount(const QModelIndex &parent) const {
    if(_m_ptr->values().isEmpty()) {
        return 0;
    }
    //if(_model->values())
    return _m_ptr->values().at(0).size();
}


template <class Type>
QVariant QDjangoTableModel<Type>::data(const QModelIndex &index, int role) const {
    if(role == Qt::DisplayRole) {
        QString key = _m_ptr->values().at(index.row()).keys().at(index.column());
        return _m_ptr->values().at(index.row())[key];
    }
    return QVariant();
}


template <class Type>
QVariant QDjangoTableModel<Type>::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole && !_m_ptr->values().isEmpty()) {
        return _m_ptr->values().at(0).keys().at(section);
    }
    return QVariant();
}


template <class Type>
bool QDjangoTableModel<Type>::setData(const QModelIndex &index, const QVariant &value, int role) const {
    if (index.isValid() && role == Qt::EditRole) {

        //emit dataChanged(index, index);
        return true;
    }
    return false;
}


template <class Type>
void QDjangoTableModel<Type>::setFilter(const QDjangoWhere &filter) {
    _model = _m_ptr->filter(filter);
    _m_ptr = &_model;
}


#endif // QDJANGOTABLEMODEL_H

#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QVector>
#include <QMap>

class dataconfig : public QObject
{
    Q_OBJECT
public:
    explicit dataconfig(QObject *parent = 0);
    
    QMap<int,QVector<QVector<int>>> mData;

signals:

public slots:
};

#endif // DATACONFIG_H

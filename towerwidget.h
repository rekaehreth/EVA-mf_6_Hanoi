#ifndef TOWERWIDGET_H
#define TOWERWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QVector>
#include "hanoi.h"
#include "diskwidget.h"

class TowerWidget : public QWidget
{
    Q_OBJECT
private:
    Hanoi* _model;
    int _id; // number of pole
    QBoxLayout* _layout;

public:
    TowerWidget(Hanoi* m, int id, QWidget *parent = nullptr);

signals:

private slots:
    void on_updateDisks();
};

#endif // TOWERWIDGET_H

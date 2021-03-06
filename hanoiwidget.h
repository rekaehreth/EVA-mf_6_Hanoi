#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>

#include "hanoi.h"
#include "towerwidget.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class HanoiWidget; }
QT_END_NAMESPACE

class HanoiWidget : public QWidget
{
    Q_OBJECT

private: 
    Ui::HanoiWidget *ui;
    Hanoi* _model;
    int from;
    int onto;

public:
    HanoiWidget(QWidget *parent = nullptr);
    ~HanoiWidget();

private slots:
    void on_newGame();
    void on_movingRefused();
    void on_gameOver();

    void on_diskNumberBox_valueChanged(int arg1);

signals:
    void set_on_numberSpinbox();

};
#endif // HANOIWIDGET_H

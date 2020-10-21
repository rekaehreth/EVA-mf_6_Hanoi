#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HanoiWidget; }
QT_END_NAMESPACE

class HanoiWidget : public QWidget
{
    Q_OBJECT

public:
    HanoiWidget(QWidget *parent = nullptr);
    ~HanoiWidget();
    void init(); // sets the start state in state 
    void final(); // checks if the current state in state is final
    bool moveDisk(int from, int onto); // returns if the selected move can be done (i.e. if the state can be changed)
    int getDiskNumber(); // returns the number of disks on a pole (size of state)
    QVector<int> getDisksOnTower(); // returns a vector containing the number of disks on a pole in descending order based on size 

private:
    int size;
    QVector<int> state;
    Ui::HanoiWidget *ui;
};
#endif // HANOIWIDGET_H

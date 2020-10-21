#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HanoiWidget; }
QT_END_NAMESPACE

class HanoiWidget : public QWidget
{
    Q_OBJECT

private:
    QVector<int> state;
    Ui::HanoiWidget *ui;

public:
    HanoiWidget(QWidget *parent = nullptr);
    ~HanoiWidget();
    void init();                        // sets the start state in state 
    bool final();                       // checks if the current state in state is final
    bool moveDisk(int from, int onto);  // returns if the selected move can be done (i.e. if the state can be changed)
    int getDiskNumber();                // returns the number of disks on a pole (size of state)
    QVector<int> getDisksOnTower();     // returns a vector containing the number of disks on a pole in descending order based on size 

private slots: 
    void updateTowers();                // triggered when state is changed (triggered at the end of init(), succesfull moveDisk() )
    void movingRefused();               // unsuccesfull moveDisk()
    void gameOver();                    // after succesful moveDisk() final() returns true for the current state 

};
#endif // HANOIWIDGET_H

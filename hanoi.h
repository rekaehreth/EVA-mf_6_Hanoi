#ifndef HANOI_H
#define HANOI_H

#include <QObject>
#include <QVector>

class Hanoi : public QObject {
    Q_OBJECT
private: 
    int startingPole;
    int numOfDisks = 3;
    QVector<int> state;

public:
    static int towerCount;              // **TODO** What's this?
    Hanoi(QObject *parent = nullptr);
    /// methods
    void init();                        // sets the start state in state, sets the number of disks
    bool final();                       // checks if the current state in state is final
    bool moveDisk(int from, int onto);  // returns if the selected move can be done (i.e. if the state can be changed)
    /// getters
    int getDiskNumber();                // returns the number of disks on a pole (size of state)
    QVector<int> getDisksOnTower( int pole );     // returns a vector containing the number of disks on a pole in descending order based on size
    /// setters 
    void setNumOfDisks( int value );

signals:
    void updateTowers();                // triggered when state is changed (triggered at the end of init(), succesfull moveDisk() )
    void movingRefused();               // unsuccesfull moveDisk()
    void gameOver();                    // after succesful moveDisk() final() returns true for the current state 
};

#endif // HANOI_H

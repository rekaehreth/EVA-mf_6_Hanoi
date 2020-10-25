#include "hanoi.h"
#include <QRandomGenerator>

Hanoi::Hanoi(QObject *parent) : QObject(parent)
{

}

// sets the start state in state
void Hanoi::init() 
{
    startingPole = QRandomGenerator::global()->generate() % 3;
    for ( int i = 0; i < numOfDisks; ++i ){
        this->state.push_back( startingPole );
    }
    this->updateTowers();
}

// checks if the current state in state is final
bool Hanoi::final()
{
    bool result = true;
    int curIdx;
    int prevIdx = this->state[ 0 ];
    for ( int i = 1; i < this->state.size(); ++i )
    {
        curIdx = this->state[ i ];
        if ( curIdx == startingPole ) return false;
        if ( !( prevIdx == curIdx ) ){
            result = false;
        }
        prevIdx = curIdx;
    }
    return result;
}

// returns if the selected move can be done (i.e. if the state can be changed)
bool Hanoi::moveDisk(int from, int onto)
{
    if ( from >= 0 && from < 3 && onto >= 0 && onto < 3 && from != onto ) {
        QVector<int> diskOnFrom = getDisksOnTower( from );
        QVector<int> diskOnTo = getDisksOnTower( onto );
        if ( diskOnFrom.size() != 0 ) {
            int lastDiskOnFrom = diskOnFrom.last();
            int lastDiskOnTo = ( diskOnTo.size() == 0 ) ? 42 : diskOnTo.last();
            if ( lastDiskOnFrom < lastDiskOnTo ) {
                this->state[ lastDiskOnFrom ] = onto;
                this->updateTowers();
                return true;
            }
        this->movingRefused();
        }
    }
    return false;
}

// returns the number of disks on a pole (size of state)
int Hanoi::getDiskNumber()
{
    return this->state.size();
}

// returns a vector containing the number of disks on a pole in descending order based on size 
QVector<int> Hanoi::getDisksOnTower( int pole )
{
    QVector<int> result; 
    for ( int i = ( this->state.size() - 1 ); i >= 0 ; --i ) {
        if ( this->state[ i ] == pole ) {
            result.push_back( i );
        }
    }
    return result;
}

void Hanoi::setNumOfDisks(int value)
{
    this->numOfDisks = value;
    this->init();
}

#include "hanoiwidget.h"
#include "ui_hanoiwidget.h"

HanoiWidget::HanoiWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HanoiWidget)
{
    ui->setupUi(this);
}

HanoiWidget::~HanoiWidget()
{
    delete ui;
}

// sets the start state in state
void HanoiWidget::init() 
{

}

// checks if the current state in state is final
bool HanoiWidget::final()
{
    bool result = true;
    int curIdx;
    int prevIdx = state[ 0 ];
    for ( int i = 1; i < state.size(); ++i )
    {
        curIdx = state[ i ];
        if ( !( prevIdx == curIdx ) ){
            result = false;
        }
        prevIdx = curIdx;
    }
    return result;

}

// returns if the selected move can be done (i.e. if the state can be changed)
// bool HanoiWidget::moveDisk(int from, int onto)
// {

// }

// returns the number of disks on a pole (size of state)
int HanoiWidget::getDiskNumber()
{
    return state.size();
}

// returns a vector containing the number of disks on a pole in descending order based on size 
// QVector<int> HanoiWidget::getDisksOnTower()
// {

// }


#include "hanoiwidget.h"
#include "ui_hanoiwidget.h"

HanoiWidget::HanoiWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HanoiWidget)
{
    ui->setupUi(this);
    setMinimumWidth((DiskWidget::maxDiskWidth + 20) * Hanoi::towerCount);
    _model = new Hanoi();
    for (int i = 0; i < Hanoi::towerCount; ++i) {
    ui->gridLayout->setColumnStretch(i, 1);
    TowerWidget* tower = new TowerWidget(_model, i, this);
    ui->gridLayout->addWidget(tower, 0, i);
    connect(_model, SIGNAL(updateTowers()), tower, SLOT(on_updateDisks()));
    }
    connect(ui->newGameButton, SIGNAL(clicked()), this, SLOT(on_newGame()));
    connect(ui->moveDiskButton, SIGNAL(clicked()), this, SLOT(on_moveDisk()));
    connect(_model, SIGNAL(movingRefused()), this, SLOT(on_movingRefused()));
    connect(_model, SIGNAL(gameOver()), this, SLOT(on_gameOver()));
    on_newGame();
}

HanoiWidget::~HanoiWidget()
{
    delete ui;
}

/*
void HanoiWidget::set_on_numberSpinbox()
{
    QSpinBox* sender = dynamic_cast<QSpinBox*>(QObject::sender());
    if ( sender == this->ui->diskNumberBox ) {
        this->model->setNumOfDisks( sender->value() );
    }
    if ( sender == this->ui->fromBox ) {
        this->from = sender->value();
    }
    if ( sender == this->ui->ontoBox ) {
        this->onto = sender->value();
    }
}

void HanoiWidget::click_on_newGameButton()
{

}

void HanoiWidget::sign_moveDisk()
{

}
*/

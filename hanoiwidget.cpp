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
    // connect(ui->moveDiskButton, SIGNAL(clicked()), this, SLOT(on_moveDisk()));
    connect(_model, SIGNAL(movingRefused()), this, SLOT(on_movingRefused()));
    connect(_model, SIGNAL(gameOver()), this, SLOT(on_gameOver()));

    on_newGame();
}

HanoiWidget::~HanoiWidget()
{
    delete ui;
}

void HanoiWidget::on_newGame()
{
    _model->setNumOfDisks( this->ui->diskNumberBox->value() );
    _model->init();
}

void HanoiWidget::on_movingRefused()
{
    QMessageBox* msg = new QMessageBox();
    msg->setText("Disk cannot be moved to the selected pole.");
    msg->show();
}

void HanoiWidget::on_gameOver()
{
    QMessageBox* msg = new QMessageBox();
    msg->setText("You've won the game.");
    msg->show();
}

void HanoiWidget::on_diskNumberBox_valueChanged(int arg1)
{

}

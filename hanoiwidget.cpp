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


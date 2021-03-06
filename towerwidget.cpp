#include "towerwidget.h"

TowerWidget::TowerWidget(Hanoi* m, int id, QWidget *parent)
  : QWidget(parent), _model(m), _id(id)
{
    _layout = new QBoxLayout(QBoxLayout::BottomToTop, this);
    _layout->setSpacing(0);
    setAcceptDrops(true);
}

int TowerWidget::getId() const {
    return _id;
}

void TowerWidget::on_updateDisks()
{
    while (_layout->count() != 0) {
        QLayoutItem* disk = _layout->takeAt(0);
        delete disk->widget();
    }
    const QVector<int> disks = _model->getDisksOnTower(_id);
    for (int i = 0; i < disks.size(); ++i) {
        DiskWidget* disk = new DiskWidget(disks[i], _model->getDiskNumber(), this);
        _layout->addWidget(disk, 0, Qt::AlignHCenter | Qt::AlignBottom);
    }
    _layout->addStretch(_model->getDiskNumber() - disks.size());
}

void TowerWidget::dropEvent(QDropEvent* event)  {
    const TowerWidget* parentTower =
    qobject_cast<TowerWidget*>(event->mimeData()->parent());
    if (parentTower) {
        if (_model->moveDisk(parentTower->getId(), _id)) event->accept();
        else event->ignore();
    }
}

void TowerWidget::dragEnterEvent(QDragEnterEvent* event) {
    const TowerWidget* parentTower = qobject_cast<TowerWidget*>(event->mimeData()->parent());
    if (parentTower) event->acceptProposedAction();
}

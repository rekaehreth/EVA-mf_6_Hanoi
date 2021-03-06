#include "diskwidget.h"

DiskWidget::DiskWidget(int diskSize, int diskNumber, QWidget *parent) : QWidget(parent)
{
    setFixedSize(maxDiskWidth * (diskSize+1) / diskNumber, diskHeight);
    QPalette pal = palette();
    const int colorValue = 255 * (diskNumber-diskSize-1) / (diskNumber-1);
    pal.setColor(QPalette::Background, QColor(colorValue, 0, 0));
    setAutoFillBackground(true);
    setPalette(pal);
    show();
}

void DiskWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
    QDrag* drag = new QDrag(parentWidget());
    QMimeData* mimeData = new QMimeData();
    mimeData->setParent(parentWidget());
    drag->setMimeData(mimeData);
    drag->exec();
    }
}


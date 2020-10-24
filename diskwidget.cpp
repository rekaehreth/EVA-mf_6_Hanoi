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


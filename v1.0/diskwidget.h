#ifndef DISKWIDGET_H
#define DISKWIDGET_H

#include <QWidget>

class DiskWidget : public QWidget
{
    Q_OBJECT
public:
    static const int diskHeight = 20;
    static const int maxDiskWidth = 120;
    DiskWidget(int diskSize, int diskNumber, QWidget *parent = nullptr);

};

#endif // DISKWIDGET_H

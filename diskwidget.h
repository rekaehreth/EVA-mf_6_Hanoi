#ifndef DISKWIDGET_H
#define DISKWIDGET_H

#include <QWidget>

class DiskWidget : public QWidget
{
    Q_OBJECT
public:
    static const int diskHeight = 300;
    static const int maxDiskWidth = 50;
    explicit DiskWidget(int diskSize, int diskNumber, QWidget *parent = nullptr);

signals:

};

#endif // DISKWIDGET_H

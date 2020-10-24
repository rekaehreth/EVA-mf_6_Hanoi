#ifndef DISKWIDGET_H
#define DISKWIDGET_H

#include <QWidget>

class DiskWidget : public QWidget
{
    Q_OBJECT
public:
    static int diskHeight;
    static int maxDiskWidth;
    explicit DiskWidget(int diskSize, int diskNumber, QWidget *parent = nullptr);

signals:

};

#endif // DISKWIDGET_H

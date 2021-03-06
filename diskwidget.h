#ifndef DISKWIDGET_H
#define DISKWIDGET_H

#include <QWidget>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>

class DiskWidget : public QWidget
{
    Q_OBJECT
public:
    static const int diskHeight = 20;
    static const int maxDiskWidth = 120;
    DiskWidget(int diskSize, int diskNumber, QWidget *parent = nullptr);
private slots:
    void mousePressEvent(QMouseEvent* event);
};

#endif // DISKWIDGET_H

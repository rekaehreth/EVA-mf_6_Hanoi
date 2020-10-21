#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HanoiWidget; }
QT_END_NAMESPACE

class HanoiWidget : public QWidget
{
    Q_OBJECT

public:
    HanoiWidget(QWidget *parent = nullptr);
    ~HanoiWidget();

private:
    Ui::HanoiWidget *ui;
};
#endif // HANOIWIDGET_H

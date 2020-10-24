#ifndef HANOIWIDGET_H
#define HANOIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HanoiWidget; }
QT_END_NAMESPACE

class HanoiWidget : public QWidget
{
    Q_OBJECT

private:
    
    Ui::HanoiWidget *ui;

public:
    HanoiWidget(QWidget *parent = nullptr);
    ~HanoiWidget();

private slots:
    void set_on_numberSpinbox();
    void click_on_newGameButton();
    void sign_moveDisk();

};
#endif // HANOIWIDGET_H

#ifndef SIXTHWINDOW_H
#define SIXTHWINDOW_H

#include <QWidget>

namespace Ui {
class sixthwindow;
}

class sixthwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit sixthwindow(void* window_parent,QWidget *parent = 0);
    ~sixthwindow();
    
private:
    Ui::sixthwindow *ui;
    QWidget* m_parent;
};

#endif // SIXTHWINDOW_H

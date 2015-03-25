#ifndef FIRTHWINDOW_H
#define FIRTHWINDOW_H

#include <QWidget>

namespace Ui {
class firthwindow;
}

class firthwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit firthwindow(void *window_parent,QWidget *parent = 0);
    ~firthwindow();
    
private slots:
    void on_find_clicked();

private:
    Ui::firthwindow *ui;
    QWidget* m_parent;
};

#endif // FIRTHWINDOW_H

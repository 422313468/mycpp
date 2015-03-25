#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QWidget>
#include "company.h"

namespace Ui {
class fourthwindow;
}

class fourthwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit fourthwindow(void* window_parent,QWidget *parent = 0);
    ~fourthwindow();
    
private slots:
    void on_delete_2_clicked();

private:
    Ui::fourthwindow *ui;
    Company* m_company;
    QWidget* m_parent;
};

#endif // FOURTHWINDOW_H

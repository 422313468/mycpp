#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include "thirdwindow.h"
#include "fourthwindow.h"
#include "firthwindow.h"
namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit secondwindow(void *window_parent,QWidget *parent = 0);
    ~secondwindow();
    
private slots:
    void on_createusr_clicked();

    void on_showusr_clicked();

    void on_deleteusr_clicked();

    void on_findusr_clicked();

private:
    Ui::secondwindow *ui;
    thirdwindow* third;
    fourthwindow* fourth;
    //Company* m_company;
    QWidget* m_parent;
    firthwindow* firth;

};

#endif // SECONDWINDOW_H

#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include "thirdwindow.h"
#include "fourthwindow.h"
namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit secondwindow(Company* p,QWidget *parent = 0);
    ~secondwindow();
    
private slots:
    void on_createusr_clicked();

    void on_showusr_clicked();

    void on_deleteusr_clicked();

private:
    Ui::secondwindow *ui;
    thirdwindow* third;
    fourthwindow* fourth;
    Company* m_company;
};

#endif // SECONDWINDOW_H

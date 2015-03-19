#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include "thirdwindow.h"
namespace Ui {
class secondwindow;
}

class secondwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit secondwindow(QWidget *parent = 0);
    ~secondwindow();
    
private slots:
    void on_createusr_clicked();

private:
    Ui::secondwindow *ui;
    thirdwindow* third;
};

#endif // SECONDWINDOW_H

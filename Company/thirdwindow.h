#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H
#include "company.h"
#include "person.h"
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMainWindow>


class Company;
class Person;
namespace Ui {
class thirdwindow;
}

class thirdwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit thirdwindow(void* window_parent,QWidget *parent = 0);
    ~thirdwindow();
    
private slots:

    void on_create_newusr_clicked();

private:
    Ui::thirdwindow *ui;
    //Company* m_company;
    QWidget* m_parent;

};

#endif // THIRDWINDOW_H

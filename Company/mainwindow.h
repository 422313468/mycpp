#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include "secondwindow.h"
#include "person.h"
#include <QtSql>
class QPushButton;
class QWidget;
class QLabel;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void create_company();
    Company* m_company;
    
private slots:

    void on_logusr_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton* m_logusr;
    secondwindow* sec;

};

#endif // MAINWINDOW_H

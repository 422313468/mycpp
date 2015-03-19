#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include "secondwindow.h"
#include "person.h"
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
    
private slots:
    void on_mastername_textEdited();

    void on_masterpasswd_textEdited();

    void on_logusr_clicked();

private:
    Ui::MainWindow *ui;
    QLabel* m_name;
    QLabel* m_passwd;
    QPushButton* m_logusr;
    secondwindow* sec;
};

#endif // MAINWINDOW_H

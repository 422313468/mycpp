#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "secondwindow.h"
#include "company.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // sec = new secondwindow();
    create_company();
   // m_name = new QLabel("name",this);
   // m_passwd = new QLabel("passwd",this);
  //  m_logusr = new QPushButton("登录",this);
   // connect(m_logusr,SIGNAL(clicked()),this,SLOT(on_logusr_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::create_company()
{
    m_company = Company::getcompany();
}

void MainWindow::on_logusr_clicked()
{
    if(ui->mastername->text() == "admin")
    {
        if(ui->masterpasswd->text() == "123456")
        {
         qDebug() << "welcome" << endl;
         sec = new secondwindow(this);
         sec->show();
        }
    }
    else
    {
        qDebug() << "error" << endl;
    }

}

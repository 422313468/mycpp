#include "fourthwindow.h"
#include "ui_fourthwindow.h"
#include <QDebug>
#include <QString>
#include "mainwindow.h"

fourthwindow::fourthwindow(void* window_parent,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fourthwindow)
{
    ui->setupUi(this);
    m_parent = (QWidget*)window_parent;
}

fourthwindow::~fourthwindow()
{
    delete ui;
}

void fourthwindow::on_delete_2_clicked()
{
    QString vocation = ui->comboBox->currentText();
    QString nameid = ui->deletematter->text();
    //((MainWindow*)m_parent)->m_company->deleteusr(vocation,nameid);
    ((MainWindow*)m_parent)->m_company->deletemember(vocation,nameid);
    close();
}

#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QWidget>
#include <QDebug>
#include <iostream>
#include "company.h"
#include "person.h"
#include "mainwindow.h"

using namespace std;
secondwindow::secondwindow(void* window_parent,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
   // m_company = p;
    m_parent = (QWidget*)window_parent;
    QObject::connect(ui->calculate,SIGNAL(clicked()),this,SLOT(on_calculate_clicked1()));
}

secondwindow::~secondwindow()
{
    delete ui;
   // ((MainWindow*)m_parent)->m_company->remove(id,"ssss");

}

void secondwindow::on_createusr_clicked()
{
    third = new thirdwindow(m_parent);
    third->show();
}

void secondwindow::on_showusr_clicked()
{
    //m_company->showPerson();
    QString b;
    ui->memberEdit->clear();
    //((MainWindow*)m_parent)->m_company->showusr(b);
    ((MainWindow*)m_parent)->m_company->showdatabase(b);
    ui->memberEdit->append(b);


}



void secondwindow::on_deleteusr_clicked()
{
    fourth = new fourthwindow(m_parent);
    fourth->show();
}

void secondwindow::on_findusr_clicked()
{
    firth = new firthwindow(m_parent);
    firth->show();
}

void secondwindow::on_calculate_clicked1()
{
    sixth = new sixthwindow(m_parent);
    sixth->show();

}

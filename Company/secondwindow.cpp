#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QWidget>
#include <QDebug>
#include <iostream>
#include "company.h"
#include "person.h"
using namespace std;
secondwindow::secondwindow(Company *p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    m_company = p;

}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_createusr_clicked()
{
    third = new thirdwindow(m_company);
    third->show();
}

void secondwindow::on_showusr_clicked()
{
    //m_company->showPerson();
    ui->memberEdit->clear();
    list<Person*>::iterator it;
    QString b;
    QString c;

    list<Person*> coll = m_company->getlist();
    for(it=coll.begin();it!=coll.end();++it)
    {
        c = QString::number((*it)->get_id());
        b = c + "             " + (*it)->get_name() +"             "
                + (*it)->get_gender() + "              "+(*it)->get_salary();
        ui->memberEdit->append(b);
    }
}



void secondwindow::on_deleteusr_clicked()
{
    fourth = new fourthwindow(m_company);
    fourth->show();
}

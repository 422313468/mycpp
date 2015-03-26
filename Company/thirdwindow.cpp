#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "person.h"
#include "company.h"
#include <QDebug>
#include "mainwindow.h"
#include "secondwindow.h"



thirdwindow::thirdwindow(void* window_parent,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
    m_parent = (QWidget*)window_parent;
    QObject::connect(ui->newname,SIGNAL(returnPressed()),this,SLOT(on_create_newusr_clicked()));
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_create_newusr_clicked()
{
    QString newname = ui->newname->text();
    QString gender = ui->gender->text();
    QString salary = ui->salary->text();
    //ui->comboBox->editTextChanged();
    QString vocation = ui->comboBox->currentText();
    int level = 0;
    ((MainWindow*)m_parent)->m_company->createusr(vocation,newname,gender,salary,level);
    qDebug() << "level" << level << endl;
    ((MainWindow*)m_parent)->m_company->addmember_from_database(newname,gender,salary,level);
    ui->newname->clear();
    ui->gender->clear();
    ui->salary->clear();
    close();
}

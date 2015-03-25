#include "firthwindow.h"
#include "ui_firthwindow.h"
#include "mainwindow.h"

firthwindow::firthwindow(void* window_parent,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::firthwindow)
{
    ui->setupUi(this);
    m_parent = (QWidget*)window_parent;
}

firthwindow::~firthwindow()
{
    delete ui;
}


void firthwindow::on_find_clicked()
{
    ui->textEdit->clear();
    QString b;
    ((MainWindow*)m_parent)->m_company->show_name_id_vocation(ui->comboBox->currentText()
                                                           ,ui->lineEdit->text(),b);
    ui->textEdit->append(b);
}

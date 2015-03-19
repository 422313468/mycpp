#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    third = new thirdwindow;
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_createusr_clicked()
{
    third->show();
}

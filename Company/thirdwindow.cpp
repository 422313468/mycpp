#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "person.h"
#include "company.h"
thirdwindow::thirdwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);

}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_create_newusr_clicked()
{
    static Company company;
    if(ui->comboBox->currentText() == "General"){
                    General* number = new General(ui->newname->text(),
                                                  ui->gender->text(),ui->salary->text(),4);
                    number->m_id = getm_id();
                    company.general->push_back(number);
    }
}

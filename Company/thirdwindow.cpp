#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "person.h"
#include "company.h"
#include <QDebug>


thirdwindow::thirdwindow(Company* p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
    m_company = p;
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

void thirdwindow::on_create_newusr_clicked()
{
   //static Company company;
    if(ui->comboBox->currentText() == "General"){
        if(ui->newname->text().isEmpty()||ui->gender->text().isEmpty()||ui->salary->text().isEmpty()){
            qDebug()<< "create not NULL !" << endl;
        }else{
            Person* number = new General(ui->newname->text(),ui->gender->text(),ui->salary->text(),
                                                  4,++Person::count);
            m_company->push_back(number);
            qDebug() << "create general success" << endl;
            close();
        }
    }else if(ui->comboBox->currentText() == "Market"){
        if((ui->newname->text().isEmpty()||ui->gender->text().isEmpty()||ui->salary->text().isEmpty())){
            qDebug()<< "create not NULL !" << endl;
        }else{
            Person* number = new Market(ui->newname->text(),ui->gender->text(),ui->salary->text(),
                                          2,++Person::count);
            m_company->push_back(number);
            qDebug() << "create market success" << endl;
            close();
        }
    }else if(ui->comboBox->currentText() == "Artisan"){
        if((ui->newname->text().isEmpty()||ui->gender->text().isEmpty()||ui->salary->text().isEmpty())){
            qDebug()<< "create not NULL !" << endl;
        }else{
            Person* number = new Artisan(ui->newname->text(),ui->gender->text(),ui->salary->text(),
                                          3,++Person::count);
            m_company->push_back(number);
            qDebug() << "create artisan success" << endl;
            close();
        }
    }else if(ui->comboBox->currentText() == "Part_time"){
        if((ui->newname->text().isEmpty()||ui->gender->text().isEmpty()||ui->salary->text().isEmpty())){
            qDebug()<< "create not NULL !" << endl;
        }else{
            Person* number = new Part_time(ui->newname->text(),ui->gender->text(),ui->salary->text(),
                                          1,++Person::count);
            m_company->push_back(number);
            qDebug() << "create part_time success" << endl;
            close();
        }
    }else{
        qDebug() << "create error !!!" << endl;
    }
}

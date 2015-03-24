#include "fourthwindow.h"
#include "ui_fourthwindow.h"
#include <QDebug>
#include <QString>

fourthwindow::fourthwindow(Company* p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fourthwindow)
{
    ui->setupUi(this);
    m_company = p;
}

fourthwindow::~fourthwindow()
{
    delete ui;
}

void fourthwindow::on_delete_2_clicked()
{
    list<Person*>::iterator it;
    QString b;
    list<Person*> coll = m_company->getlist();
    if(ui->comboBox->currentText() == "name"){
        if(ui->deletematter->text().isEmpty()){
            qDebug() << "delete error" << endl;
        }else{
            for(it = coll.begin();it != coll.end();++it){
                qDebug() << "hello1" << endl;
                if((*it)->get_name() == ui->deletematter->text()){
                    qDebug() << "hello2" << endl;
                    coll.erase(it);
                    qDebug() << "delete success" << endl;
                    //close();
                }
            }
            qDebug() << "no the name" << endl;
        }
    }else if(ui->comboBox->currentText() == "id"){
        if(ui->deletematter->text().isEmpty()){
            qDebug() << "delete error" << endl;
        }else{
            for(it = coll.begin();it != coll.end();++it){
                b = QString::number((*it)->get_id());
                if(b == ui->deletematter->text()){
                    coll.erase(it);
                    qDebug() << "delete success" << endl;
                  //  close();
                }
            }
            qDebug() << "no the id" << endl;
        }
    }else{
        qDebug() << "delete error" << endl;
    }
}

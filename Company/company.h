#ifndef _COMPANY_H_
#define _COMPANY_H_
#include "person.h"
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMainWindow>
using namespace std;

class Company{

public:
    Company();
    ~Company();
    void push_back(Person* other){
        person.push_back(other);
    }
    bool remove(int id,QString name);
    void createusr(QString& vocation,QString& newname,QString& gender,QString& salary,int& level);
    void showusr(QString& b);
    void deleteusr(QString& vocation,QString& nameid);
    void show_name_id_vocation(QString vocation,QString name_id_vocation,QString& b);
    void showdatabase(QString& b);
    void addmember_from_database(QString& name,QString& gender,QString& salary,int& level);
    void deletemember_from_database(QString vocation,QString nameid);
    void find_from_database(QString vocation,QString nameid,QString& d);
    //void showPerson();
private:
    list<Person*> person;
    QSqlDatabase db;
    bool ok;
public:
    static Company* fact;
    static Company* getcompany();
};

#endif

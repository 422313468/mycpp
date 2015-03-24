#include "person.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

int Person::count = 0;


Person::Person(QString name,QString gender,QString salary,int level,int id)
    :m_name(name),m_gender(gender),m_salary(salary),m_level(level),m_id(id)
{

}

Person::~Person()
{

}

General::General(QString name,QString gender,QString salary,int level,int id)
    :Person(name,gender,salary,level,id)
{
    // general_num = new list<General>;
   
}

General::~General()
{
}
QString General::get_gender(){
    return m_gender;
}
int General::get_id(){
    return m_id;
}
QString General::get_salary(){
    return m_salary;
}





Artisan::Artisan(QString name,QString gender,QString salary,int level,int id)
    :Person(name,gender,salary,level,id)
{
}

Artisan::~Artisan()
{
}

QString Artisan::get_gender(){
    return m_gender;
}
int Artisan::get_id(){
    return m_id;
}
QString Artisan::get_salary(){
    return m_salary;
}






Market::Market(QString name,QString gender,QString salary,int level,int id)
    :Person(name,gender,salary,level,id)
{
}

Market::~Market()
{
}
QString Market::get_gender(){
    return m_gender;
}

int Market::get_id(){
    return m_id;
}
QString Market::get_salary(){
    return m_salary;
}





Part_time::Part_time(QString name,QString gender,QString salary,int level,int id)
    :Person(name,gender,salary,level,id)
{
}

Part_time::~Part_time()
{
}

QString Part_time::get_gender(){
    return m_gender;
}

int Part_time::get_id(){
    return m_id;
}
QString Part_time::get_salary(){
    return m_salary;
}

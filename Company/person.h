#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <QString>
#include <list>
#include <QDebug>
using namespace std;

class Person{

public:
    Person(QString name,QString gender,QString salary,int level,int id);
    virtual ~Person() = 0;
    //virtual void adduser() = 0;
    //virtual void deluser() = 0;
    //virtual void changeuser() = 0;
    //virtual void checkuser() = 0;
    virtual QString get_name() = 0;
    //virtual void doSomething()=0;
    virtual QString get_gender() = 0;
    virtual QString get_salary() = 0;
    virtual int get_id() = 0;

protected:
    QString m_name;
    QString m_gender;
    QString m_salary;
	int m_level;
    int m_id;
public:
    static int count;
};


class General:public Person
{
public:
    General(QString name,QString gender,QString salary,int level,int id);
    ~General();
    virtual QString get_name(){
        return m_name;
    }
    virtual QString get_gender();
    virtual QString get_salary();
    virtual int get_id();
    //virtual void doSomething(){qDebug()<<"General"<<endl;}
    //virtual void adduser();
    //virtual void deluser();
    //virtual void changeuser();
    //virtual void checkuser()；
	
};

class Artisan:public Person{
public:
    Artisan(QString name,QString gender,QString salary,int level,int id);
    ~Artisan();
    virtual QString get_name(){
        return m_name;
    }
    virtual QString get_gender();
    virtual QString get_salary();
    virtual int get_id();
    //virtual void doSomething(){qDebug()<<"Artisan"<<endl;}

};

class Market:public Person{
public:
    Market(QString name,QString gender,QString salary,int level,int id);
	~Market();
    virtual QString get_name(){
        return m_name;
    }
    virtual QString get_gender();
    virtual QString get_salary();
    virtual int get_id();
    //virtual void doSomething(){qDebug()<<"Market"<<endl;}

};

class Part_time:public Person{
public:
    Part_time(QString name,QString gender,QString salary,int level,int id);
	~Part_time();
    virtual QString get_name(){
        return m_name;
    }
    virtual QString get_gender();
    virtual QString get_salary();
    virtual int get_id();
    //virtual void doSomething(){qDebug()<<"Part_time"<<endl;}

};

#endif


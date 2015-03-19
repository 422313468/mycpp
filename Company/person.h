#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <list>
using namespace std;

class Person{
public:
    Person(string name,string gender,double salary,int level);
    virtual ~Person() = 0;
    //virtual void adduser() = 0;
    //virtual void deluser() = 0;
    //virtual void changeuser() = 0;
    //virtual void checkuser() = 0;
    int getm_id(){
        return m_id;
    }
protected:
	string m_name;
    string m_gender;
    double m_salary;
    static int m_id;
	int m_level;
};

class General:public Person{
public:
    General(string name,string gender,double salary,int level);
	~General();	
    //virtual void adduser();
    //virtual void deluser();
    //virtual void changeuser();
    //virtual void checkuser()；
	
};
/*
class Artisan:public Person{
public:
    Artisan(string name,string gender,double salary,int id,int level);
	~Artisan();
	virtual void adduser();
	virtual void deluser();
	virtual void changeuser();
	virtual void checkuser();
private:
	list<Artisan> artisan_num;
	
};

class Market:public Person{
public:
    Market(string name,string gender,double salary,int id,int level);
	~Market();
	virtual void adduser();
	virtual void deluser();
	virtual void changeuser();
	virtual void checkuser();
private:
	list<Market> market_num;
};

class Part_time:public Person{
public:
    Part_time(string name,string gender,double salary,int id,int level);
	~Part_time();
	virtual void adduser();
	virtual void deluser();
	virtual void changeuser();
	virtual void checkuser();
private:
	list<Part_time> part_time_num;
};
*/
#endif


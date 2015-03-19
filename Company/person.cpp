#include "person.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

int Person::m_id = 0;

Person::Person(string name,string gender,double salary,int level)
    :m_name(name),m_gender(gender),m_salary(salary),m_level(level)
{
    m_id++;
}

Person::~Person()
{
    m_id--;
}

General::General(string name,string gender,double salary,int level)
    :Person(name,gender,salary,level)
{
    // general_num = new list<General>;
   
}

General::~General()
{
}
/*
void General::adduser(){
	cout << "please general name: "<< endl;
	cin >> m_name;
	cout << "please general level: " << endl;
	cin >> m_level;
	cout << "please general money: " << endl;
	cin >> m_money;
	m_id = m_id + 1;
    //general_num.push_back(m_name,m_id,m_level,m_money);

}
*/
/*
Artisan::Artisan(string name,int id,int level,double money)
	:Person(name,id,level,money)
{
}

Artisan::~Artisan()
{
}

Market::Market(string name,int id,int level,double money)
	:Person(name,id,level,money)
{
}

Market::~Market()
{
}

Part_time::Part_time(string name,int id,int level,double money)
	:Person(name,id,level,money)
{
}

Part_time::~Part_time()
{
}

*/


#include <iostream>
using namespace std;

class Employee{
public:
		Employee();
		~Employee();
		void setname();
		void setaddress();
		void setcode();
		void changeName();
		void display();
private:
		char name[30];
		char address[30];
		char code[30];
};


class Date{
public:
		Date(int y=2014,int m=12,int d=31);
		~Date();
		int getyear(){
			return m_year;
		}
		int getmonth(){
			return m_month;
		}
		int getday(){
			return m_day;
		}

private:
		int m_year;
		int m_month;
		int m_day;
};




		Date::Date(int y,int m,int d)
:m_year(y),m_month(m),m_day(d)
{


}
Date::~Date(){

};



Employee::Employee()
{
	name[30] = '\0';
	address[30] = '\0';
	code[30] = '\0';
};
Employee::~Employee(){};


void Employee::setname(){
	cout << "input name: " << endl;
	cin >> name;
}

void Employee::setaddress(){
	cout << "input address: " << endl;
	cin >> address;
}

void Employee::setcode(){
	cout << "input code: " << endl;
	cin >> code;
}

void Employee::display(){
	Date date;
	int year = date.getyear();
	int month = date.getmonth();
	int day = date.getday();
	cout << "name: " << name << " "<< "address: " << address << " " <<"code: " << code << endl;
	cout << "join in company :" << year << "/" << month << "/" << day << endl;
}

void Employee::changeName(){
	cout << "changename: " << endl;
	cin >> name;
	cout << "changeaddress: " << endl;
	cin >> address;

}

int main(int argc,char **argv){
	Employee employee;
	employee.setname();
	employee.setaddress();
	employee.setcode();
	employee.display();
	employee.changeName();
	employee.display();
	return 0;
}

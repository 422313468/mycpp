#ifndef _COMPANY_H_
#define _COMPANY_H_
#include "person.h"
using namespace std;

class Company{

public:
    Company();
    ~Company();
    void push_back(Person* other){
        person.push_back(other);
    }
    list<Person*> getlist();
    //void showPerson();
private:
    list<Person*> person;
public:
    static Company* fact;
    static Company* getcompany();
};

#endif

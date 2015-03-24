#include "company.h"
#include "person.h"
#include <QDebug>

Company* Company::fact = NULL;
Company::Company()
{
}
Company::~Company()
{

}

Company* Company::getcompany(){
    if(NULL == fact){
        fact = new Company;
        return fact;
    }
    return fact;
}
/*
void Company::showPerson()
{
    list<Person*>::iterator it;
    for(it=person.begin();it!=person.end();++it)
    {

    }
}
*/
list<Person*> Company::getlist()
{
    return person;
}

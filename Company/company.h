#ifndef _COMPANY_H_
#define _COMPANY_H_
#include "person.h"
class Company{
public:
    Company();
    ~Company();
private:
    list<General>* general;
//	Artisan* m_artisan;
//	Market* m_market;
//	Part_time* m_part_time;
};

#endif

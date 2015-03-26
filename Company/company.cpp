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

void Company::createusr(QString& vocation,QString& newname,QString& gender,QString& salary,int& level)
{
    if(vocation == "General")
    {
        if(newname.isEmpty()||gender.isEmpty()||salary.isEmpty()){
            qDebug()<< "create not NULL !" << endl;
        }else
        {
            level = 4;
            Person* number = new General(newname,gender,salary,4,++Person::count);
            person.push_back(number);
            qDebug() << "create general success" << endl;
            //close();
        }
    }else if(vocation == "Market"){
        if(newname.isEmpty()||gender.isEmpty()||salary.isEmpty()){
            qDebug()<< "create not NULL !" << endl;
        }else{
            level = 2;
            Person* number = new Market(newname,gender,salary,2,++Person::count);
            person.push_back(number);
            qDebug() << "create Market success" << endl;
            //close();
        }
    }else if(vocation == "Artisan"){
        if(newname.isEmpty()||gender.isEmpty()||salary.isEmpty()){
            qDebug()<< "create not NULL !" << endl;
        }else{
            level = 3;
            Person* number = new Artisan(newname,gender,salary,3,++Person::count);
            person.push_back(number);
            qDebug() << "create Artisan success" << endl;
            //close();
        }
    }else if(vocation == "Part_time"){
        if(newname.isEmpty()||gender.isEmpty()||salary.isEmpty()){
            qDebug()<< "create not NULL !" << endl;
        }else{
            level = 1;
            Person* number = new Part_time(newname,gender,salary,1,++Person::count);
            person.push_back(number);
            qDebug() << "create Part_time success" << endl;
           // close();
        }
    }else{
        qDebug() << "create error !!!" << endl;
    }
}
void Company::showusr(QString& b)
{
    list<Person*>::iterator it;
    QString c;
    for(it=person.begin();it!=person.end();++it)
    {
        c = QString::number((*it)->get_id());

        b +=c + "      " + (*it)->get_name() +"      "
                + (*it)->get_gender() + "      "+(*it)->get_salary()+"\n";


    }

}

void Company::deleteusr(QString& vocation,QString& nameid)
{
    list<Person*>::iterator it;
    QString b;
    if(vocation == "name"){
        if(nameid.isEmpty()){
            qDebug() << "delete error" << endl;
        }else{
            for(it = person.begin();it != person.end();++it)
            {
                qDebug() << "hello1" << endl;
                if((*it)->get_name() == nameid)
                {
                    qDebug() << "hello2" << endl;
                    person.erase(it);
                    qDebug() << "delete success" << endl;
                    //close();
                    return;
                }
            }
            qDebug() << "no the name" << endl;
        }
    }else if(vocation == "id")
    {
        if(nameid.isEmpty()){
            qDebug() << "delete error" << endl;
        }else
        {
            for(it = person.begin();it != person.end();++it)
            {
                b = QString::number((*it)->get_id());
                if(b == nameid)
                {
                    person.erase(it);
                    qDebug() << "delete success" << endl;
                    return;
                  //  close();
                }
            }
            qDebug() << "no the id" << endl;
        }
    }else
    {
        qDebug() << "delete error" << endl;
    }
}

void Company::show_name_id_vocation(QString vocation,QString name_id_vocation,QString& b)
{
    list<Person*>::iterator it;
    QString c;
    int val;
    if(vocation == "name")
    {
        for(it = person.begin();it != person.end();++it)
        {
            if((*it)->get_name() == name_id_vocation){
                c = QString::number((*it)->get_id());

                b +=c + "      " + (*it)->get_name() +"      "
                        + (*it)->get_gender() + "      "+(*it)->get_salary()+"\n";
            }
        }
    }else if(vocation == "id")
    {
        for(it = person.begin();it != person.end();++it)
        {
            val = name_id_vocation.toInt();
            if((*it)->get_id() == val){
                c = QString::number((*it)->get_id());
                b +=c + "      " + (*it)->get_name() +"      "
                        + (*it)->get_gender() + "      "+(*it)->get_salary()+"\n";
            }
        }

    }
    else if(vocation == "vocation")
    {
        for(it = person.begin();it != person.end();++it)
        {
            val = name_id_vocation.toInt();
            if((*it)->get_level() == val){
                c = QString::number((*it)->get_id());
                b +=c + "      " + (*it)->get_name() +"      "
                        + (*it)->get_gender() + "      "+(*it)->get_salary()+"\n";
            }
        }
    }

}

void Company::addmember_from_database(QString& name,QString& gender,QString& salary,int& level){
    if(db.isOpen()){

    }else
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("company");//指定数据库
        db.setUserName("root");
        db.setPassword("123456");
        qDebug() << "hello" << endl;
        ok = db.open();
        qDebug() << ok << endl;
    }
    if(ok){
        qDebug() << "company ok" << endl;
        QString cmd = "insert into m_company values(:id,:level,:name,:gender,:salary)";
        QSqlQuery query;
        query.prepare(cmd);
        query.bindValue(":id",Person::count);
        query.bindValue(":level",level);
        query.bindValue(":name",name);
        query.bindValue(":gender",gender);
        query.bindValue(":salary",salary);
        bool b = query.exec();
        if(b){
            qDebug() << "insert ok" << endl;
        }else{
            qDebug() << "insert error" << endl;
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug() << "company error" << db.lastError() << endl;
    }
}

void Company::showdatabase(QString& b){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("company");//指定数据库
        db.setUserName("root");
        db.setPassword("123456");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "company ok"<< endl;
        QString cmd = "select * from m_company;";
        QSqlQuery query;
        bool d = query.exec(cmd);
        if(d){
            qDebug() <<"select all ok"<< endl;
            while(query.next()){
                //ui->memberEdit->append(b);
                b += (query.value(0).toString()+"          "+query.value(1).toString()
                                            +"          "+query.value(2).toString()+"      "+query.value(3).toString())+"      "+query.value(4).toString()+"\n";
            }
        }else{
            qDebug() <<"select all error"<< endl;
        }
        db.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }else{
        qDebug()<< "company error"<<db.lastError()<< endl;
    }


}

void Company::deletemember_from_database(QString vocation,QString nameid){
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");//与mysql关联
        db.setHostName("localhost");
        db.setDatabaseName("company");//指定数据库
        db.setUserName("root");
        db.setPassword("123456");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "company ok"<< endl;
        if(vocation == "name"){
            QString a = "'"+ nameid + "'";
            QString cmd = "delete from m_company where name = "+ a +";";
            QSqlQuery query;
            bool b = query.exec(cmd);
            if(b){
                qDebug() << "delete name ok" << endl;
            }else{
                qDebug() << "delete name error" << endl;
            }
            db.close();
            QSqlDatabase::removeDatabase("QMYSQL");
         }
         else if(vocation == "id"){
            QString cmd = ("delete from m_company where id ="+ nameid +";");
            QSqlQuery query;
            bool b = query.exec(cmd);
            if(b){
                qDebug() << "delete id ok" << endl;
            }else{
                qDebug() << "delete id error" << endl;
            }
            db.close();
            QSqlDatabase::removeDatabase("QMYSQL");

        }

    }else{
        qDebug()<< "company error"<<db.lastError()<< endl;
    }


}

void Company::find_from_database(QString vocation,QString nameid,QString& d)
{
    if(db.isOpen()){

    }else{
        db =  QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("company");
        db.setUserName("root");
        db.setPassword("123456");
        ok = db.open();
    }
    if(ok){
        qDebug()<< "company ok"<< endl;
        if(vocation == "name")
        {
            QString a = "'" + nameid + "'";
            QString cmd = "select * from m_company where name ="+ a +";";
            QSqlQuery query;
            bool b = query.exec(cmd);
            if(b){
                while(query.next()){
                    d += (query.value(0).toString()+"      "+query.value(1).toString()
                                                +"      "+query.value(2).toString()+"      "+query.value(3).toString())+"      "+query.value(4).toString()+"\n";
                }
                qDebug() << "select name ok" << endl;
            }else{
                qDebug() << "select name error" << endl;
            }
            db.close();
            QSqlDatabase::removeDatabase("QMYSQL");
         } else if(vocation == "id")
        {
            QString cmd = ("select * from m_company where id ="+ nameid +";");
            QSqlQuery query;
            bool b = query.exec(cmd);
            if(b){
                while(query.next()){
                    d += (query.value(0).toString()+"      "+query.value(1).toString()
                                                +"      "+query.value(2).toString()+"      "+query.value(3).toString())+"      "+query.value(4).toString()+"\n";
                }
                qDebug() << "select id ok" << endl;
            }else{
                qDebug() << "select id error" << endl;
            }
            db.close();
            QSqlDatabase::removeDatabase("QMYSQL");
        }else if(vocation == "vocation")
        {
            QString cmd = ("select * from m_company where level = " + nameid + ";");
            QSqlQuery query;
            bool b = query.exec(cmd);
            if(b){
                while(query.next()){
                    d += (query.value(0).toString()+"      "+query.value(1).toString()
                          +"      "+query.value(2).toString()+"      "+query.value(3).toString())+"      "+query.value(4).toString()+"\n";
                }
                qDebug() << "select vocation ok" << endl;
            }else{
                qDebug() << "select vocation error" << endl;
            }
            db.close();
            QSqlDatabase::removeDatabase("QMYSQL");
        }

    }else{
        qDebug()<< "company error"<<db.lastError()<< endl;
    }

}
/*
bool Company::remove(int id,QString name)
{

}
*/

#include <iostream>
#include <string>
using namespace std;
class Engine{
public:
	Engine(int id)
		:m_id(id)
		{
		}
	~Engine(){}
	void start(){
		cout << "Engine start" << endl;
	}
	void stop(){
		cout << "Engine stop" << endl;
	}
private:
	int m_id;
};


class Wheel{
public:
	Wheel(int id)
		:m_id(id)
	{
	}
	~Wheel(){}
	void roll(){
		cout << "wheel rolling" << endl;
	}
private:
	int m_id;
};


class Car{
public:
	Car(Engine *,Wheel *,string name,int);
	~Car(){}

	void run();
	void stop();
private:
	Car(const Car&);
	Car& operator=(const Car&);
	Engine *engine;
	Wheel *wheel;
	string name;
	int price;
};

class Stero{
public:
	Stero(){}
	~Stero(){}
	void play(){
		cout << "stero play" << endl;
	}
};

class Benchi:public Car{
public:
	Benchi(Engine *,Wheel *,string,int,Stero *);
	~Benchi(){}
	void musicon();
private:
	Stero *stero;
};

class Transformer : public Car{
public:
	Transformer(Engine*,Wheel*,string,int,bool);
	~Transformer(){}

	void fight();
	void transform();
private:
	bool val;
};

Car::Car(Engine* e,Wheel* w,string s,int p)
	:engine(e),wheel(w),name(s),price(p)
{
	
}

void Car::run(){
	engine->start();
	wheel->roll();
	cout << "car runing" << endl;
}

void Car::stop(){
	engine->stop();
	cout << "car stoping" << endl;
}

Benchi::Benchi(Engine* e,Wheel* w,string s,int p,Stero* st)
	:Car(e,w,s,p),stero(st)
{

}
void Benchi::musicon(){
	Car::run();
	stero->play();
	cout << "play music now " << endl;
}

Transformer::Transformer(Engine *e,Wheel* w,string s,int p,bool v)
	:Car(e,w,s,p),val(v)
{
}

void Transformer::fight(){
	run();
	cout << "Transformer fight" << endl;
}

void Transformer::transform(){
	run();
	cout << "Transformer transform" << endl;
}
int main(int argc,char** argv){
	Engine e1(1);
	Wheel w1(1);
	Stero stero;
	Benchi benchi(&e1,&w1,"benchi",100,&stero);
	benchi.musicon();

	Transformer t(&e1,&w1,"optimusprime",200,true);
	t.transform();
	t.fight();
	return 0;
}

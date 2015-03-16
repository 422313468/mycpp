#include "calculator.h"

#include <QPushButton>
#include <QLabel>
#include <string>
#include <iostream>
using namespace std;

Calculator::Calculator(){
	num1 = "0";
	num2 = "0";
	j = "0";
	flag = 0;
	oper = '\0';
	setFixedSize(400,300);
	m_resultLabel = new QLabel("0",this);
	m_resultLabel->setGeometry(10,0,380,80);
	m_charC = new QPushButton("c",this);
	m_charC->setGeometry(270,60,120,120);
	m_number0 = new QPushButton("0",this);
	m_number0->setGeometry(10,240,125,60);
	m_number1 = new QPushButton("1",this);
	m_number1->setGeometry(10,180,60,60);
	m_number2 = new QPushButton("2",this);
	m_number2->setGeometry(75,180,60,60);
	m_number3 = new QPushButton("3",this);
	m_number3->setGeometry(140,180,60,60);
	m_number4 = new QPushButton("4",this);
	m_number4->setGeometry(10,120,60,60);
	m_number5 = new QPushButton("5",this);
	m_number6 = new QPushButton("6",this);
	m_number7 = new QPushButton("7",this);
	m_number8 = new QPushButton("8",this);
	m_number9 = new QPushButton("9",this);
	m_number10 = new QPushButton(".",this);
	m_number5->setGeometry(75,120,60,60);
	m_number6->setGeometry(140,120,60,60);
	m_number7->setGeometry(10,60,60,60);
	m_number8->setGeometry(75,60,60,60);
	m_number9->setGeometry(140,60,60,60);
	m_number10->setGeometry(140,240,60,60);
	m_equalBtn = new QPushButton("=",this);
	m_equalBtn->setGeometry(270,180,120,120);

	m_operator1 = new QPushButton("+",this);
	m_operator1->setGeometry(205,240,60,60);
	m_operator2 = new QPushButton("-",this);
	m_operator2->setGeometry(205,180,60,60);
	m_operator3 = new QPushButton("*",this);
	m_operator3->setGeometry(205,120,60,60);
	m_operator4 = new QPushButton("/",this);
	m_operator4->setGeometry(205,60,60,60);
	connect(m_charC,SIGNAL(clicked()),this,SLOT(char1Clicked()));
	connect(m_number1,SIGNAL(clicked()),this,SLOT(number1Clicked()));
	connect(m_number2,SIGNAL(clicked()),this,SLOT(number2Clicked()));
	connect(m_number3,SIGNAL(clicked()),this,SLOT(number3Clicked()));
	connect(m_number4,SIGNAL(clicked()),this,SLOT(number4Clicked()));
	connect(m_number5,SIGNAL(clicked()),this,SLOT(number5Clicked()));
	connect(m_number6,SIGNAL(clicked()),this,SLOT(number6Clicked()));
	connect(m_number7,SIGNAL(clicked()),this,SLOT(number7Clicked()));
	connect(m_number8,SIGNAL(clicked()),this,SLOT(number8Clicked()));
	connect(m_number9,SIGNAL(clicked()),this,SLOT(number9Clicked()));
	connect(m_number0,SIGNAL(clicked()),this,SLOT(number0Clicked()));
	connect(m_number10,SIGNAL(clicked()),this,SLOT(number10Clicked()));
	connect(m_equalBtn,SIGNAL(clicked()),this,SLOT(equalBtnClicked()));
	connect(m_operator1,SIGNAL(clicked()),this,SLOT(operatornum1Clicked()));
	connect(m_operator2,SIGNAL(clicked()),this,SLOT(operatornum2Clicked()));
	connect(m_operator3,SIGNAL(clicked()),this,SLOT(operatornum3Clicked()));
	connect(m_operator4,SIGNAL(clicked()),this,SLOT(operatornum4Clicked()));
}
/*
Calculator::~Calculator()
{
}
*/
void Calculator::equalBtnClicked(){
	double i = 0.0;
	double s1 = num1.toDouble();
	cout << "s1 = " << s1 << endl;
	double s2 = num2.toDouble();
	cout << "s2 = " << s2 << endl;
	switch(Calculator::getoper()){
		case '+':
			i = s1 + s2;
			break;
		case '-':
			i = s1 - s2;
			break;
		case '*':
			i = s1 * s2;
			break;
		case '/':
			i = s1 / s2;
			break;
	}
	num1 = num1.setNum(i);
	m_resultLabel->setText(num1);
}

void Calculator::number1Clicked(){
	cout << "flag = " << flag << endl; 
	if(flag == 0){
		num1 += "1";
	}else if(flag == 1){
		num2 += "1";
	}
	m_resultLabel->setText("1");
}


void Calculator::number2Clicked(){
	if(flag == 0){
		num1 += "2";
	}else if(flag == 1){
		num2 += "2";
	}
}

void Calculator::number3Clicked(){
	if(flag == 0){
		num1 += "3";
	}else if(flag == 1){
		num2 += "3";
	}
	m_resultLabel->setText("3");
}
void Calculator::number4Clicked(){
	if(flag == 0){
		num1 += "4";
	}else if(flag == 1){
		num2 += "4";
	}
	m_resultLabel->setText("4");
}
void Calculator::number5Clicked(){
	if(flag == 0){
		num1 += "5";
	}else if(flag == 1){
		num2 += "5";
	}
	m_resultLabel->setText("5");
}
void Calculator::number6Clicked(){
	if(flag == 0){
		num1 += "6";
	}else if(flag == 1){
		num2 += "6";
	}
	m_resultLabel->setText("6");
}
void Calculator::number7Clicked(){
	if(flag == 0){
		num1 += "7";
	}else if(flag == 1){
		num2 += "7";
	}
	m_resultLabel->setText("7");
}
void Calculator::number8Clicked(){
	if(flag == 0){
		num1 += "8";
	}else if(flag == 1){
		num2 += "8";
	}
	m_resultLabel->setText("8");
}
void Calculator::number9Clicked(){
	if(flag == 0){
		num1 += "9";
	}else if(flag == 1){
		num2 += "9";
	}
	m_resultLabel->setText("9");
}
void Calculator::number0Clicked(){
	if(flag == 0){
		num1 += "0";
	}else if(flag == 1){
		num2 += "0";
	}
	m_resultLabel->setText("0");
}

void Calculator::number10Clicked(){
	if(flag == 0){
		num1 += ".";
	}else if(flag == 1){
		num2 += ".";
	}
	m_resultLabel->setText(".");
}


void Calculator::operatornum1Clicked(){
	oper = '+';
	num2 = "0";
	flag = 1;
}

void Calculator::operatornum2Clicked(){
	oper = '-';
	num2 = "0";
	flag = 1;
}
void Calculator::operatornum3Clicked(){
	oper = '*';
	num2 = "0";
	flag = 1;
}
void Calculator::operatornum4Clicked(){
	oper = '/';
	num2 = "0";
	flag = 1;
}

void Calculator::char1Clicked(){
	flag = 0;
	num1 = "0";
	num2 = "0";
	oper = '\0';
	m_resultLabel->setText("0");
}

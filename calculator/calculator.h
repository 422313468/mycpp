#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <QWidget>
#include <string>
using namespace std;
class QLabel;
class QPushButton;

class Calculator : public QWidget{
	Q_OBJECT
public:
	Calculator();
	~Calculator(){}
	QString getnum1(){
		return num1;
	}
	QString getnum2(){
		return num2;
	}
	char getoper(){
		return oper;
	}
private slots:
	void equalBtnClicked();
	void number1Clicked();
	void number2Clicked();
	void number3Clicked();
	void number4Clicked();
	void number5Clicked();
	void number6Clicked();
	void number7Clicked();
	void number8Clicked();
	void number9Clicked();
	void number0Clicked();
	void number10Clicked();
	void operatornum1Clicked();
	void operatornum2Clicked();
	void operatornum3Clicked();
	void operatornum4Clicked();
	void char1Clicked();
private:
	QLabel *m_resultLabel;
	QPushButton *m_number0;
	QPushButton *m_number1;
	QPushButton *m_number2;
	QPushButton *m_number3;
	QPushButton *m_number4;
	QPushButton *m_number5;
	QPushButton *m_number6;
	QPushButton *m_number7;
	QPushButton *m_number8;
	QPushButton *m_number9;
	QPushButton *m_number10;
	QPushButton *m_equalBtn;
	QPushButton *m_operator1;
	QPushButton *m_operator2;
	QPushButton *m_operator3;
	QPushButton *m_operator4;
	QPushButton *m_charC;
	QString num1;
	QString num2;
	QString j;
	int flag;
	char oper;
};

#endif

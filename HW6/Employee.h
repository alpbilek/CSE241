#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "UNI.h"
#include <string>
#include <iostream>
using namespace std;
class Employee{
	public:
		void set_pid(int p);
		int get_pid();
		void set_name(string n);
		string get_name();
		void set_surname(string sn);
		string get_surname();
		void set_keyword(string kyw);
		string get_keyword();
		int happiness=0;
		string action;
		int drinkTea(UNI& u);  
		int submitPetition(UNI& u);
		virtual void work(int num,UNI& u)=0;
	protected:
		int pid;
		string name,surname,keyword;
};


#endif 
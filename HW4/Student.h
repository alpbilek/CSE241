#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//DEFINING THE STUDENT CLASS!!
class Student{
	public:

		void set_name(string n);
		string get_name();
		void set_surname(string sn);
		string get_surname();
		void set_id(int num);
		int get_id();
		int lectures[21];
		int counter=0;
		int enroll();
		int disenroll();
		int attendance=0;
		int isinClass=0;
		int temp_i,temp_j;
		//int Enter_class(classroom* clr);
	private:
		string name,surname;
		int id;
};

















#endif 
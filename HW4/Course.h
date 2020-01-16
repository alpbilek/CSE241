#ifndef COURSE_H_
#define COURSE_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Classroom.h"
using namespace std;
//DEFINING THE COURSE CLASS!!
class Course{
	public:
		void set_id(int num);
		int get_id();
		void set_name(string n);
		string get_name();
		void set_code(int c);
		int get_code();
		void set_credit(int cr);
		int get_credit();
		void set_total_hours(int th);
		int get_total_hours();
		void set_field(string f);
		string get_field();
		void set_isMandatory(int ism);
		int get_isMandatory();
		void set_isTaken(int ist);
		int get_isTaken();
		void set_day(int d);
		int get_day();
		void set_hour(int h);
		int get_hour();
		void set_classroom(Classroom clr);
		Classroom get_classroom();
		vector<Student> s_v;
		int counter=0;
		int enter(Student s);
		int quit();
		int in_room=0;
   	private:
	    int id;
	    string name;
	    int code;
	    int credit;
	    int total_hours;
	    string field;
	    int isMandatory;
	    int isTaken=0;
	    int day,hour;
	    Classroom classroom;

};














#endif 
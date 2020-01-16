#ifndef LECTURER_H_
#define LECTURER_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Course.h"
using namespace std;
//DEFINING THE LECTURER CLASS!!
class Lecturer{
	public:
		void proposeCourse(string name_p,int code_p,int credit_p,int total_hours_p,string field_p);
		void assignCourse(Course c);
		void set_name(string n);
		string get_name();
		void set_surname(string s);
		string get_surname();
		void set_title(string t);
		string get_title();
		void set_prof(string p);
		string get_prof();
		void set_id(int num);
		int get_id();
		//int get_course_counter();
		int course_counter=0;
		Course s[4];
		string proff[4];
		Course propose[3];
		int propose_counter=0;
	private:
		string name,surname,title,prof;
		int id;
			
		
};







#endif 
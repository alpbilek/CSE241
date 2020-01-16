#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lecturer.h"
#include "Course.h"
#include "Classroom.h"
using namespace std;
//IMPLEMENTING THE LECTURER'S MEMBER FUNTIONS!
void Lecturer::proposeCourse(string name_p,int code_p,int credit_p,int total_hours_p,string field_p){
	propose[propose_counter].set_name(name_p);
	propose[propose_counter].set_code(code_p);
	propose[propose_counter].set_credit(credit_p);
	propose[propose_counter].set_total_hours(total_hours_p);
	propose[propose_counter].set_field(field_p);
	propose_counter++;
}

void Lecturer::assignCourse(Course c){
	s[course_counter]=c;
	course_counter++;
	c.set_isTaken(1);
}

void Lecturer::set_name(string n){
	name=n;
}

string Lecturer::get_name(){return name;}

void Lecturer::set_surname(string s){
	surname=s;
}

string Lecturer::get_surname(){return surname;}

void Lecturer::set_title(string t){
	title=t;
}

string Lecturer::get_title(){return title;}

void Lecturer::set_prof(string p){
	prof=p;
}

string Lecturer::get_prof(){return prof;}

void Lecturer::set_id(int num){
	id=num;
}

int Lecturer::get_id(){return id;}

//int Lecturer::get_course_counter(){return course_counter;}

//-----
//student funcs!!!
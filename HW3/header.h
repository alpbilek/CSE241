#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

//DEFINING THE STRUCTS!
struct courses{
    int id;
    string name;
    int code;
    int credit;
    int total_hours;
    string field;
    int isMandatory;
    int isTaken=0;
    int day,hour;
    string classroom;
};
class Lecturer{
public:
	string name,surname,title,prof;
	int id;
	void proposeCourse(string name_p,int code_p,int credit_p,int total_hours_p,string field_p);
	void assignCourse(courses c);
	int course_counter=0;	
	courses s[3];
	string proff[4];
	int propose_counter=0;
	courses propose[3];
};
struct classrooms
{
    int id;
    string c_no;
    int student_inroom,capacity;
};
class Administrator{
	public:
	void asign(Lecturer* l,courses* c);
	void timetable(Lecturer* l,courses* c);
	void arrangeC(Lecturer* l,classrooms* cr);
};
Lecturer* initL();
courses* init();
classrooms* initc();

#endif /*HEADER_H_*/

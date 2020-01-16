#ifndef ADMIN_H_
#define ADMIN_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Classroom.h"
#include "Course.h"
#include "Lecturer.h"
using namespace std;

//DEFINING THE ADMIN CLASS!!
class Admin{
	public:
		Lecturer* init_Lecturer();
		Course* init_Course();
		Classroom* init_Classroom();
		void asign(Lecturer* l,Course* c);
		void timetable(Lecturer* l,Course* c);
		void arrangeC(Lecturer* l,Classroom* cr);
};;
#endif /*ADMİN_H_*/
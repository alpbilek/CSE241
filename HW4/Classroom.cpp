#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lecturer.h"
#include "Course.h"
#include "Classroom.h"
using namespace std;


//IMPLMENTING THE CLASSROOM CLASS'S GETTERS AND SETTERS!!
void Classroom::set_id(int num){
	id=num;
}

int Classroom::get_id(){return id;}

void Classroom::set_c_no(string c) {
	c_no=c;
}

string Classroom::get_c_no(){return c_no;}

void Classroom::set_student_inroom(int s){
	student_inroom=s;
}

int Classroom::get_student_inroom(){return student_inroom;}

void  Classroom::set_capacity(int c){
	capacity=c;
}

int Classroom::get_capacity(){return capacity;}
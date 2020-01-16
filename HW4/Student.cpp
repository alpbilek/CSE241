#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lecturer.h"
#include "Course.h"
#include "Classroom.h"
#include "Student.h"
using namespace std;
//IMPLEMENTING THE STUDENT CLASS'S GETTERS AND SETTERS!!
void Student::set_name(string n){
	name=n;
}

string Student::get_name(){return name;}

void Student::set_surname(string sn){
	surname=sn;
}
string Student::get_surname(){return surname;}

void Student::set_id(int num){
	id=num;
}
int Student::get_id(){return id;}
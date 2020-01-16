#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "Classroom.h"
#include "Course.h"
using namespace std;
//IMPLEMENTING THE COURSE CLASS'S MEMBER FUNTIONS!!
//ENTER FUNC.
int Course::enter(Student s){
	int is=0,temp;	
	s_v.resize(100);
	for(int i=0;i<counter;i++){
		if((s_v[i].get_id()==s.get_id())){
			is++;
			temp=i;
		}
	}
	if(is==0 ){
		s_v[counter]=s;
		s_v[counter].attendance++;
		temp=counter;
		in_room++;
		counter++;	
	}
	else if(is!=0){
		if(s.isinClass==0){
			s_v[temp].attendance++;
			in_room++;
		}
	}



	return in_room;
}//QUIT FUNC.
int Course::quit(){
	in_room--;
	return in_room;
}
void Course::set_id(int num){
	id=num;
}

int Course::get_id(){return id;}

void Course::set_name(string n){
	name=n;
}

string Course::get_name(){return name;}

void Course::set_code(int c){
	code=c;
}

int Course::get_code(){return code;}

void Course::set_credit(int cr){
	credit=cr;
}

int Course::get_credit(){return credit;}

void Course::set_total_hours(int th){
	total_hours=th;
}

int Course::get_total_hours(){return total_hours;}

void Course::set_field(string f){
	field=f;
}

string Course::get_field(){return field;}

void Course::set_isMandatory(int ism){
	isMandatory=ism;
}

int Course::get_isMandatory(){return isMandatory;}

void Course::set_isTaken(int ist){
	isTaken=ist;
}

int Course::get_isTaken(){return isTaken;}

void Course::set_day(int d){
	day=d;
}

int Course::get_day(){return day;}

void Course::set_hour(int h){
	hour=h;
}

int Course::get_hour(){return hour;}

void Course::set_classroom(Classroom clr){
	classroom=clr;
}

Classroom Course::get_classroom(){return classroom;}
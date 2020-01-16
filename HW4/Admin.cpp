#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lecturer.h"
#include "Course.h"
#include "Classroom.h"
#include "Admin.h"
using namespace std;

//READING FROM THE FILE FUNCTIONS AND SOME ARRANGEMENT FUNCTIONS!

Lecturer* Admin::init_Lecturer(){
	static Lecturer s[7];
	ifstream read;
	int counter=0,id_temp;
	string name_t,surname_t,prof_t,title_t;
	read.open("lecturers.txt");
	for(int i=0;i<7;i++){
		read>>id_temp>>name_t>>surname_t>>title_t>>prof_t;
		for(int j=0;j<prof_t.length();j++){
			if(prof_t[j]==','){
				prof_t[j]=' ';
				counter++;
			}
		}
		s[i].set_id(id_temp);
		s[i].set_name(name_t);
		s[i].set_surname(surname_t);
		s[i].set_title(title_t);
		istringstream some_stream(prof_t);
		some_stream>>s[i].proff[0]>>s[i].proff[1]>>s[i].proff[2]>>s[i].proff[3];
		counter=0;
	}
	read.close();
	return s;
}
Course* Admin::init_Course(){
	static Course s[18];
	ifstream read;
	read.open("courses_classrooms.txt");
	string useless,name_temp,field_temp;
	read>>useless;
	int id_temp,code_temp,credit_temp,total_hours_temp;
	for(int i=0;i<18;i++){
		read>>id_temp>>name_temp>>code_temp>>credit_temp>>total_hours_temp>>field_temp;
		s[i].set_id(id_temp);
		s[i].set_name(name_temp);
		s[i].set_code(code_temp);
		s[i].set_credit(credit_temp);
		s[i].set_total_hours(total_hours_temp);
		s[i].set_field(field_temp);
		s[i].set_isMandatory(1);
	}
	read.close();
	return s;
}
Classroom* Admin::init_Classroom(){
	static Course s[18];
	ifstream read;
	read.open("courses_classrooms.txt");
	string useless,name_temp,field_temp;
	read>>useless;
	int id_temp,code_temp,credit_temp,total_hours_temp;
	for(int i=0;i<18;i++){
		read>>id_temp>>name_temp>>code_temp>>credit_temp>>total_hours_temp>>field_temp;
		s[i].set_id(id_temp);
		s[i].set_name(name_temp);
		s[i].set_code(code_temp);
		s[i].set_credit(credit_temp);
		s[i].set_total_hours(total_hours_temp);
		s[i].set_field(field_temp);
		s[i].set_isMandatory(1);
	} 
	static Classroom sc[6];
	read>>useless;
	int id_clr,student_inroom_clr;
	string c_no_clr;
	for(int i=0;i<6;i++){
		read>>id_clr>>c_no_clr>>student_inroom_clr;
		sc[i].set_id(id_clr);
		sc[i].set_c_no(c_no_clr);
		sc[i].set_student_inroom(student_inroom_clr);
	}
	return sc;
}

void Admin::asign(Lecturer* l,Course* c){
	int temp1=0,temp2=0,temp3=0,temp4=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<18;j++){
			if((l[i].proff[0]==c[j].get_field()) &&(c[j].get_isTaken()==0) &&(l[i].course_counter<=3) &&(temp1==0)) {
				temp1++;
				l[i].assignCourse(c[j]);
			}
			else if((l[i].proff[1]==c[j].get_field()) &&(c[j].get_isTaken()==0) &&(l[i].course_counter<=3) &&(temp2==0)){
				temp2++;
				l[i].assignCourse(c[j]);
			}
			else if((l[i].proff[2]==c[j].get_field()) &&(c[j].get_isTaken()==0) &&(l[i].course_counter<=3) &&(temp3==0)){
				temp3++;
				l[i].assignCourse(c[j]);
			}
			else if(l[i].proff[3]==c[j].get_field() &&c[j].get_isTaken()==0 &&l[i].course_counter<=3 &&temp4==0){
				temp4++;
				l[i].assignCourse(c[j]);
			}
		}
		temp1=0;
		temp2=0;
		temp3=0;
		temp4=0;
	}
	int temp;
	string line,temp_l,name,prof;
	int lec_id,credit,code,total_h;
	for(int i=0;i<7;i++){
		if(!(l[i].propose_counter+l[i].course_counter>=3)){
			cout<<"NAME:"<<l[i].get_name()<<"("<<l[i].get_id()<<")"<<" PLEASE PROPOSE"<<3-l[i].course_counter<<" LECTURES"<<endl;
			getline(cin,line);
			istringstream some_stream(line);
			some_stream>>temp_l>>lec_id>>name>>code>>credit>>total_h>>prof;
			l[i].proposeCourse(name,code,credit,total_h,prof);
		}
		if(l[i].course_counter!=3 && l[i].course_counter>l[i].propose_counter){
			temp=3-l[i].course_counter;
			for(int j=0;j<temp;j++){
				l[i].assignCourse(l[i].propose[j]);
			}
		}
	}
}

void Admin::timetable(Lecturer* l,Course* c){
	int t=0,count=0;
	int array_day[5],array_hour[4];
	for(int f=0;f<4;f++){
		array_hour[f]=f;
	}
	for(int x=0;x<5;x++){
		array_day[x]=x;
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			l[i].s[j].set_day(array_day[t]);
			count++;
			if(count%5==0){
				t++;
			}
		}
	}
	t=0;
	count=0;
	for(int x=0;x<7;x++){
		for(int z=0;z<3;z++){
			l[x].s[z].set_hour(array_hour[t]);
			count++;
			t++;
			if(count%4==0){
				t=0;
			}
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			if(l[i].s[j].get_day()==0){
				if(l[i].s[j].get_hour()==0){
					cout<<l[i].s[j].get_name()<<":MON,8-10"<<endl;
				}
				else if(l[i].s[j].get_hour()==1){
					cout<<l[i].s[j].get_name()<<":MON,10-12"<<endl;
				}
				else if(l[i].s[j].get_hour()==2){
					cout<<l[i].s[j].get_name()<<":MON,12-14"<<endl;
				}
				else if(l[i].s[j].get_hour()==3){
					cout<<l[i].s[j].get_name()<<":MON,14-16"<<endl;
				}
			}
			else if(l[i].s[j].get_day()==1){
				if(l[i].s[j].get_hour()==0){
					cout<<l[i].s[j].get_name()<<":TUE,8-10"<<endl;
				}
				else if(l[i].s[j].get_hour()==1){
					cout<<l[i].s[j].get_name()<<":TUE,10-12"<<endl;
				}
				else if(l[i].s[j].get_hour()==2){
					cout<<l[i].s[j].get_name()<<":TUE,12-14"<<endl;
				}
				else if(l[i].s[j].get_hour()==3){
					cout<<l[i].s[j].get_name()<<":TUE,14-16"<<endl;
				}
			}
			else if(l[i].s [j].get_day()==2){
				if(l[i].s[j].get_hour()==0){
					cout<<l[i].s[j].get_name()<<":WED,8-10"<<endl;
				}
				else if(l[i].s[j].get_hour()==1){
					cout<<l[i].s[j].get_name()<<":WED,10-12"<<endl;
				}
				else if(l[i].s[j].get_hour()==2){
					cout<<l[i].s[j].get_name()<<":WED,12-14"<<endl;
				}
				else if(l[i].s[j].get_hour()==3){
					cout<<l[i].s[j].get_name()<<":WED,14-16"<<endl;
				}
			}
			else if(l[i].s[j].get_day()==3){
				if(l[i].s[j].get_hour()==0){
					cout<<l[i].s[j].get_name()<<":THURS,8-10"<<endl;
				}
				else if(l[i].s[j].get_hour()==1){
					cout<<l[i].s[j].get_name()<<":THURS,10-12"<<endl;
				}
				else if(l[i].s[j].get_hour()==2){
					cout<<l[i].s[j].get_name()<<":THURS,12-14"<<endl;
				}
				else if(l[i].s[j].get_hour()==3){
					cout<<l[i].s[j].get_name()<<":THURS,14-16"<<endl;
				}
			}
			else if(l[i].s[j].get_day()==4){
				if(l[i].s[j].get_hour()==0){
					cout<<l[i].s[j].get_name()<<":FRI,8-10"<<endl;
				}
				else if(l[i].s[j].get_hour()==1){
					cout<<l[i].s[j].get_name()<<":FRI,10-12"<<endl;
				}
				else if(l[i].s[j].get_hour()==2){
					cout<<l[i].s[j].get_name()<<":FRI,12-14"<<endl;
				}
				else if(l[i].s[j].get_hour()==3){
					cout<<l[i].s[j].get_name()<<":FRI,14-16"<<endl;
				}
			}
		}
	}

}

void Admin::arrangeC(Lecturer* l,Classroom* cr){
	int t=0;
	int count=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			l[i].s[j].set_classroom(cr[t]);
			count++;
			t++;
			if(count%6==0){
				t=0;
			}
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			cout<<"Courses name: "<<l[i].s[j].get_name()<<" Classroom: "<<l[i].s[j].get_classroom().get_id()<<endl;
		}
	}
}
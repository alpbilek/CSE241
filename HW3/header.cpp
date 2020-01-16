#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"
using namespace std;



void Lecturer::proposeCourse(string name_p,int code_p,int credit_p,int total_hours_p,string field_p){
	propose[propose_counter].name=name_p;
	propose[propose_counter].code=code_p;
	propose[propose_counter].credit=credit_p;
	propose[propose_counter].total_hours=total_hours_p;
	propose[propose_counter].field=field_p;
	propose_counter++;
}
void Lecturer::assignCourse(courses c){
	s[course_counter]=c;
	course_counter++;
	c.isTaken=1;
}



void  Administrator::asign(Lecturer* l,courses* c){
	int temp1=0,temp2=0,temp3=0,temp4=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<18;j++){
			if(l[i].proff[0]==c[j].field &&c[j].isTaken==0 &&l[i].course_counter<=3 &&temp1==0){
				temp1++;
				l[i].assignCourse(c[j]);
				
			}
			else if(l[i].proff[1]==c[j].field && c[j].isTaken==0 &&l[i].course_counter<=3 &&temp2==0){
				temp2++;
				l[i].assignCourse(c[j]);
				
			}
			else if(l[i].proff[2]==c[j].field && c[j].isTaken==0 &&l[i].course_counter<=3 &&temp3==0){
				temp3++;
				l[i].assignCourse(c[j]);
				
			}
			else if(l[i].proff[3]==c[j].field && c[j].isTaken==0 &&l[i].course_counter<=3 &&temp4==0){
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
			cout<<"NAME:"<<l[i].name<<" PLEASE PROPOSE"<<3-l[i].course_counter<<" LECTURES"<<endl;
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
void Administrator::arrangeC(Lecturer* l,classrooms* c){
	int t=0;
	int count=0;
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			l[i].s[j].classroom=c[t].c_no;
			count++;
			t++;
			if(count%6==0){
				t=0;
			}
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			cout<<"Courses name: "<<l[i].s[j].name<<" Classroom: "<<l[i].s[j].classroom<<endl;
		}
	}
}

//THIS FUNCTION FOR THE AUTOMATIC TIMETABLE!
void Administrator::timetable(Lecturer* l,courses* c){
	int t=0,count=0;
	int array_day[5],array_hour[5];
	for(int f=0;f<5;f++){
		array_day[f]=f;
		array_hour[f]=f;
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			l[i].s[j].day=array_day[t];
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
			l[x].s[z].hour=array_hour[t];
			count++;
			t++;
			if(count%5==0){
				t=0;
			}
		}
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<3;j++){
			if(l[i].s[j].day==0){
				if(l[i].s[j].hour==0){
					cout<<l[i].s[j].name<<":MON,8-10"<<endl;
				}
				else if(l[i].s[j].hour==1){
					cout<<l[i].s[j].name<<":MON,10-12"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":MON,12-14"<<endl;
				}
				else if(l[i].s[j].hour==3){
					cout<<l[i].s[j].name<<":MON,14-16"<<endl;
				}
				else if(l[i].s[j].hour==4){
					cout<<l[i].s[j].name<<":MON,16-18"<<endl;
				}
			}
			else if(l[i].s[j].day==1){
				if(l[i].s[j].hour==0){
					cout<<l[i].s[j].name<<":TUE,8-10"<<endl;
				}
				else if(l[i].s[j].hour==1){
					cout<<l[i].s[j].name<<":TUE,10-12"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":TUE,12-14"<<endl;
				}
				else if(l[i].s[j].hour==3){
					cout<<l[i].s[j].name<<":TUE,14-16"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":TUE,16-18"<<endl;
				}
			}
			else if(l[i].s[j].day==2){
				if(l[i].s[j].hour==0){
					cout<<l[i].s[j].name<<":WED,8-10"<<endl;
				}
				else if(l[i].s[j].hour==1){
					cout<<l[i].s[j].name<<":WED,10-12"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":WED,12-14"<<endl;
				}
				else if(l[i].s[j].hour==3){
					cout<<l[i].s[j].name<<":WED,14-16"<<endl;
				}
				else if(l[i].s[j].hour==4){
					cout<<l[i].s[j].name<<":WED,16-18"<<endl;
				}
			}
			else if(l[i].s[j].day==3){
				if(l[i].s[j].hour==0){
					cout<<l[i].s[j].name<<":THURS,8-10"<<endl;
				}
				else if(l[i].s[j].hour==1){
					cout<<l[i].s[j].name<<":THURS,10-12"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":THURS,12-14"<<endl;
				}
				else if(l[i].s[j].hour==3){
					cout<<l[i].s[j].name<<":THURS,14-16"<<endl;
				}
				else if(l[i].s[j].hour==4){
					cout<<l[i].s[j].name<<":THURS,16-18"<<endl;
				}
			}
			else if(l[i].s[j].day==4){
				if(l[i].s[j].hour==0){
					cout<<l[i].s[j].name<<":FRI,8-10"<<endl;
				}
				else if(l[i].s[j].hour==1){
					cout<<l[i].s[j].name<<":FRI,10-12"<<endl;
				}
				else if(l[i].s[j].hour==2){
					cout<<l[i].s[j].name<<":FRI,12-14"<<endl;
				}
				else if(l[i].s[j].hour==3){
					cout<<l[i].s[j].name<<":FRI,14-16"<<endl;
				}
				else if(l[i].s[j].hour==4){
					cout<<l[i].s[j].name<<":FRI,16-18"<<endl;
				}
			}
		}
	}
}





//IMPLEMENTING THE  INIT FUCNTIONS FOR THE COURSES,CLASSROOMS AND LECTURERS!
courses* init(){
    static courses s[18];
    ifstream read;
    read.open("courses_classrooms.txt");
    string useless;
    read>>useless;
    for(int i=0;i<18;i++){
        read>>s[i].id>>s[i].name>>s[i].code>>s[i].credit>>s[i].total_hours>>s[i].field;
        s[i].isMandatory=1;
    }
    read.close();
    return s;
} 

classrooms* initc(){
    static courses s[18];
    ifstream read;
    read.open("courses_classrooms.txt");
    string useless;
    read>>useless;
    for(int i=0;i<18;i++){
        read>>s[i].id>>s[i].name>>s[i].code>>s[i].credit>>s[i].total_hours>>s[i].field;
    }
    static classrooms sc[6];
    read>>useless;
    for(int i=0;i<6;i++){
        read>>sc[i].id>>sc[i].c_no>>sc[i].student_inroom;
    }
    return sc;
}

Lecturer* initL(){
	static Lecturer s[7];
	ifstream read;
	int counter=0;
	read.open("lecturers.txt");
	for(int i=0;i<7;i++){
		read>>s[i].id>>s[i].name>>s[i].surname>>s[i].title>>s[i].prof;
		for(int j=0;j<s[i].prof.length();j++){
			if(s[i].prof[j]==','){
				s[i].prof[j]=' ';
				counter++;
			}
		}
		istringstream some_stream(s[i].prof);
		some_stream>>s[i].proff[0]>>s[i].proff[1]>>s[i].proff[2]>>s[i].proff[3];
		for(int y=0;y<counter+1;y++){
			cout<<s[i].proff[y]<<" ";
		}
		cout<<endl;
		counter=0;
	}
	read.close();
	return s;
}

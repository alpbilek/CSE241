#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Lecturer.h"
#include "Course.h"
#include "Classroom.h"
#include <vector>
#include "Student.h"
#include "Admin.h"
using namespace std;

namespace aebns{
	int  finder_day(int num){
		num=num-1;
		int temp=num/2;
		int temp_day,temp_hour;
		temp_day=temp/4;
		temp_hour=temp-temp_day*4;
		return temp_day;
	}
	int finder_hour(int num){
		num=num-1;
		int temp=num/2;
		int temp_day,temp_hour;
		temp_day=temp/4;
		temp_hour=temp-temp_day*4;
		return temp_hour;
	}
}
int main(){
	Admin a;
	Lecturer* temp;
	temp=a.init_Lecturer();
	Course* temp_C=a.init_Course();
	Classroom* temp_clr=a.init_Classroom();
	a.asign(temp,temp_C);
	a.timetable(temp,temp_C);
	a.arrangeC(temp,temp_clr);
	vector<Student> v;
	v.resize(100);
	int temp_x,temp_y;
	int flag=0,counter=0;
	int std_id,clr_id,num,c_id,level,temp_std_id,temp_day,temp_hour,temp_a,il,jl;
	string line,temp_line,temp2,std_name;

	//MENU FOR THE USER!!
	while(flag==0){
		getline(cin,line);
		istringstream some_stream(line);
		some_stream>>temp_line;
		if(temp_line=="-enter"){
			istringstream some_stream(line);
			some_stream>>temp2>>std_id>>clr_id>>num;
			temp_day=aebns::finder_day(num);
			temp_hour=aebns::finder_hour(num);
			int is=0;
			for(int i=0;i<v.size();i++){
				if(std_id==v[i].get_id()){
					temp_std_id=i;
					is++;
				}
			}
			if(is==0){
				cout<<"BLOCK:THERE IS NO STUDENT ID LIKE "<<std_id<<endl;
			}
			if(v[temp_std_id].isinClass==1){
				cout<<"BLOCK:YOU ARE ALREADY IN A CLASS!FIRST YOU SHOULD \"QUIT\" FROM YOUR CLASS"<<endl;
			}
			else{
			int ist=0;
				for(int i=0;i<7;i++){
					for(int j=0;j<3;j++){
						if(temp[i].s[j].get_classroom().get_id()==clr_id){	
							if(temp[i].s[j].get_day()==temp_day && temp[i].s[j].get_hour()==temp_hour){
							temp_a=temp[i].s[j].enter(v[temp_std_id]);
							v[temp_std_id].isinClass=1;
							//temp[i].s[j].counter++;
							temp_x=i;
							temp_y=j;
							cout<<"student in room:"<<temp_a<<endl;
							ist++;
							}
						}
					}
				}
				if(ist==0){
					cout<<"BLOCK:THERE IS NO CLASSROOM LIKE "<<clr_id<<endl;		
				}
			}
		}
		else if(temp_line=="-attendance"){
			istringstream some_stream(line);
			some_stream>>temp2>>c_id;
			for(int i=0;i<7;i++){
				for(int j=0;j<3;j++){
					if(temp[i].s[j].get_id()==c_id){
						for(int t=0;t<temp[i].s[j].counter;t++){
							cout<<temp[i].s[j].s_v[t].get_name()<<" "<<temp[i].s[j].s_v[t].attendance<<" ";
						}
					}
				}
			}
		}
		else if(temp_line=="-quit"){
			istringstream some_stream(line);
			some_stream>>temp2>>std_id;
			int temp_std_id_q;
			int temp_ir;
			int is=0;
			for(int i=0;i<v.size();i++){
				if(std_id==v[i].get_id()){
					temp_std_id_q=i;
					cout<<v[temp_std_id_q].get_name()<<endl;
					is++;
				}

			}
			if(is==0){
				cout<<"BLOCK:THERE IS NO STUDENT ID LIKE "<<std_id<<endl;
			}
			else{
				temp_ir=temp[temp_x].s[temp_y].quit();
				cout<<"Student in room:"<<temp_ir<<endl;
				v[temp_std_id_q].isinClass=0;
			}
		}
		else if(temp_line=="exit"){flag++;}
		else if(temp_line=="-ns"){
			istringstream some_stream(line);
			some_stream>>temp2>>std_name>>std_id>>level;
			v[counter].set_id(std_id);
			v[counter].set_name(std_name);
			counter++;
		}
		else{
			cout<<"THERE IS NO KEYWORD LIKE "<<temp_line<<endl;
		}
	}
	return 0;
}
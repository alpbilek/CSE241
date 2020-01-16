
/*
#HW3
161044049
ALP EMİR BİLEK
*/





//INCLUDING THE LIBRARIES!
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "header.h"
using namespace std;



int main(){
  	courses* temp=init();
    classrooms* tempc=initc();   
    Lecturer* tempL=initL();
    //MENU FOR THE USER'S SELECTIONS
    int flag=0,at,tr,lec_id,code,credit,total_h,course_id;
	string line,temp_line,temp2,other,name,prof;
	Administrator a;
	while(flag==0){
		getline(cin,line);
		if(line=="-assign"){
			a.asign(tempL,temp);
			line=".";
		}
		else if(line=="-arrangeC"){
			a.arrangeC(tempL,tempc);
			line=".";
		}
		else if(line=="-timetable"){
			a.timetable(tempL,temp);
			line=".";
		}
		
		istringstream some_stream(line);
		some_stream>>temp_line;
		//propose proccess!
		if(temp_line=="-propose"){
			istringstream some_stream(line);
			some_stream>>temp2>>lec_id>>name>>code>>credit>>total_h>>prof;
			for(int p=0;p<7;p++){
				if(lec_id==tempL[p].id){
					tempL[p].proposeCourse(name,code,credit,total_h,prof);
				}
			}
		}
		//assign process
		else if(temp_line=="-assign"){
			int temp_course_index;
			istringstream some_stream(line);
			some_stream>>temp2>>lec_id>>course_id;
			for(int ci=0;ci<18;ci++){
				if(course_id==temp[ci].id){
					temp_course_index=ci;
				}
			}
			for(int li=0;li<7;li++){
				if(lec_id==tempL[li].id){
					tempL[li].assignCourse(temp[temp_course_index]);
					cout<<tempL[li].s[tempL[li].course_counter-1].name<<endl;
				}
			}
			temp[temp_course_index].isTaken=1;
		}
		else if(temp_line=="-arrangeC"){
			istringstream some_stream(line);
			some_stream>>temp2>>at>>tr;
			cout<<at<<" "<<tr<<endl;
		}
		else if(temp_line=="-timetable"){
			istringstream some_stream(line);
			some_stream>>temp2>>at>>tr;
			cout<<at<<" "<<tr<<endl;
		}	
		else if(temp_line=="exit"){
			flag++;
		}
	}
    return 0;
}




#include "Lecturer.h"
#include "UNI.h"
using namespace std;
int Lecturer::seeSuccessfulStudent(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=10;
	u.contribution+=0;
	actions[counter]="Sees Successful Students";
	action="Sees Successful Students";
	counter++;
}


int Lecturer::makePublish(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=2;
	u.contribution+=5;	
	actions[counter]="Makes publish";
	action="Makes publish";
	counter++;
}
//Lecturer funcs!!!
//-----
int Lecturer::giveHW(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=2;
	u.contribution+=1;
	actions[counter]="Gives Homework";
	action="Gives Homework";
	counter++;
}
	
int Lecturer::giveLesson(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=1;
	u.contribution+=5;
	actions[counter]="Gives Lessons";
	action="Gives Lessons";
	counter++;
}
//WORK FUNCTION IS A VIRTUAL FUNCTIONS FROM EMPLOYEE CLASS!
//GETTING A PARAMETER FOR THE LECTURER'S FUNCTIONS
//ALSO GETTING ANOTHER PARAMETER FOR THE CONTRIBUTION!
void Lecturer::work(int num,UNI& u){
	if(num==1){
		seeSuccessfulStudent(u);
	}
	else if(num==2){
		giveHW(u);
	}
	else if(num==3){
		giveLesson(u);
	}
	else if(num==4){
		makePublish(u);
	}
}

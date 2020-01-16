#include "Secretary.h"
#include "UNI.h"
using namespace std;
int Secretary::manageProcess(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=1;
	u.contribution+=2;
	actions[counter]="managesProcess";
	action="managesProcess";
	counter++;
}
int Secretary::receivePetition(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=1;
	u.contribution-=1;
	actions[counter]="Receives Petition";
	action="Receives Petition";
	counter++;
}
//WORK FUNCTION IS A VIRTUAL FUNCTIONS FROM EMPLOYEE CLASS!
//GETTING A PARAMETER FOR THE SECRETARY'S FUNCTIONS!

void Secretary::work(int num,UNI& u){
	if(num==1){
		receivePetition(u);
		
	}
	else if(num==2){
		manageProcess(u);

	}
}
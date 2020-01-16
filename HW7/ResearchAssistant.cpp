#include "ResearchAssistant.h"
#include "UNI.h"
using namespace std;

int ResearchAssistant::research(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=3;
	u.contribution+=4;
	actions[counter]="researches";
	action="researches";
	counter++;
}

int ResearchAssistant::readHW(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=3;
	u.contribution+=2;
	actions[counter]="reads Homework";
	action="reads Homework";
	counter++;
}
//WORK FUNCTION IS A VIRTUAL FUNCTIONS FROM EMPLOYEE CLASS!
void ResearchAssistant::work(int num,UNI& u){
	if(num==1){
		research(u);
		
	}
	else if(num==2){	
		readHW(u);
		
	}

}
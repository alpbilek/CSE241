#include "ResearchAssistant.h"
#include "UNI.h"
using namespace std;

int ResearchAssistant::research(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=3;
	u.contribution+=4;
	action="researches";
}

int ResearchAssistant::readHW(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=3;
	u.contribution+=2;
	action="reads Homework";
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
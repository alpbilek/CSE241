#include "Employee.h"
#include "UNI.h"
using namespace std;
//EMPLOYEE FUNCTIONS!!!!
//------------
//SETTER AND GETTER FUNCTIONS FOR THE EMPLOYEE CLASS!!
void Employee::set_pid(int p){
	pid=p;
}

int Employee::get_pid(){return pid;}

void Employee::set_name(string n){
	name=n;
}

string Employee::get_name(){return name;}

void Employee::set_surname(string sn){
	surname=sn;
}

string Employee::get_surname(){return surname;}

void Employee::set_keyword(string kyw){
	keyword=kyw;
}

string Employee::get_keyword(){return keyword;}
//DRINKTEA FUNCTION!
int Employee::drinkTea(UNI& u){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=5;
	u.contribution-=2;
	actions[counter]="drinks tea";
	action="drinks tea";
	counter++;
}
//SUBMITPETITION FUNCTION!!
int Employee::submitPetition(UNI& u){
	happiness+=1;
	u.contribution-=2;
	actions[counter]="submits Petition";
	action="submits Petition";
	counter++;
}
#include "Officer.h"
#include "UNI.h"
using namespace std;
int Officer::makeDoc(UNI& u){
    happiness-=2;
    u.contribution+=3;
    actions[counter]="makes doc";
    action="makes doc";
   	counter++;
}
//WORK FUNCTION IS A VIRTUAL FUNCTIONS FROM EMPLOYEE CLASS!
void Officer::work(int num,UNI& u){
	makeDoc(u);
}
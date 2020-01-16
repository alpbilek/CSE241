/*
#HW07
ALP EMİR BİLEK 
161044049
*/
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "UNI.h"
#include "Secretary.h"
#include "Officer.h"
#include "ResearchAssistant.h"
#include "Lecturer.h"
#include <string>
#include "YOK.h"
using namespace std;
//MENU FOR THE USER'S SELECTION!
int main(){
	UNI GTU;
	int choice;
	cout<<"------MENU-----"<<endl;
	cout<<"1)Liberal University"<<endl;
	cout<<"2)Communist University"<<endl;
	cout<<"3)Capitalist University"<<endl;
	cin>>choice;
	switch(choice){
		case 1:{
			LibUNI y;
			cout<<"I see that there is an oppurtunity for being Liberal in the university.So I am Liberal"<<endl;
			y.init(GTU);
			break;
		}	
		case 2:{
			ComUNI y;
						cout<<"I see that there is an oppurtunity for being Communist in the university.So I am Communist"<<endl;
			y.init(GTU);
			break;
		}
		case 3:{
			cout<<"I see that there is an oppurtunity for being Capitalist in the university.So I am Capitalist"<<endl;
			CapUNI y;
			y.init(GTU);
			break;
		}
		
		default:{
			cout<<"Thats a wrong choice please try again:"<<endl;
			cin>>choice;			
			break;
		}
	}
	return 0;
}
#include "YOK.h"

using namespace std;
//INITILIAZING FUNCTION!
//FINDING THE BEST EMPLOYEE FOR THE LIBERAL!!!
Employee* sort(Employee** t){
	    Employee* temp;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(t[j]->happiness<t[j+1]->happiness){
                temp=t[j+1];
                t[j+1]=t[j];
                t[j]=temp;
            }
        }
    }
    return t[0];
}
//INITIALIZE FUNCTION FOR THE COMMUNIST!!
void ComUNI::init(UNI& u){
	//CREATING A DOUBLE POINTER BECAUSE I MADE THE EMPLOYEE CLASS PURE!!
	static Employee* arr[10];
	ifstream read;
	string bos;
	//READING FROM THE FILE!
	read.open("personnellist.txt");
	//SOME TEMPORARY OBJECTS!!
	Secretary sc;
	Officer of;
	Lecturer lc;
	ResearchAssistant ra;
	string name,surname;
	srand(time(NULL));
	for(int i=0;i<10;i++){
		read>>name>>surname>>bos;
		//RANDOMIZING THE EMPLOYEE'S JOB!
		int random=rand()%4;
		//IF RANDOM IS 0 IT MEANS,EMPLOYEE WILL BE A LECTURER!
		if(random==0){
			lc.set_name(name);
			lc.set_surname(surname);
			lc.set_keyword("Lecturer");
			arr[i]=&lc;
		}
		//IF RANDOM IS 1 IT MEANS,EMPLOYEE WILL BE A RESEARCHASSISTANT!
		else if(random==1){
			ra.set_name(name);
			ra.set_surname(surname);
			ra.set_keyword("ResearchAssistant");
			arr[i]=&ra;
		}
		//IF RANDOM IS 2 IT MEANS,EMPLOYEE WILL BE A SECRETARY!
		else if(random==2){
			sc.set_name(name);
			sc.set_surname(surname);
			sc.set_keyword("Secretary");
			arr[i]=&sc;
			
		}
		//IF RANDOM IS 3 IT MEANS,EMPLOYEE WILL BE OFFICER!
		else if(random==3){
			of.set_name(name);
			of.set_surname(surname);
			of.set_keyword("Officer");
			arr[i]=&of;
		}
	}
	//50 ACTIONS!!!
	int control=0;
	int emp_index;
	int actions;
	int rand_emp,rand_emp_in;
	while(control<50){
		//RANDOMIZING FOR THE WHICH EMPLOYEE WILL EXECUTE AN ACTION!!
		emp_index=rand()%10;
		rand_emp=rand()%2;
		//RANDOMIIZING THE ACTION IS GOING TO BE NORMAL EMPLOYEE FUNCS OR THE INHERITED FUNCTIONS!
		if(rand_emp==0){
			rand_emp_in=rand()%2;
			if(rand_emp_in==0){
				arr[emp_index]->drinkTea(u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" drinks tea "<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else{
				arr[emp_index]->submitPetition(u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" submits petition "<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
		else if(rand_emp==1){
			//CHECKING THE EMPLOYEE'S KEYWORD!
			//ACCORDING TO KEYWORDS EXECUTING THE FUNCTIONS!
			if(arr[emp_index]->get_keyword()=="Lecturer"){
				actions=rand()%4 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="ResearchAssistant"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Secretary"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Officer"){
				actions=0;
				arr[emp_index]->work(actions,u);
				control++;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
	}

}
//INITIALIZE FUNCTIONS FOR THE LIBERAL!
void LibUNI::init(UNI& u){
	//CREATING A DOUBLE POINTER BECAUSE I MADE THE EMPLOYEE CLASS PURE!!
	static Employee* arr[10];
	ifstream read;
	string bos;
	//READING FROM THE FILE!
	read.open("personnellist.txt");
	//SOME TEMPORARY OBJECTS!!
	Secretary sc;
	Officer of;
	Lecturer lc;
	ResearchAssistant ra;
	string name,surname;
	srand(time(NULL));
	for(int i=0;i<10;i++){
		read>>name>>surname>>bos;
		//RANDOMIZING THE EMPLOYEE'S JOB!
		int random=rand()%4;
		//IF RANDOM IS 0 IT MEANS,EMPLOYEE WILL BE A LECTURER!
		if(random==0){
			lc.set_name(name);
			lc.set_surname(surname);
			lc.set_keyword("Lecturer");
			arr[i]=&lc;
			cout<<"GTU requests a Lecturer."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
		}
		//IF RANDOM IS 1 IT MEANS,EMPLOYEE WILL BE A RESEARCHASSISTANT!
		else if(random==1){
			ra.set_name(name);
			ra.set_surname(surname);
			ra.set_keyword("ResearchAssistant");
			arr[i]=&ra;
			cout<<"GTU requests a ResearchAssistant."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
		}
		//IF RANDOM IS 2 IT MEANS,EMPLOYEE WILL BE A SECRETARY!
		else if(random==2){
			sc.set_name(name);
			sc.set_surname(surname);
			sc.set_keyword("Secretary");
			arr[i]=&sc;
			cout<<"GTU requests a Secretary."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			
		}
		//IF RANDOM IS 3 IT MEANS,EMPLOYEE WILL BE OFFICER!
		else if(random==3){
			of.set_name(name);
			of.set_surname(surname);
			of.set_keyword("Officer");
			arr[i]=&of;
			cout<<"GTU requests a Officer."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;

		}
	}
	//50 ACTIONS!!!
	int control=0;
	int emp_index;
	int actions;
	int rand_emp,rand_emp_in;
	while(control<50){
		//RANDOMIZING FOR THE WHICH EMPLOYEE WILL EXECUTE AN ACTION!!
		emp_index=rand()%10;
		rand_emp=rand()%2;
		//RANDOMIIZING THE ACTION IS GOING TO BE NORMAL EMPLOYEE FUNCS OR THE INHERITED FUNCTIONS!
		if(rand_emp==0){
			rand_emp_in=rand()%2;
			if(rand_emp_in==0){
				arr[emp_index]->drinkTea(u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" drinks tea "<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else{
				arr[emp_index]->submitPetition(u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" submits petition "<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
		else if(rand_emp==1){
			//CHECKING THE EMPLOYEE'S KEYWORD!
			//ACCORDING TO KEYWORDS EXECUTING THE FUNCTIONS!
			if(arr[emp_index]->get_keyword()=="Lecturer"){
				actions=rand()%4 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="ResearchAssistant"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Secretary"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Officer"){
				actions=0;
				arr[emp_index]->work(actions,u);
				control++;
				//cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
	}
	//FINDING THE BEST EMPLOYEE AND PRINTING THE HIS/HER ACTIONS!!
	Employee* best=sort(arr);
	for(int i=0;i<best->counter;i++){
		cout<<"University has "<<best->actions[i]<<endl;
	}
	cout<<"After all my name is "<<best->get_name()<<" money is "<<best->happiness<<" happines is "<<best->happiness<<" uni's contribution is "<<u.contribution<<endl;
}

//INITIALIZE FUNCTION FOR THE CAPITALIST!!
void CapUNI::init(UNI& u){
	//CREATING A DOUBLE POINTER BECAUSE I MADE THE EMPLOYEE CLASS PURE!!
	static Employee* arr[10];
	ifstream read;
	string	 bos;
	//READING FROM THE FILE!
	read.open("personnellist.txt");
	//SOME TEMPORARY OBJECTS!!
	Secretary sc;
	Officer of;
	Lecturer lc;
	ResearchAssistant ra;
	string name,surname;
	srand(time(NULL));
	for(int i=0;i<10;i++){
		read>>name>>surname>>bos;
		//RANDOMIZING THE EMPLOYEE'S JOB!
		int random=rand()%4;
		//IF RANDOM IS 0 IT MEANS,EMPLOYEE WILL BE A LECTURER!
		if(random==0){
			lc.set_name(name);
			lc.set_surname(surname);
			lc.set_keyword("Lecturer");
			arr[i]=&lc;
			cout<<"GTU requests a Lecturer."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
		}
		//IF RANDOM IS 1 IT MEANS,EMPLOYEE WILL BE A RESEARCHASSISTANT!
		else if(random==1){
			ra.set_name(name);
			ra.set_surname(surname);
			ra.set_keyword("ResearchAssistant");
			arr[i]=&ra;
			cout<<"GTU requests a ResearchAssistant."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
		}
		//IF RANDOM IS 2 IT MEANS,EMPLOYEE WILL BE A SECRETARY!
		else if(random==2){
			sc.set_name(name);
			sc.set_surname(surname);
			sc.set_keyword("Secretary");
			arr[i]=&sc;
			cout<<"GTU requests a Secretary."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			
		}
		//IF RANDOM IS 3 IT MEANS,EMPLOYEE WILL BE OFFICER!
		else if(random==3){
			of.set_name(name);
			of.set_surname(surname);
			of.set_keyword("Officer");
			arr[i]=&of;
			cout<<"GTU requests a Officer."<<endl;
			cout<<"YOK give job to "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;
			cout<<"GTU employs "<<arr[i]->get_name()<<" "<<arr[i]->get_surname();
			cout<<"as "<<arr[i]->get_keyword()<<endl;

		}
	}
	//50 ACTIONS!!!
	int control=0;
	int emp_index;
	int actions;
	int rand_emp,rand_emp_in;
	while(control<50){
		//RANDOMIZING FOR THE WHICH EMPLOYEE WILL EXECUTE AN ACTION!!
		emp_index=rand()%10;
		rand_emp=rand()%2;
		//RANDOMIIZING THE ACTION IS GOING TO BE NORMAL EMPLOYEE FUNCS OR THE INHERITED FUNCTIONS!
		if(rand_emp==0){
			rand_emp_in=rand()%2;
			if(rand_emp_in==0){
				arr[emp_index]->drinkTea(u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" drinks tea "<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else{
				arr[emp_index]->submitPetition(u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" submits petition "<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
		else if(rand_emp==1){
			//CHECKING THE EMPLOYEE'S KEYWORD!
			//ACCORDING TO KEYWORDS EXECUTING THE FUNCTIONS!
			if(arr[emp_index]->get_keyword()=="Lecturer"){
				actions=rand()%4 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="ResearchAssistant"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Secretary"){
				actions=rand()%2 + 1;
				arr[emp_index]->work(actions,u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
			else if(arr[emp_index]->get_keyword()=="Officer"){
				actions=0;
				arr[emp_index]->work(actions,u);
				control++;
				double money=(arr[emp_index]->happiness*3/2)-1;
				cout<<control<<")"<<arr[emp_index]->get_name()<<" "<<arr[emp_index]->action<<" happiness:"<<arr[emp_index]->happiness<<" money:"<<money<<" contribution of uni is:"<<u.contribution<<endl;
			}
		}
	}
}
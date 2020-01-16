//HOCAM MAKEFILE YAPMAYA COK UGRASTIM FAKAT SUREKLI SACMA HATALAR ALDIM BUNDAN DOLAYI HEADERSIZ SADECE MAIN DOSYASINI GONDERIYORUM!!!!









#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//ENUM FOR THE ACTIONS!!
enum func{makeDoc,drinkTea,research,giveLesson,seeSuccessfulStudent,makePublish,manageProcess,giveHW,readHW,receivePetition,submitPetition};
int cont=0;

//DEFINING THE EMPLOYEE CLASS(BASE CLASS)!!
class Employee{
	public:
		void set_pid(int p);
		int get_pid();
		void set_name(string n);
		string get_name();
		void set_surname(string sn);
		string get_surname();
		void set_keyword(string kyw);
		string get_keyword();
		int happiness=0;
		int drinkTea();
		int submitPetition();
	private:
		int pid;
		string name,surname,keyword;
};
class UNI{
	public:
		Employee* init_employees();
		//int contribution=0;
		int* array_arr();
};
//DEFINING THE DERIVED CLASSES,ACADEMIC PERSONNEL CLASS!!
class AcademicPersonnel :public Employee
{
public:
	int seeSuccessfulStudent();
	int makePublish();
};
//DEFINING THE DERIVED CLASSES,ADMINISTRATIVE PERSONNEL CLASS!!
class AdministrativePersonnel:public Employee
{
	public:
	int manageProcess();
};
//DEFINING THE DERIVED CLASSES,LECTURER CLASS!!
class Lecturer:public AcademicPersonnel
{
	public:
	int giveHW();
	int giveLesson();
};
//DEFINING THE DERIVED CLASSES,RESEARCH ASSISTANT CLASS!!
class ResearchAssistant:public AcademicPersonnel
{
	public:
	int research();
	int readHW();
};
//DEFINING THE DERIVED CLASSES,SECRETARY CLASS!!
class Secretary:public AdministrativePersonnel
{
	public:
	int receivePetition();
};
//DEFINING THE DERIVED CLASSES,OFFICER CLASS!!
class Officer:public AdministrativePersonnel
{
	public:
	int makeDoc();
};

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
int Employee::drinkTea(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=5;
	cont-=2;
	return happiness;
}
//SUBMITPETITION FUNCTION!!
int Employee::submitPetition(){
	happiness+=1;
	cont-=2;
}


//UNI FUNCTIONS!!!
//------------
//MAKING RANDOM NUMBER FUNCTION!!
int* UNI::array_arr(){
	static int arr[10];
    int temp;
    srand(time(NULL));
    arr[0]=rand()%25;
    for(int i=1;i<10;i++){
        temp=rand()%25;
        for(int j=0;j<i;j++){
            if(arr[j]==temp){
                i--;
                break;
            }
            else {
                arr[i]=temp;
            }
        }
    }


	return arr;

}

//READING FROM THE FILE AND INITIALIZE!!
Employee* UNI::init_employees(){
	static Employee temp[25];
	static Employee e[10];
	ifstream read;
	string kyw,n,sn;
	Lecturer lc;
	Officer of;
	ResearchAssistant ra;
	Secretary sc;
	read.open("personnellist.txt");
	for(int i=0;i<25;i++){
		read>>kyw>>n>>sn;

//READING FROM THE FILE AND INITIALIZING THE DATAS TO EMPLOYEE ARRAY ACCORDING TO THEIR KEYWORDS!!
		if(kyw=="Lecturer"){
			lc.set_keyword(kyw);
			lc.set_name(n);
			lc.set_surname(sn);
			temp[i]=lc;
		}
		else if(kyw=="Officer"){
			of.set_keyword(kyw);
			of.set_name(n);
			of.set_surname(sn);
			temp[i]=of;
		}
		else if(kyw=="Secretary"){
			sc.set_keyword(kyw);
			sc.set_name(n);
			sc.set_surname(sn);
			temp[i]=sc;
		}
		else if(kyw=="ResearchAssistant"){
			ra.set_keyword(kyw);
			ra.set_name(n);
			ra.set_surname(sn);
			temp[i]=ra;
		}
	}
	int* arr=array_arr();
	for(int i=0;i<10;i++){
		e[i]=temp[arr[i]];
	}

	return e;
}


//ACADEMICPERSONNEL FUNCS!!!
//-----------------
int AcademicPersonnel::seeSuccessfulStudent(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=10;
	cont+=0;
}

int AcademicPersonnel::makePublish(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=2;
	cont+=5;	
}

//AdministrativePersonnel funcs!!!
//----------
int AdministrativePersonnel::manageProcess(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=1;
	cont+=2;
}

//Lecturer funcs!!!
//-----
int Lecturer::giveHW(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=2;
	cont+=1;
}

int Lecturer::giveLesson(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=1;
	cont+=5;
}


//ResearchAssistant funcs!!
//-----
int ResearchAssistant::research(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness+=3;
	cont+=4;
}

int ResearchAssistant::readHW(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=3;
	cont+=2;
}

//Sectetary Funcs!!
//-------

int Secretary::receivePetition(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=1;
	cont-=1;
}

//Officer funcs!!
//-----
int Officer::makeDoc(){
//INCREMENTING OR DECREMENTING ACCORDING TO FUNCTIONS TYPE!!!
	happiness-=2;
	cont+=3;
}
void processer(){
//THIS FUNC DOING THE MAIN JOB ACTUALLY!!
//MAKING RANDOM NUMS VIA RANDOM FUNC.
//AND CHECKING THE DATAS WITH THE EMPLOYEE ARRAY!
//FINALLY PRINTING THE ACTION'S RESULTS!!
	UNI v;
	Employee* temp=v.init_employees();
	int emp_index;
	int func_index;
	int counter=0;
	srand(time(NULL));
	while(counter<50){
		emp_index=rand()%10;
		func_index=rand()%11;
		if(func_index==makeDoc){
			if(temp[emp_index].get_keyword()=="Officer"){
				Officer temp_o;
				temp_o.happiness=temp[emp_index].happiness;
				temp_o.makeDoc();
				temp[emp_index].happiness=temp_o.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have document.Therefore,"<<temp[emp_index].get_name()<<"makes Doc.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==drinkTea){
			temp[emp_index].drinkTea();
			cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have slackness.Therefore,"<<temp[emp_index].get_name()<<"drinks tea.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
			counter++;
		}
		else if(func_index==research){
			if(temp[emp_index].get_keyword()=="ResearchAssistant"){
				ResearchAssistant temp_r;
				temp_r.happiness=temp[emp_index].happiness;
				temp_r.research();
				temp[emp_index].happiness=temp_r.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have project.Therefore,"<<temp[emp_index].get_name()<<"researches.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==giveLesson){
			if(temp[emp_index].get_keyword()=="Lecturer"){
				Lecturer temp_l;
				temp_l.happiness=temp[emp_index].happiness;
				temp_l.giveLesson();
				temp[emp_index].happiness=temp_l.happiness;	
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have lesson.Therefore,"<<temp[emp_index].get_name()<<"gives lesson.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==seeSuccessfulStudent){
			if(temp[emp_index].get_keyword()=="Lecturer" ||temp[emp_index].get_keyword()=="ResearchAssistant"){
				AcademicPersonnel temp_ap;
				temp_ap.happiness=temp[emp_index].happiness;
				temp_ap.seeSuccessfulStudent();
				temp[emp_index].happiness=temp_ap.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have seminar.Therefore,"<<temp[emp_index].get_name()<<"sees the successful student.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==makePublish){
			if(temp[emp_index].get_keyword()=="Lecturer" ||temp[emp_index].get_keyword()=="ResearchAssistant"){
				AcademicPersonnel temp_ap;
				temp_ap.happiness=temp[emp_index].happiness;
				temp_ap.makePublish();
				temp[emp_index].happiness=temp_ap.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have academicPaper.Therefore,"<<temp[emp_index].get_name()<<"makes publish.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==manageProcess){
			if(temp[emp_index].get_keyword()=="Officer" ||temp[emp_index].get_keyword()=="Secretary"){
				AdministrativePersonnel temp_ad;
				temp_ad.happiness=temp[emp_index].happiness;
				temp_ad.manageProcess();
				temp[emp_index].happiness=temp_ad.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have administration.Therefore,"<<temp[emp_index].get_name()<<"manages process.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==giveHW){
			if(temp[emp_index].get_keyword()=="Lecturer"){
				Lecturer temp_l;
				temp_l.happiness=temp[emp_index].happiness;
				temp_l.giveHW();
				temp[emp_index].happiness=temp_l.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have homeworkTime.Therefore,"<<temp[emp_index].get_name()<<"gives homework.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==readHW){
			if(temp[emp_index].get_keyword()=="ResearchAssistant"){
				ResearchAssistant temp_r;
				temp_r.happiness=temp[emp_index].happiness;
				temp_r.readHW();
				temp[emp_index].happiness=temp_r.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have homeworkTimeout.Therefore,"<<temp[emp_index].get_name()<<"reads homework.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==receivePetition){
			if(temp[emp_index].get_keyword()=="Secretary"){
				Secretary temp_s;
				temp_s.happiness=temp[emp_index].happiness;
				temp_s.receivePetition();
				temp[emp_index].happiness=temp_s.happiness;
				cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have incident.Therefore,"<<temp[emp_index].get_name()<<"receives petition.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
				counter++;
			}
		}
		else if(func_index==submitPetition){
			temp[emp_index].submitPetition();
			cout<<counter+1<<")"<<temp[emp_index].get_name()<<" have solution.Therefore,"<<temp[emp_index].get_name()<<"submits petition.Happiness of"<<temp[emp_index].happiness<<"is"<<temp[emp_index].get_name()<<"contribution of uni is"<<cont<<endl;
			counter++;
		}

	}
}
int main(){
	processer();
	return 0;
}



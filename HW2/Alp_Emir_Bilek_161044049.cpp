/*
#HW2
ALP EMİR BİLEK 
161044049
*/



//INCLUDING THE LIBRARIES!
#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <fstream>
using namespace std;
//IMPLEMENTING THE CLASS AND STRUCTS!
class Student{ 
	public:
		int enroll(int,int);
		string name,surname;
		int id;
		int lectures[8];
		int counter=0;
		int cer=24;
		int bol=1;
		int disenrol();

};
struct courses{
    int id;
    string name;
    int code;
    int credit;
    int total_hours;
    string lecture_dates1,lecture_dates2;
    int field;
};
struct classrooms
{
    int id;
    string c_no;
    int student_inroom;
};
int Student::enroll(int lec,int crdt){
	
	cer=cer-crdt;
	if(cer>0){

	lectures[counter]=lec;
	counter++;
	return cer;
	}
	else{
		bol=0;
		cer=cer+crdt;
		return cer;
	}
}
int Student::disenrol(){
	return cer;
}
courses* init();
classrooms* initc();



//WRITING THE MAIN FUNC! 
int main(){
	//DEFINING SOME NECESSARY VARIABLES!
	string line;
	string bs,bs1;
	vector<Student> v;
	courses* temp_courses=init();
	classrooms* temp_classrooms=initc();
	v.resize(100);
	int flag=0;
	int i=0;
	getline(cin,line);
	istringstream some_stream(line);
	some_stream>>bs>>v[i].name>>v[i].surname>>v[i].id;
	//READING THE VALUES FROM THE KEYBOARD AS A STRING!
	while(line!="list"){
		i++;
		getline(cin,line);
		istringstream some_stream(line);
		//DIVING  STRING TO REQUARIED VARIABLES!
		some_stream>>bs>>v[i].name>>v[i].surname>>v[i].id;
	}
	for(int z=0;z<8;z++){
		cout<<"("<<temp_courses[z].id<<")"<<temp_courses[z].name<<" ";

	}
	cout<<endl;
	string neW;
	string big_line;
	int aydi,temp,temp1,temp2,temp_e;
	int std_id,lec_id,std_id_temp,w;
	while(flag==0){
		//CONTROLLING THE PROCESSES!
		getline(cin,big_line);
		string ctrls=big_line;
		istringstream some_stream(big_line);
		some_stream>>neW>>aydi>>temp;
		if(ctrls=="o"){
			for(int b=0;b<i;b++){
				cout<<v[b].name<<" "<<v[b].surname<<"[]:Total credits: "<<24-v[b].cer<<" credit right:"<<v[b].cer<<endl;
			}
			neW="a";
		}
		if(neW=="e"){
			for(int alp=0;alp<v.size();alp++){
				if(aydi==v[alp].id){
					temp1=alp;
				//temp1 is finding the std_id;
				}
			}
			int q_temp;//q_temp holds the lecture's credits!
			for(int q=0;q<8;q++){
				if(temp==temp_courses[q].id){
					q_temp=q;
				}
			}
			int rmc=v[temp1].enroll(temp,temp_courses[q_temp].credit);
			int v_counter=v[temp1].counter;
			if(v[temp1].bol==1){
				cout<<"DONE!!"<<endl;
			}
			else{
				cout<<"BLOCK!Because of credit!";
				cout<<"Remaining credit is:"<<rmc<<endl;
			}
		}
		else if(neW=="de"){
			for(int e=0;e<v.size();e++){
				if(aydi==v[e].id){
					temp_e=e;
				}
			}
			int cr=v[temp_e].disenrol();
		}
		else if(neW=="o" ){
			std_id=aydi;
			
			for(int x=0;x<v.size();x++){
				if(std_id==v[x].id){
					temp2=x;
				//temp2 is finging the std_id;
				}
			}
				cout<<v[temp2].name<<" "<<v[temp2].surname<<":"<<endl;
				for(int l=0;l<v[temp2].counter;l++){
					for(int s=0;s<8;s++){
						if(v[temp2].lectures[l]==temp_courses[s].id){
							cout<<"("<<temp_courses[s].id<<")"<<temp_courses[s].name<<" "<<temp_courses[s].credit<<endl;						}
					}
				}	
				cout<<"Remaining credit:"<<v[temp2].cer<<endl;

		}
		else if(neW=="file.txt"){
			w=aydi;
			ofstream file("out.txt");

			for(int u=0;u<v.size();u++){
				if(w==v[u].id){
					lec_id=u;
				}
			}
			file<<v[lec_id].name<<" "<<v[lec_id].surname<<":"<<endl;
			for(int f=0;f<v[lec_id].counter;f++){
				for(int c=0;c<8;c++){
					if(v[lec_id].lectures[f]==temp_courses[c].id){
						file<<"("<<temp_courses[c].id<<")"<<temp_courses[c].name<<" "<<temp_courses[c].credit<<endl;
					}
				}
			}
			file<<"Remaining credit:"<<v[lec_id].cer<<endl;
		}

		else if(neW=="exit"){
			flag++;
		}
		else if(neW=="a"){
		}
		else{
			cout<<"WARNING!"<<endl;
			cout<<"YOU SHOULD TYPE IT IN RIGHT FORM!"<<endl;
			cout<<"RIGHT FORM IS:"<<endl<<"1)e STUDENT_ID LECTURE_ID"<<endl<<"2)o STUDENT_ID"<<endl<<"3)file.txt STUDENT_ID"<<endl<<"4)o"<<endl;
		}
	}
	v.resize(i);
	return 0;
}
//READING THE COURSES FROM THE FILE AND RETURNING AN COURSES ARRAY!
courses* init(){
    static courses s[8];
    ifstream read;
    read.open("courses_classrooms.txt");
    string useless;
    read>>useless;
    for(int i=0;i<8;i++){
        read>>s[i].id>>s[i].name>>s[i].code>>s[i].credit>>s[i].total_hours>>s[i].lecture_dates1;
    }
    read.close();


    return s;
} 
//READING THE CLASSROOMS FROM THE FILE AND RETURNING AN CLASSROOMS ARRAY!
classrooms* initc(){
    static courses s[8];
    ifstream read;
    read.open("courses_classrooms.txt");
    string useless;
    read>>useless;
    for(int i=0;i<8;i++){
        read>>s[i].id>>s[i].name>>s[i].code>>s[i].credit>>s[i].total_hours>>s[i].lecture_dates1;
    }
    static classrooms sc[6];
    read>>useless;
    for(int i=0;i<6;i++){
        read>>sc[i].id>>sc[i].c_no>>sc[i].student_inroom;

    }
    return sc;
}
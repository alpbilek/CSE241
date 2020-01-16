#ifndef CLASSROOM_H_
#define CLASSROOM_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//DEFINING THE CLASSROOM CLASS!!
class Classroom{
	public:
		void set_id(int num);
		int get_id();
		void set_c_no(string c);
		string get_c_no();
		void set_student_inroom(int s);
		int get_student_inroom();
		void set_capacity(int c);
		int get_capacity();
	private:
		    int id;
    		string c_no;
    		int student_inroom,capacity;
};

#endif 
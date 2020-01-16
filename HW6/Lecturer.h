#ifndef LECTURER_H
#define LECTURER_H
using namespace std;
#include "Employee.h"
#include "UNI.h"
class Lecturer:public Employee
{
	public:
	int giveHW(UNI& u);
	int giveLesson(UNI& u);
	int seeSuccessfulStudent(UNI& u);
	int makePublish(UNI& u);
	void work(int num,UNI& u);
};

#endif // LECTURER_H
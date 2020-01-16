#ifndef RESEARCHASSISTANT_H
#define RESEARCHASSISTANT_H
using namespace std;
#include "Employee.h"
#include "UNI.h"
class ResearchAssistant:public Employee
{
	public:
	int research(UNI& u);
	int readHW(UNI& u);
	void work(int num,UNI& u);
};
#endif // RESEARCHASSISTANT_H

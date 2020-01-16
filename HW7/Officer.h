#ifndef OFFICER_H
#define OFFICER_H
#include "Employee.h"
#include "UNI.h"
using namespace std;
class Officer:public Employee
{
	public:
	int makeDoc(UNI& u);
	void work(int num,UNI& u);
};

#endif // OFFICER_H
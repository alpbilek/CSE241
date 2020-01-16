#ifndef SECRETARY_H
#define SECRETARY_H
using namespace std;
#include "UNI.h"
#include "Employee.h"
class Secretary:public Employee
{
	public:
	int receivePetition(UNI& u);
	int manageProcess(UNI& u);
	void work(int num,UNI& u);
};

#endif // SECRETARY_H

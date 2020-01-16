#ifndef YOK_H
#define YOK_H_
#include "UNI.h"
#include <string>
#include <iostream>
#include "Lecturer.h"
#include "Employee.h"
#include "Officer.h"
#include "ResearchAssistant.h"
#include "Secretary.h"
#include <fstream>
using namespace std;
class YOK{
public:
	virtual void init(UNI& u)=0;
};

class ComUNI:public YOK{
public:
	void init(UNI& u);

};

class LibUNI:public YOK{
public:
	void init(UNI& u);

};
class CapUNI:public YOK{
public:
	void init(UNI&);
};

Employee* sort(Employee** t);

#endif 
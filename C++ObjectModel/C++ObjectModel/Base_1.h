#pragma once
#include<iostream>
using namespace std;

class Base_1
{
public:
	Base_1(int);
	virtual ~Base_1(void);
	virtual void print(void) const;
protected:
	int iBase_1;
};


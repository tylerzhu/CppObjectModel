#pragma once
#include <iostream>
using namespace std;
class Base
{
public:
	Base(void);
	//~Base(void);
	virtual ~Base(void);
	void print() const;
	virtual void print_virtual() const;
};


#pragma once
#include "base.h"
class Derived_Virtual_Inherit1 :
	virtual public Base
{
public:
	Derived_Virtual_Inherit1(int);
	~Derived_Virtual_Inherit1(void);
	virtual void print(void) const;
	virtual void inherit1_print(void) const;

protected:
	int iDerived_Virtual_Inherit1;
};


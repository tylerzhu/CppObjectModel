#pragma once
#include "base.h"
class Derived_Virtual_Inherit2 :
	virtual public Base
{
public:
	Derived_Virtual_Inherit2(int);
	~Derived_Virtual_Inherit2(void);
	virtual void print(void) const;
	virtual void inherit2_print(void) const;

protected:
	int iDerived_Virtual_Inherit2;
};

#pragma once
#include "Base.h"
#include "Base_1.h"
class Derived_Mutlip_Inherit:
	public Base, public Base_1
{
public:
	Derived_Mutlip_Inherit(int);
	virtual ~Derived_Mutlip_Inherit(void);
	virtual void print(void) const;
	virtual void test_fun(void);
protected:
	int iDerived_Mutlip_Inherit;
};


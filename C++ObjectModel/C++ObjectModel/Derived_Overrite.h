#pragma once
#include "base.h"
class Derived_Overrite :
	public Base
{
public:
	Derived_Overrite(int);
	virtual ~Derived_Overrite(void);
	virtual void print(void) const;

protected:
	int iDerived;
};


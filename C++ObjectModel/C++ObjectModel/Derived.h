#pragma once
#include "base.h"

class Derived :
	public Base
{
public:
	Derived(int);
	virtual ~Derived(void);
	virtual void derived_print(void);

protected:
	int iDerived;
};


#pragma once
#include "derived_virtual_inherit1.h"
#include "derived_virtual_inherit2.h"

class Derived_Virtual :
	public Derived_Virtual_Inherit1, public Derived_Virtual_Inherit2
{
public:
	Derived_Virtual(int);
	~Derived_Virtual(void);
	virtual void print(void) const;
	virtual void inherit1_print(void) const;
	virtual void derived_print(void) const;
protected:
	int iDerived_Virtual;
};


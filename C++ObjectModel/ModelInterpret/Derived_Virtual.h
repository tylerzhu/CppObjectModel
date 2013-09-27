#pragma once
#include "base.h"
class Derived_Virtual :
	virtual public Base
{
public:
	Derived_Virtual(void);
	~Derived_Virtual(void);
	virtual void print_derived_virtual() const;
};


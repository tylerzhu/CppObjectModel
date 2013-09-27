#pragma once
#include <iostream>
#include "base.h"

using namespace std;

class Derived :
	public Base
{
public:
	Derived(void);
	~Derived(void);
	void print() const;
	virtual void print_virtual() const;
};


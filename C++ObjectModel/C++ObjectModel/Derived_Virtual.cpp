#include "stdafx.h"
#include "Derived_Virtual.h"

Derived_Virtual::Derived_Virtual(int i):Base(0),Derived_Virtual_Inherit1(1), Derived_Virtual_Inherit2(2)
{
	iDerived_Virtual = i;
	cout << "Derived_Virtual::Derived_Virtual()" << endl;
}

Derived_Virtual::~Derived_Virtual(void)
{
	cout << "Derived_Virtual::~Derived_Virtual()" << endl;
}

void Derived_Virtual::derived_print(void) const
{
	cout<<"Derived_Virtual::derived_print()£¬ iDerived_Virtual " << iDerived_Virtual << endl;
}

void Derived_Virtual::inherit1_print(void) const
{
	cout<<"Derived_Virtual::inherit1_print()£¬ iDerived_Virtual " << iDerived_Virtual << endl;
}

void Derived_Virtual::print(void) const
{
	cout<<"Derived_Virtual::print()£¬ iDerived_Virtual " << iDerived_Virtual << endl;
}
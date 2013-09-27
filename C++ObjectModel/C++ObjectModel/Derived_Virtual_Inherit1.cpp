#include "stdafx.h"
#include "Derived_Virtual_Inherit1.h"


Derived_Virtual_Inherit1::Derived_Virtual_Inherit1(int i):Base(1)
{
	iDerived_Virtual_Inherit1 = i;
	cout << "Derived_Virtual_Inherit1::Derived_Virtual_Inherit1()" << endl;
}

Derived_Virtual_Inherit1::~Derived_Virtual_Inherit1(void)
{
	cout << "Derived_Virtual_Inherit1::~Derived_Virtual_Inherit1()" << endl;
}

void Derived_Virtual_Inherit1::print(void) const
{
	cout<<"Derived_Virtual_Inherit1::print()£¬ iDerived_Virtual_Inherit1 " << iDerived_Virtual_Inherit1 << endl;
}

void Derived_Virtual_Inherit1::inherit1_print(void) const
{
	cout<<"Derived_Virtual_Inherit1::inherit1_print()£¬ iDerived_Virtual_Inherit1 " << iDerived_Virtual_Inherit1 << endl;
}
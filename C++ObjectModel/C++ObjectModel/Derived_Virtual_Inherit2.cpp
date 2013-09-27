#include "stdafx.h"
#include "Derived_Virtual_Inherit2.h"


Derived_Virtual_Inherit2::Derived_Virtual_Inherit2(int i):Base(1)
{
	iDerived_Virtual_Inherit2 = i;
	cout << "Derived_Virtual_Inherit2::Derived_Virtual_Inherit2()" << endl;
}

Derived_Virtual_Inherit2::~Derived_Virtual_Inherit2(void)
{
	cout << "Derived_Virtual_Inherit2::~Derived_Virtual_Inherit2()" << endl;
}

void Derived_Virtual_Inherit2::print(void) const
{
	cout<<"Derived_Virtual_Inherit2::print()£¬ iDerived_Virtual_Inherit2 " << iDerived_Virtual_Inherit2 << endl;
}

void Derived_Virtual_Inherit2::inherit2_print(void) const
{
	cout<<"Derived_Virtual_Inherit2::inherit2_print()£¬ iDerived_Virtual_Inherit2 " << iDerived_Virtual_Inherit2 << endl;
}
#include "stdafx.h"
#include "Derived.h"


Derived::Derived(int i):
	Base(0)
{
	iDerived = i;
	cout<<"Derived::Derived()"<<endl;
}

Derived::~Derived(void)
{
	cout<<"Derived::~Derived()"<<endl;
}

void Derived::derived_print()
{
	cout<<"Derived::derived_print()"<<iDerived<<endl;
}
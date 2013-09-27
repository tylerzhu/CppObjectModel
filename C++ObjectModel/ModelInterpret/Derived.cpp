#include "stdafx.h"
#include "Derived.h"


Derived::Derived(void)
{
	cout << "Derived::Derived()" << endl;
}


Derived::~Derived(void)
{
	cout << "Derived::~Derived()" << endl;
}

void Derived::print() const
{
	cout << "Derived::print()" << endl;
}

void Derived::print_virtual() const
{
	cout << "Derived::print_virtual()" << endl;
}
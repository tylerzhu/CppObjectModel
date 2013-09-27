#include "stdafx.h"
#include "Derived_Mutlip_Inherit.h"

Derived_Mutlip_Inherit::Derived_Mutlip_Inherit(int i): Base(0), Base_1(1)
{
	iDerived_Mutlip_Inherit = i;
	cout << "Derived_Multip_Inherit::Derived_Multip_Inherit()" << endl;
}

Derived_Mutlip_Inherit::~Derived_Mutlip_Inherit(void)
{
	cout << "Derived_Multip_Inherit::~Derived_Multip_Inherit()" << endl;
}

void Derived_Mutlip_Inherit::print() const
{
	cout << "Derived_Multip_Inherit::print()" << endl;
}

void Derived_Mutlip_Inherit::test_fun()
{
	cout << "Derived_Multip_Inherit::test_fun()" << endl;
}
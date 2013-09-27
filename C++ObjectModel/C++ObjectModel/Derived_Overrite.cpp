#include "stdafx.h"
#include "Derived_Overrite.h"


Derived_Overrite::Derived_Overrite(int i):Base(0)
{
	iDerived = i;
	cout<<"Derived_Overrite::Derived_Overrite()"<<endl;
}

Derived_Overrite::~Derived_Overrite(void)
{
	cout<<"Derived_Overrite::~Derived_Overrite()"<<endl;
}

void Derived_Overrite::print(void) const
{
	cout<<"Derived_Overrite::print()£¬ iDerived " << iDerived << endl;
}

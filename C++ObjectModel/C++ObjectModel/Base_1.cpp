#include "stdafx.h"
#include "Base_1.h"


Base_1::Base_1(int i)
{
	iBase_1 = 1;
	cout << "Base_1::Base_1()" << endl;
}


Base_1::~Base_1(void)
{
	cout << "Base_1::~Base_1()" << endl;
}

void Base_1::print(void) const
{
	cout<<"Base_1::print()£¬ iBase_1 " << iBase_1 << endl;
}
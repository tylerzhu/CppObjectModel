#include "stdafx.h"
#include "Base.h"


Base::Base(void)
{
	cout << "Base::Base()" << endl;
}


Base::~Base(void)
{
	cout << "Base::~Base()" << endl;
}

void Base::print() const
{
	cout << "Base::print()" << endl;
}

void Base::print_virtual() const
{
	cout << "Base::print_virtual()" << endl;
}
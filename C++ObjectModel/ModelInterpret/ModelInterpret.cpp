// ModelInterpret.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "Derived_Virtual.h"
#include "Empty.h"

//#include "
void test_size();
void test_polmorphisn();
void test_vitual_destructor();

int _tmain(int argc, _TCHAR* argv[])
{
	test_size();
	//test_polmorphisn();
	//test_vitual_destructor();
	system("pause");
	return 0;
}

void test_size()
{
	Base b;
	Derived d;
	Derived_Virtual dv;
	cout << "sizeof(b):\t" << sizeof(b) << endl;
	cout << "sizeof(d):\t" << sizeof(d) << endl;
	cout << "sizeof(dv):\t" << sizeof(dv) << endl;

	Empty e;
	cout << "sizeof(e):\t" << sizeof(e) << endl;
}

void test_polmorphisn()
{
	Base b;
	Derived d;
	
	b = d;
	b.print();
	b.print_virtual();

	Base *p;
	p = &d;
	p->print();
	p->print_virtual();
}

void test_vitual_destructor()
{
	Base *p = new Derived();
	delete p;
}




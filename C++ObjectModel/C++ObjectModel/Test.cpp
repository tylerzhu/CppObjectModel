// C++ObjectModel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "Derived_Overrite.h"
#include "Derived_Mutlip_Inherit.h"
#include "Derived_Virtual_Inherit1.h"
#include "Derived_Virtual.h"
#include "type_info.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

void test_base_model(void);
void test_single_inherit_norewrite(void);
void test_single_inherit_rewrite(void);
void test_multip_inherit(void);
void test_single_vitrual_inherit(void);
void test_multip_vitrual_inherit(void);

void test_polymorphisn(void);

int _tmain(int argc, _TCHAR* argv[])
{
	while (true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout << "C++对象模型测试程序，请输入对应的测试号：(输入0退出)\n";
		cout << "\t1.测试基本对象模型\n";
		cout << "\t2.测试单继承对象模型（【无】重写函数）\n";
		cout << "\t3.测试单继承对象模型（【有】重写函数）\n";
		cout << "\t4.测试多继承对象模型\n";
		cout << "\t5.测试单一虚继承对象模型\n";
		cout << "\t6.测试菱形重复虚继承对象模型\n";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); 
		int test_no;
		cout << "请输入：";
		cin >> test_no;
		cout << "你选择的测试号是：" << test_no << endl;
		switch (test_no)
		{
		case 0://退出
			exit(0);
			break;
		case 1://1.测试基本对象模型
			test_base_model();
			break;
		case 2://2.测试单继承对象模型（【无】重写函数）
			test_single_inherit_norewrite();
			break;
		case 3://3.测试单继承对象模型（【有】重写函数）
			test_single_inherit_rewrite();
			break;
		case 4://4.测试多继承对象模型
			test_multip_inherit();
			break;
		case 5://5.测试单一虚继承对象模型
			test_single_vitrual_inherit();
			break;
		case 6://6.测试菱形重复虚继承对象模型
			test_multip_vitrual_inherit();
			break;
		default:
			cout << "输入测试号错误！" << endl;
			break;
		}
	}

	return 0;
}

void test_base_model()
{
	Base b1(1000);
	cout << "对象b1的起始内存地址：" << &b1 << endl;
	cout << "type_info信息：" << ((int*)*(int*)(&b1) - 1) << endl;
	RTTICompleteObjectLocator str=
		*((RTTICompleteObjectLocator*)*((int*)*(int*)(&b1) - 1));
	//abstract class name from RTTI
	string classname(str.pTypeDescriptor->name);
	classname = classname.substr(4,classname.find("@@")-4);
	cout << classname <<endl;
	cout << "虚函数表地址：\t\t\t" << (int*)(&b1) << endl;
	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&b1) << "\t即析构函数地址：" << (int*)*((int*)*(int*)(&b1)) << endl;
	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t";
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);
	pFun();
	b1.print();
	cout << endl;
	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&b1) +1) << "\t通过地址取值iBase的值：" << *((int*)(&b1) +1) << endl;
	cout << "Base::getIBase(): " << b1.getIBase() << endl;

	b1.instanceCount();
	cout << "静态函数instanceCount地址： " << b1.instanceCount << endl;
}

void test_single_inherit_norewrite()
{
	Derived d(9999);
	cout << "对象d的起始内存地址：" << &d << endl;
	cout << "type_info信息：" << ((int*)*(int*)(&d) - 1) << endl;
	RTTICompleteObjectLocator str=
		*((RTTICompleteObjectLocator*)*((int*)*(int*)(&d) - 1));
	//abstract class name from RTTI
	string classname(str.pTypeDescriptor->name);
	classname = classname.substr(4,classname.find("@@")-4);
	cout << classname <<endl;
	cout << "虚函数表地址：\t\t\t" << (int*)(&d) << endl;
	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&d) << "\t即析构函数地址" << endl;
	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&d) + 1) << "\t";
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*(((int*)*(int*)(&d)) + 1);
	pFun();
	d.print();
	cout << endl;

	cout << "虚函数表 — 第3个函数地址：\t" << ((int*)*(int*)(&d) + 2) << "\t";
	pFun = (Fun)*(((int*)*(int*)(&d)) + 2);
	pFun();
	d.derived_print();
	cout << endl;

	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&d) +1) << "\t通过地址取得的值：" << *((int*)(&d) +1) << endl;
	cout << "推测数据成员iDerived地址：\t" << ((int*)(&d) +2) << "\t通过地址取得的值：" << *((int*)(&d) +2) << endl;
}

void test_single_inherit_rewrite()
{
	Derived_Overrite d(111111);
	cout << "对象d的起始内存地址：\t\t" << &d << endl;
	cout << "虚函数表地址：\t\t\t" << (int*)(&d) << endl;
	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&d) << "\t即析构函数地址" << endl;
	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&d) + 1) << "\t";
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*(((int*)*(int*)(&d)) + 1);
	pFun();
	d.print();
	cout << endl;

	cout << "虚函数表 — 第3个函数地址：\t" << *((int*)*(int*)(&d) + 2) << "【结束】\t";
	cout << endl;

	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&d) +1) << "\t通过地址取得的值：" << *((int*)(&d) +1) << endl;
	cout << "推测数据成员iDerived地址：\t" << ((int*)(&d) +2) << "\t通过地址取得的值：" << *((int*)(&d) +2) << endl;
}

void test_multip_inherit()
{
	Derived_Mutlip_Inherit dmi(3333);
	cout << "对象dmi的起始内存地址：\t\t" << &dmi << endl;
	cout << "虚函数表_vptr_Base地址：\t" << (int*)(&dmi) << endl;
	cout << "_vptr_Base — 第1个函数地址：\t" << (int*)*(int*)(&dmi) << "\t即析构函数地址" << endl;
	cout << "_vptr_Base — 第2个函数地址：\t" << ((int*)*(int*)(&dmi) + 1) << "\t";
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*(((int*)*(int*)(&dmi)) + 1);
	pFun();
	cout << endl;
	cout << "_vptr_Base — 第3个函数地址：\t" << ((int*)*(int*)(&dmi) + 2) << "\t";
	pFun = (Fun)*(((int*)*(int*)(&dmi)) + 2);
	pFun();
	cout << endl;
	cout << "_vptr_Base — 第4个函数地址：\t" << *((int*)*(int*)(&dmi) + 3) << "【结束】\t";
	cout << endl;
	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&dmi) +1) << "\t通过地址取得的值：" << *((int*)(&dmi) +1) << endl;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); 
	cout << "虚函数表_vptr_Base1地址：\t" << ((int*)(&dmi) +2) << endl;
	cout << "_vptr_Base1 — 第1个函数地址：\t" << (int*)*((int*)(&dmi) +2) << "\t即析构函数地址" << endl;
	cout << "_vptr_Base1 — 第2个函数地址：\t" << ((int*)*((int*)(&dmi) +2) + 1) << "\t";
	typedef void(*Fun)(void);
	pFun = (Fun)*((int*)*((int*)(&dmi) +2) + 1);
	pFun();
	cout << endl;
	cout << "_vptr_Base1 — 第3个函数地址：\t" << *((int*)*(int*)((int*)(&dmi) +2) + 2) << "【结束】\t";
	cout << endl;	
	cout << "推测数据成员iBase1地址：\t" << ((int*)(&dmi) +3) << "\t通过地址取得的值：" << *((int*)(&dmi) +3) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); 
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); 
	cout << "推测数据成员iDerived地址：\t" << ((int*)(&dmi) +4) << "\t通过地址取得的值：" << *((int*)(&dmi) +4) << endl;
}

void test_single_vitrual_inherit()
{
	Derived_Virtual_Inherit1 dvi1(88888);
	cout << "对象dvi1的起始内存地址：\t\t" << &dvi1 << endl;
	cout << "虚函数表_vptr_Derived..地址：\t\t" << (int*)(&dvi1) << endl;
	cout << "_vptr_Derived — 第1个函数地址：\t" << (int*)*(int*)(&dvi1) << endl;
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*((int*)*(int*)(&dvi1));
	pFun();
	cout << endl;
	cout << "_vptr_Derived — 第2个函数地址：\t" << *((int*)*(int*)(&dvi1) + 1) << "【结束】\t";
	cout << endl;
	cout << "=======================：\t" << ((int*)(&dvi1) +1) << "\t通过地址取得的值：" << (int*)*((int*)(&dvi1) +1) << "\t" <<*(int*)*((int*)(&dvi1) +1) << endl;
	cout << "推测数据成员iDerived地址：\t" << ((int*)(&dvi1) +2) << "\t通过地址取得的值：" << *((int*)(&dvi1) +2) << endl;
	cout << "=======================：\t" << ((int*)(&dvi1) +3) << "\t通过地址取得的值：" << *((int*)(&dvi1) +3) << endl;
	cout << "虚函数表_vptr_Base地址：\t" << ((int*)(&dvi1) +4) << endl;
	cout << "_vptr_Base — 第1个函数地址：\t" << (int*)*((int*)(&dvi1) +4) << "\t即析构函数地址" << endl;
	cout << "_vptr_Base — 第2个函数地址：\t" << ((int*)*((int*)(&dvi1) +4) +1) << "\t";
	pFun = (Fun)*((int*)*((int*)(&dvi1) +4) +1);
	pFun();
	cout << endl;
	cout << "_vptr_Base — 第3个函数地址：\t" << ((int*)*((int*)(&dvi1) +4) +2) << "【结束】\t" << *((int*)*((int*)(&dvi1) +4) +2);
	cout << endl;
	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&dvi1) +5) << "\t通过地址取得的值：" << *((int*)(&dvi1) +5) << endl;
}

void test_multip_vitrual_inherit()
{
	Derived_Virtual dvi1(88888);
	cout << "对象dvi1的起始内存地址：\t\t" << &dvi1 << endl;
	cout << "虚函数表_vptr_inherit1地址：\t\t" << (int*)(&dvi1) << endl;
	cout << "_vptr_inherit1 — 第1个函数地址：\t" << (int*)*(int*)(&dvi1) << endl;
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*((int*)*(int*)(&dvi1));
	pFun();
	cout << endl;
	cout << "_vptr_inherit1 — 第2个函数地址：\t" << ((int*)*(int*)(&dvi1) + 1) << endl;
	pFun = (Fun)*((int*)*(int*)(&dvi1) + 1);
	pFun();
	cout << endl;
	cout << "_vptr_inherit1 — 第3个函数地址：\t" << ((int*)*(int*)(&dvi1) + 2) << "\t通过地址取得的值：" << *((int*)*(int*)(&dvi1) + 2) << "【结束】\t";
	cout << endl;
	cout << "======指向=============：\t" << ((int*)(&dvi1) +1) << "\t通过地址取得的值：" << (int*)*((int*)(&dvi1) +1)<< "\t" <<*(int*)*((int*)(&dvi1) +1) << endl;
	cout << "推测数据成员iInherit1地址：\t" << ((int*)(&dvi1) +2) << "\t通过地址取得的值：" << *((int*)(&dvi1) +2) << endl;
	//
	cout << "虚函数表_vptr_inherit2地址：\t" << ((int*)(&dvi1) +3) << endl;
	cout << "_vptr_inherit2 — 第1个函数地址：\t" << (int*)*((int*)(&dvi1) +3) << endl;
	pFun = (Fun)*((int*)*((int*)(&dvi1) +3));
	pFun();
	cout << endl;
	cout << "_vptr_inherit2 — 第2个函数地址：\t" << (int*)*((int*)(&dvi1) +3) + 1 <<"\t通过地址取得的值：" << *((int*)*((int*)(&dvi1) +3) + 1) << "【结束】\t" << endl;
	cout << endl;
	cout << "======指向=============：\t" << ((int*)(&dvi1) +4) << "\t通过地址取得的值：" << (int*)*((int*)(&dvi1) +4) << "\t" <<*(int*)*((int*)(&dvi1) +4)<< endl;
	cout << "推测数据成员iInherit2地址：\t" << ((int*)(&dvi1) +5) << "\t通过地址取得的值：" << *((int*)(&dvi1) +5) << endl;
	cout << "推测数据成员iDerived地址：\t" << ((int*)(&dvi1) +6) << "\t通过地址取得的值：" << *((int*)(&dvi1) +6) << endl;
	cout << "=======================：\t" << ((int*)(&dvi1) +7) << "\t通过地址取得的值：" << *((int*)(&dvi1) +7) << endl;
	//
	cout << "虚函数表_vptr_Base地址：\t" << ((int*)(&dvi1) +8) << endl;
	cout << "_vptr_Base — 第1个函数地址：\t" << (int*)*((int*)(&dvi1) +8) << "\t即析构函数地址" << endl;
	cout << "_vptr_Base — 第2个函数地址：\t" << ((int*)*((int*)(&dvi1) +8) +1) << "\t";
	pFun = (Fun)*((int*)*((int*)(&dvi1) +8) +1);
	pFun();
	cout << endl;
	cout << "_vptr_Base — 第3个函数地址：\t" << ((int*)*((int*)(&dvi1) +8) +2) << "【结束】\t" << *((int*)*((int*)(&dvi1) +8) +2);
	cout << endl;
	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&dvi1) +9) << "\t通过地址取得的值：" << *((int*)(&dvi1) +9) << endl;
}

void test_polymorphisn()
{
	
}

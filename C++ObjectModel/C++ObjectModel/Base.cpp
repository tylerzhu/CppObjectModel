#include "stdafx.h"
#include "Base.h"

//初始化静态成员数据
int Base::count = 0;
//静态方法
int Base::instanceCount()
{
	cout<<"Base::instanceCount()\tcount地址： " << &count << endl;
	return count;
}

Base::Base(int i)
{
	iBase = i;
	count++;
	cout<<"Base::Base()"<<endl;
}


Base::~Base(void)
{
	cout<<"Base::~Base()" <<endl;
}

int Base::getIBase() const
{
	cout<< "实际iBase地址：" << &iBase << endl;
	return iBase;
}

void Base::print(void) const
{
	cout<<"Base::print()， iBase " << iBase << endl;
}

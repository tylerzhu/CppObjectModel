#pragma once

typedef unsigned long DWORD;
struct TypeDescriptor
{
	DWORD ptrToVTable;
	DWORD spare;
	char name[8];
};
struct PMD
{
	int mdisp;  //member displacement
	int pdisp;  //vbtable displacement
	int vdisp;  //displacement inside vbtable
};
struct RTTIBaseClassDescriptor
{
	struct TypeDescriptor* pTypeDescriptor; //type descriptor of the class
	DWORD numContainedBases; //number of nested classes following in the Base Class Array
	struct PMD where;        //pointer-to-member displacement info
	DWORD attributes;        //flags, usually 0
};

struct RTTIClassHierarchyDescriptor
{
	DWORD signature;      //always zero?
	DWORD attributes;     //bit 0 set = multiple inheritance, bit 1 set = virtual inheritance
	DWORD numBaseClasses; //number of classes in pBaseClassArray
	struct RTTIBaseClassArray* pBaseClassArray;
};

struct RTTICompleteObjectLocator
{
	DWORD signature; //always zero ?
	DWORD offset;    //offset of this vtable in the complete class
	DWORD cdOffset;  //constructor displacement offset
	struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class
	struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy
};
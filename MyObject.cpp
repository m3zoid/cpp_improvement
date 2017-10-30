#include "IncludeAll.h"

MyObject::MyObject()
{
	iind = 0;
#ifdef __LDBG_H_INCLUDED_
	std::cout << iind << " <- Construct (MyObject)(standart)\n";
#endif
}

MyObject::MyObject(int index)
{
	iind = index;
#ifdef __LDBG_H_INCLUDED_
	std::cout << iind << " <- Construct (MyObject)(index_type)\n";
#endif
}

MyObject::~MyObject()
{
#ifdef __LDBG_H_INCLUDED_
	std::cout << iind << " <- Destructor (MyObject)\n";
#endif
}

void MyObject::say()
{
	std::cout << iind << " <- MyObject saying name\n";
}

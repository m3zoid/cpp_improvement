#include "IncludeAll.h"

MyObject::MyObject()
{
	m_iName = 0;
	debug_str(std::to_string(m_iName) + " <- (MyObject: standart) Constructor");
}

MyObject::MyObject(int iIndex)
{
	m_iName = iIndex;
	debug_str(std::to_string(m_iName) + " <- (MyObject: by index) Constructor");
}

MyObject::~MyObject()
{
	debug_str(std::to_string(m_iName) + " <- (MyObject) Destructor");
}

void MyObject::sayname()
{
	std::cout << m_iName << " <- (MyObject) saying name\n";
}

#ifdef __LDBG_H_CUSTOMONE_INCLUDED_
void MyObject::debug_str(const std::string sOutStr) const
{
	std::cout << sOutStr << "\n";
}
#else
inline
void MyObject::debug_str(const std::string sOutStr) const
{
	// empty
}
#endif

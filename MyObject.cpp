#include "IncludeAll.h"

MyObject::MyObject()
{
	m_i_name = 0;
	debug_str(std::to_string(m_i_name) + " <- (MyObject: standart) Constructor");
}

MyObject::MyObject(int index)
{
	m_i_name = index;
	debug_str(std::to_string(m_i_name) + " <- (MyObject: by index) Constructor");
}

MyObject::~MyObject()
{
	debug_str(std::to_string(m_i_name) + " <- (MyObject) Destructor");
}

void MyObject::sayname()
{
	std::cout << m_i_name << " <- (MyObject) saying name\n";
}

#ifdef __LDBG_H_CUSTOMONE_INCLUDED_
void MyObject::debug_str(const std::string outString)
{
	std::cout << outString << "\n";
}
#else
inline
void MyObject::debug_str(const std::string outString)
{
	// empty
}
#endif

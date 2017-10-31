#ifndef __MYOBJECT_H_CUSTOMONE_INCLUDED_
#define __MYOBJECT_H_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

class MyObject
{
public:
	MyObject();
	MyObject(int);
	~MyObject();
	void sayname();

private:
	void debug_str(const std::string);

private:
	int m_i_name;
};

#endif // __MYOBJECT_H_CUSTOMONE_INCLUDED_

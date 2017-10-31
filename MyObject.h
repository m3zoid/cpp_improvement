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
	void _debug_str(const std::string) const;

private:
	int m_iName;
};

#endif // __MYOBJECT_H_CUSTOMONE_INCLUDED_

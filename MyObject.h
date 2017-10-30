#ifndef __MYOBJECT_H_INCLUDED_
#define __MYOBJECT_H_INCLUDED_

class MyObject
{
public:
	MyObject();
	MyObject(int index);
	~MyObject();
	void say();

private:
	int iind;
};

#endif // __MYOBJECT_H_INCLUDED_

#ifndef __MYLIST_HPP_CUSTOMONE_INCLUDED_
#define __MYLIST_HPP_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

template <class T>
class MyList
{
public:
	MyList();
	~MyList();

	bool empty() const;
	std::size_t size() const;

	void push_back(const T&);
	void pop_back();

	void clear();

	void reverse();

	void reveal() const;

private:
	void initializer();
	void clear_all();

	void debug_str(const std::string);

private:
	struct Element
	{
		Element* previous;
		Element* next;
		T data;
	};

private:
	std::size_t sz;
	Element* first;
	Element* last;
};

template <class T>
MyList<T>::MyList()
	// : inherited_class(arg1,arg2)
	// , member1(0)
	// , member2()
{
	initializer();
	debug_str(std::string("_ <- (MyList: standart) Constructor"));
}

template <class T>
MyList<T>::~MyList()
{
	debug_str(std::string("_ <- (MyList) Destructor start"));
	clear_all();
	debug_str(std::string("_ <- (MyList) Destructor end"));
}

template <class T>
bool MyList<T>::empty() const
{
	return (sz == 0);
}

template <class T>
std::size_t MyList<T>::size() const
{
	return sz;
}

template <class T>
void MyList<T>::push_back(const T& val)
{
	// std::unique< Element > pElement(new Element);
	Element* buffElem = new Element;
	buffElem->previous = NULL;
	buffElem->next = NULL;
	buffElem->data = val;

	if (sz > 0)
	{
		buffElem->previous = last;
		last->next = buffElem;
		last = buffElem;
	}
	else
	{
		first = buffElem;
		last = buffElem;
	}
	++sz;
	debug_str(std::to_string(sz) + " <- (MyList) Pushing back to");
}

template <class T>
void MyList<T>::pop_back()
{
	if (last)
	{
		if (first == last)
		{
			delete last;
			first = last = NULL;
		}
		else
		{
			last = last->previous;
			delete last->next;
			last->next = NULL;
		}
		--sz;
	}
	else
	{
		throw std::runtime_error("Undefined behavior with MyList pop_back()");
	}
	debug_str(std::to_string(sz) + " <- (MyList) Poping back to");
}

template <class T>
void MyList<T>::initializer()
{
	sz = 0;
	first = last = NULL;
}

template <class T>
void MyList<T>::clear_all()
{
	Element* current;
	while (first)
	{
		current = first;
		first = current->next;
		delete current;
	}
	initializer();
}

template <class T>
void MyList<T>::reveal() const
{
	debug_str(std::string("_ <- (MyList) Revealing start direct"));
	Element* current = first;
	while (current)
	{
		current->data.sayname();
		current = current->next;
	}
	debug_str(std::string("_ <- (MyList) Revealing start reverse"));
	current = last;
	while (current)
	{
		current->data.sayname();
		current = current->previous;
	}
	debug_str(std::string("_ <- (MyList) Revealing completed"));
}

template <class T>
void MyList<T>::clear()
{
	clear_all();
}

template <class T>
void MyList<T>::reverse()
{
	Element* aux_curr = first;
	Element* aux_next = NULL;
	Element* aux_prev = NULL;

	while (aux_curr != NULL)
	{
		aux_next = aux_curr->next;
		aux_curr->next = aux_prev;
		aux_curr->previous = aux_next;
		aux_prev = aux_curr;
		aux_curr = aux_next;
	}
	last = first;
	first = aux_prev;
	debug_str(std::string("_ <- (MyList) Reverse completed"));
}

#ifdef __LDBG_H_CUSTOMONE_INCLUDED_
template <class T>
void MyList<T>::debug_str(const std::string outString)
{
	std::cout << outString << "\n";
}
#else
inline
template <class T>
void MyList<T>::debug_str(const std::string outString)
{
	// empty
}
#endif

#endif // __MYLIST_HPP_CUSTOMONE_INCLUDED_

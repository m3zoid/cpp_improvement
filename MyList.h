#ifndef __MYLIST_H_INCLUDED_
#define __MYLIST_H_INCLUDED_

#include "IncludeAll.h"

template <class T>
class MyList
{
public:
	MyList();
	~MyList();

	bool empty() const noexcept;
	std::size_t size() const noexcept;

	void push_back(const T& val);
	void pop_back();

	void clear() noexcept;

	void reverse() noexcept;

	void reveal() const;

private:
	struct Element
	{
		Element* previous;
		Element* next;
		T data;
	};

	std::size_t sz;
	Element* first;
	Element* last;

	void initializer();
	void clear_all();
};

template <class T>
MyList<T>::MyList()
{
	initializer();
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Constructor\n";
#endif
}

template <class T>
MyList<T>::~MyList()
{
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Start destructor\n";
#endif
	clear_all();
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Destroyed\n";
#endif
}

template <class T>
bool MyList<T>::empty() const noexcept
{
	return (sz == 0) ? true : false;
}

template <class T>
std::size_t MyList<T>::size() const noexcept
{
	return sz;
}

template <class T>
void MyList<T>::push_back(const T& val)
{
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
#ifdef __LDBG_H_INCLUDED_
	std::cout << sz << " <- MyList Pushing back to\n";
#endif
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
#ifdef __LDBG_H_INCLUDED_
	std::cout << sz << " <- MyList Poping back to\n";
#endif
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
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Revealing start direct\n";
#endif
	Element* current = first;
	while (current)
	{
		current->data.say();
		current = current->next;
	}
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Revealing start reverse\n";
#endif
	current = last;
	while (current)
	{
		current->data.say();
		current = current->previous;
	}
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Revealing completed\n";
#endif
}

template <class T>
void MyList<T>::clear() noexcept
{
	clear_all();
}

template <class T>
void MyList<T>::reverse() noexcept
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
#ifdef __LDBG_H_INCLUDED_
	std::cout << "MyList" << " <- Reverse completed\n";
#endif
}

#endif // __MYLIST_H_INCLUDED_

#ifndef __MYLIST_HPP_CUSTOMONE_INCLUDED_
#define __MYLIST_HPP_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

template <class TObjTemplate>
class MyList
{
public:
	MyList();
	~MyList();

	bool empty() const;
	std::size_t size() const;

	void push_back(const TObjTemplate&);
	void pop_back();

	void clear();

	void reverse();

	void reveal() const;

private:
	void _initializer();
	void _clear_all();
	void _debug_str(const std::string) const;

private:
	struct Node
	{
		Node* m_pPrev;
		Node* m_pNext;
		TObjTemplate m_storedData;
	};

private:
	std::size_t m_iCurrentSize;
	Node* m_pHead;
	Node* m_pTail;
};

template <class TObjTemplate>
MyList<TObjTemplate>::MyList()
	: m_iCurrentSize(0)
	, m_pHead(NULL)
	, m_pTail(NULL)
{
	_debug_str(std::string("_ <- (MyList: standart) Constructor"));
}

template <class TObjTemplate>
MyList<TObjTemplate>::~MyList()
{
	_debug_str(std::string("_ <- (MyList) Destructor start"));
	_clear_all();
	_debug_str(std::string("_ <- (MyList) Destructor end"));
}

template <class TObjTemplate>
bool MyList<TObjTemplate>::empty() const
{
	return (m_iCurrentSize == 0);
}

template <class TObjTemplate>
std::size_t MyList<TObjTemplate>::size() const
{
	return m_iCurrentSize;
}

template <class TObjTemplate>
void MyList<TObjTemplate>::push_back(const TObjTemplate& val)
{
	// std::unique< Node > pNode(new Node);
	Node* pAuxCurr = new Node;
	pAuxCurr->m_pPrev = NULL;
	pAuxCurr->m_pNext = NULL;
	pAuxCurr->m_storedData = val;

	if (m_iCurrentSize > 0)
	{
		pAuxCurr->m_pPrev = m_pTail;
		m_pTail->m_pNext = pAuxCurr;
		m_pTail = pAuxCurr;
	}
	else
	{
		m_pHead = pAuxCurr;
		m_pTail = pAuxCurr;
	}
	++m_iCurrentSize;
	_debug_str(std::to_string(m_iCurrentSize) + " <- (MyList) Pushing back to");
}

template <class TObjTemplate>
void MyList<TObjTemplate>::pop_back()
{
	if (m_pTail)
	{
		if (m_pHead == m_pTail)
		{
			delete m_pTail;
			m_pHead = m_pTail = NULL;
		}
		else
		{
			m_pTail = m_pTail->m_pPrev;
			delete m_pTail->m_pNext;
			m_pTail->m_pNext = NULL;
		}
		--m_iCurrentSize;
	}
	else
	{
		throw std::runtime_error("Undefined behavior in MyList pop_back() function");
	}
	_debug_str(std::to_string(m_iCurrentSize) + " <- (MyList) Poping back to new size");
}

template <class TObjTemplate>
void MyList<TObjTemplate>::_initializer()
{
	m_iCurrentSize = 0;
	m_pHead = m_pTail = NULL;
}

template <class TObjTemplate>
void MyList<TObjTemplate>::_clear_all()
{
	Node* pAuxCurr;
	while (m_pHead)
	{
		pAuxCurr = m_pHead;
		m_pHead = pAuxCurr->m_pNext;
		delete pAuxCurr;
	}
	_initializer();
}

template <class TObjTemplate>
void MyList<TObjTemplate>::reveal() const
{
	_debug_str(std::string("_ <- (MyList) Revealing start direct"));
	Node* pAuxCurr = m_pHead;
	while (pAuxCurr)
	{
		pAuxCurr->m_storedData.sayname();
		pAuxCurr = pAuxCurr->m_pNext;
	}
	_debug_str(std::string("_ <- (MyList) Revealing start reverse"));
	pAuxCurr = m_pTail;
	while (pAuxCurr)
	{
		pAuxCurr->m_storedData.sayname();
		pAuxCurr = pAuxCurr->m_pPrev;
	}
	_debug_str(std::string("_ <- (MyList) Revealing completed"));
}

template <class TObjTemplate>
void MyList<TObjTemplate>::clear()
{
	_clear_all();
}

template <class TObjTemplate>
void MyList<TObjTemplate>::reverse()
{
	Node* pAuxCurr = m_pHead;
	Node* pAuxNext = NULL;
	Node* pAuxPrev = NULL;

	while (pAuxCurr != NULL)
	{
		pAuxNext = pAuxCurr->m_pNext;
		pAuxCurr->m_pNext = pAuxPrev;
		pAuxCurr->m_pPrev = pAuxNext;
		pAuxPrev = pAuxCurr;
		pAuxCurr = pAuxNext;
	}
	m_pTail = m_pHead;
	m_pHead = pAuxPrev;
	_debug_str(std::string("_ <- (MyList) Reverse completed"));
}

#ifdef __LDBG_H_CUSTOMONE_INCLUDED_
template <class TObjTemplate>
void MyList<TObjTemplate>::_debug_str(const std::string sOutStr) const
{
	std::cout << sOutStr << "\n";
}
#else
inline
template <class TObjTemplate>
void MyList<TObjTemplate>::_debug_str(const std::string sOutStr) const
{
	// empty
}
#endif

#endif // __MYLIST_HPP_CUSTOMONE_INCLUDED_

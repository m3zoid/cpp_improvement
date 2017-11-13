#ifndef __MYMAP_HPP_CUSTOMONE_INCLUDED_
#define __MYMAP_HPP_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

template <class _TKey, class _TVal, class _TCompare>
class MyMap
{
public:
    MyMap();
    ~MyMap();

    bool empty() const;
    std::size_t size() const;

    void clear();

    // void reveal() const;

private:
    struct Node
    {
        Node* m_pLeft;
        Node* m_pRight;
        MyPair<_TKey, _TVal>* m_storedPair;
    };

private:
    void _initializer();
    void _node_cleaner(Node*);
    void _clear_all();
    void _debug_str(const std::string) const;

private:
    std::size_t m_iCurrentSize;
    Node* m_pRoot;
};

template <class _TKey, class _TVal, class _TCompare>
MyMap<_TKey, _TVal, _TCompare>::MyMap()
    : m_iCurrentSize(0)
    , m_pRoot(NULL)
{
    _debug_str(std::string("_ <- (MyMap: standart) Constructor"));
}

template <class _TKey, class _TVal, class _TCompare>
MyMap<_TKey, _TVal, _TCompare>::~MyMap()
{
    _debug_str(std::string("_ <- (MyMap) Destructor start"));
    _clear_all();
    _debug_str(std::string("_ <- (MyMap) Destructor end"));
}

// template <class _TKey, class _TVal, class _TCompare>
// bool MyMap<_TKey, _TVal, _TCompare>::empty() const
// {
//  return (m_iCurrentSize == 0);
// }

// template <class _TKey, class _TVal, class _TCompare>
// std::size_t MyMap<_TKey, _TVal, _TCompare>::size() const
// {
//  return m_iCurrentSize;
// }

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_initializer()
{
    m_iCurrentSize = 0;
    m_pRoot = NULL;
}

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_node_cleaner(Node* _pNd)
{
    if (_pNd == NULL) return;

    _node_cleaner(_pNd->m_pLeft);
    _node_cleaner(_pNd->m_pRight);

    delete _pNd->m_storedPair;
}

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_clear_all()
{
    _node_cleaner(m_pRoot);
    _initializer();
}

// template <class _TKey, class _TVal, class _TCompare>
// void MyMap<_TKey, _TVal, _TCompare>::reveal() const
// {
//  _debug_str(std::string("_ <- (MyMap) Revealing start direct"));
//  Node* pAuxCurr = m_pHead;
//  while (pAuxCurr)
//  {
//      pAuxCurr->m_storedData.sayname();
//      pAuxCurr = pAuxCurr->m_pNext;
//  }
//  _debug_str(std::string("_ <- (MyMap) Revealing start reverse"));
//  pAuxCurr = m_pTail;
//  while (pAuxCurr)
//  {
//      pAuxCurr->m_storedData.sayname();
//      pAuxCurr = pAuxCurr->m_pPrev;
//  }
//  _debug_str(std::string("_ <- (MyMap) Revealing completed"));
// }

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::clear()
{
    _clear_all();
}

#ifdef __LDBG_H_CUSTOMONE_INCLUDED_
template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_debug_str(const std::string sOutStr) const
{
    std::cout << sOutStr << "\n";
}
#else
inline
template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_debug_str(const std::string sOutStr) const
{
    // empty
}
#endif

#endif // __MYMAP_HPP_CUSTOMONE_INCLUDED_

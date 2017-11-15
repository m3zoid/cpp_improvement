#ifndef __MYMAP_HPP_CUSTOMONE_INCLUDED_
#define __MYMAP_HPP_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

template <class _TKey, class _TVal, class _TCompare = my_less<_TKey> >
class MyMap
{
private:
    struct Node
    {
        Node* m_pLeft;
        Node* m_pRight;
        MyPair<_TKey, _TVal> m_storedPair;
    };

public:
    MyMap();
    ~MyMap();

    bool empty() const;
    std::size_t size() const;

    MyPair<bool, bool> insert (const MyPair<const _TKey, _TVal>&);
    // MyPair<bool, bool> insert (MyPair<_TKey, _TVal>);

    void clear();

    void reveal() const;

private:
    void _initializer();
    void _reveal_node(Node*) const;
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

template <class _TKey, class _TVal, class _TCompare>
bool MyMap<_TKey, _TVal, _TCompare>::empty() const
{
    return (m_iCurrentSize == 0);
}

template <class _TKey, class _TVal, class _TCompare>
std::size_t MyMap<_TKey, _TVal, _TCompare>::size() const
{
    return m_iCurrentSize;
}

template <class _TKey, class _TVal, class _TCompare>
MyPair<bool, bool> MyMap<_TKey, _TVal, _TCompare>::insert (const MyPair<const _TKey, _TVal>& _val)
// MyPair<bool, bool> MyMap<_TKey, _TVal, _TCompare>::insert (MyPair<_TKey, _TVal> _val)
{
    // Node* pAuxCurr = m_pRoot;
    // while (pAuxCurr != NULL)
    // {
    //     bool is_less = _TCompare(pAuxCurr.m_storedPair, _val.m_storedPair);
    //     if (is_less)
    //         pAuxCurr = pAuxCurr.m_pLeft;
    //     else
    //         pAuxCurr = pAuxCurr.m_pRight;
    // }
    return MyPair<bool, bool> (true, true);
}

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

    delete _pNd;
}

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_clear_all()
{
    _node_cleaner(m_pRoot);
    _initializer();
}

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::_reveal_node(Node* _pNd) const
{
    if (_pNd == NULL) return;

    _reveal_node(_pNd->m_pLeft);
    _reveal_node(_pNd->m_pRight);

    _pNd->m_storedPair.second.sayname();
}

template <class _TKey, class _TVal, class _TCompare>
void MyMap<_TKey, _TVal, _TCompare>::reveal() const
{
    _debug_str(std::string("_ <- (MyMap) Revealing start"));
    _reveal_node(m_pRoot);
    _debug_str(std::string("_ <- (MyMap) Revealing completed"));
}

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

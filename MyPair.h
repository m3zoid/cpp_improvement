#ifndef __MYPAIR_HPP_CUSTOMONE_INCLUDED_
#define __MYPAIR_HPP_CUSTOMONE_INCLUDED_

template <class _TVal1, class _TVal2>
struct MyPair {
    _TVal1 first;
    _TVal2 second;
    MyPair() : first(_TVal1()), second(_TVal2()) {}
    MyPair(const _TVal1& _jObj, const _TVal2& _rObj) : first(_jObj), second(_rObj) {}
};

template <class _TVal1, class _TVal2>
inline bool operator==(const MyPair<_TVal1, _TVal2>& _x, const MyPair<_TVal1, _TVal2>& _y)
{
    return _x.first == _y.first && _x.second == _y.second;
}

template <class _TVal1, class _TVal2>
inline bool operator<(const MyPair<_TVal1, _TVal2>& _x, const MyPair<_TVal1, _TVal2>& _y)
{
    return _x.first < _y.first || (!(_y.first < _x.first) && _x.second < _y.second);
}

#endif // __MYPAIR_HPP_CUSTOMONE_INCLUDED_

#ifndef __MYFUNCTION_HPP_CUSTOMONE_INCLUDED_
#define __MYFUNCTION_HPP_CUSTOMONE_INCLUDED_

#include "IncludeAll.h"

template <class _Arg1, class _Arg2, class _Result>
struct my_binary_function {
    typedef _Arg1 first_argument_type;
    typedef _Arg2 second_argument_type;
    typedef _Result result_type;
};

template <class _Tp>
struct my_less : public my_binary_function<_Tp, _Tp, bool>
{
    bool operator()(const _Tp& _x, const _Tp& _y) const { return _x < _y; }
};

#endif // __MYFUNCTION_HPP_CUSTOMONE_INCLUDED_

#line 1 "include/boost/multiprecision/detail/functions/trunc.hpp"
///////////////////////////////////////////////////////////////////////////////
//  Copyright 2022 Matt Borland. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MP_DETAIL_FUNCTIONS_TRUNC_HPP
#define BOOST_MP_DETAIL_FUNCTIONS_TRUNC_HPP

#include <cmath>
#include <limits>
#include <stdexcept>
#include <boost/multiprecision/detail/standalone_config.hpp>
#include <boost/multiprecision/detail/no_exceptions_support.hpp>

#ifdef BOOST_MP_MATH_AVAILABLE
#include <boost/math/special_functions/trunc.hpp>
#endif

namespace boost { namespace multiprecision { namespace detail {

namespace impl {

template <typename T>
inline T trunc BOOST_PREVENT_MACRO_SUBSTITUTION (const T arg)
{
    using std::floor;
    using std::ceil;

    return (arg > 0) ? floor(arg) : ceil(arg);
}

} // namespace impl

#ifdef BOOST_MP_MATH_AVAILABLE

template <typename T>
inline long long lltrunc BOOST_PREVENT_MACRO_SUBSTITUTION (const T arg)
{
    return boost::math::lltrunc(arg);
}

template <typename T>
inline int itrunc BOOST_PREVENT_MACRO_SUBSTITUTION (const T arg)
{
    return boost::math::itrunc(arg);
}

#else

template <typename T>
inline long long lltrunc BOOST_PREVENT_MACRO_SUBSTITUTION (const T arg)
{
    if (arg > LLONG_MAX)
    {
        BOOST_MP_THROW_EXCEPTION(std::domain_error("arg cannot be converted into a long long"));
    }

    return static_cast<long long>(boost::multiprecision::detail::impl::trunc(arg));
}

template <typename T>
inline int itrunc BOOST_PREVENT_MACRO_SUBSTITUTION (const T arg)
{
    if (arg > INT_MAX)
    {
        BOOST_MP_THROW_EXCEPTION(std::domain_error("arg cannot be converted into an int"));
    }

    return static_cast<int>(boost::multiprecision::detail::impl::trunc(arg));
}

#endif

}}} // Namespaces

#endif // BOOST_MP_DETAIL_FUNCTIONS_TRUNC_HPP

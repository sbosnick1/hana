/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/adapted/std_array.hpp>

#include <boost/hana/detail/static_assert.hpp>

#include <array>
using namespace boost::hana;


template <int ...i>
constexpr auto array = std::array<int, sizeof...(i)>{{i...}};

int main() {
    using operators::operator==;
    BOOST_HANA_STATIC_ASSERT(cons(0, array<>) == array<0>);
    BOOST_HANA_STATIC_ASSERT(cons(0, array<1>) == array<0, 1>);
    BOOST_HANA_STATIC_ASSERT(cons(0, array<1, 2>) == array<0, 1, 2>);
    BOOST_HANA_STATIC_ASSERT(cons(0, array<1, 2, 3>) == array<0, 1, 2, 3>);

    BOOST_HANA_STATIC_ASSERT(cons(0, nil<StdArray>) == array<0>);
}

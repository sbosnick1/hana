/*
@copyright Louis Dionne 2013-2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/remove_if.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

#include <type_traits>
namespace hana = boost::hana;


static_assert(hana::remove_if(hana::make_tuple(1, 2.0, 3, 4.0), hana::trait<std::is_integral>) == hana::make_tuple(2.0, 4.0), "");
static_assert(hana::remove_if(hana::just(3.0), hana::trait<std::is_integral>) == hana::just(3.0), "");
BOOST_HANA_CONSTANT_CHECK(hana::remove_if(hana::just(3), hana::trait<std::is_integral>) == hana::nothing);

int main() { }

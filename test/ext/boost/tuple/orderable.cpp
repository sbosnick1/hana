/*
@copyright Louis Dionne 2013-2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/ext/boost/tuple.hpp>

#include <boost/hana/tuple.hpp>

#include <laws/comparable.hpp>
#include <laws/orderable.hpp>

#include <boost/tuple/tuple.hpp>
using namespace boost::hana;


template <int i>
using eq = test::ct_eq<i>;

template <int i>
using ord = test::ct_ord<i>;

int main() {
    //////////////////////////////////////////////////////////////////////////
    // Setup for the laws below
    //////////////////////////////////////////////////////////////////////////
    auto eq_tuples = make<tuple_tag>(
          ::boost::make_tuple()
        , ::boost::make_tuple(eq<0>{})
        , ::boost::make_tuple(eq<0>{}, eq<1>{})
        , ::boost::make_tuple(eq<0>{}, eq<1>{}, eq<2>{})
        , ::boost::make_tuple(eq<0>{}, eq<1>{}, eq<2>{}, eq<3>{}, eq<4>{})
    );

    auto ord_tuples = make<tuple_tag>(
          ::boost::make_tuple()
        , ::boost::make_tuple(ord<0>{})
        , ::boost::make_tuple(ord<0>{}, ord<1>{})
        , ::boost::make_tuple(ord<0>{}, ord<1>{}, ord<2>{})
        , ::boost::make_tuple(ord<0>{}, ord<1>{}, ord<2>{}, ord<3>{}, ord<4>{})
    );

    //////////////////////////////////////////////////////////////////////////
    // Comparable and Orderable
    //////////////////////////////////////////////////////////////////////////
    test::TestComparable<ext::boost::tuple_tag>{eq_tuples};
    test::TestOrderable<ext::boost::tuple_tag>{ord_tuples};
}

/*
@copyright Louis Dionne 2013-2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/bool.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/pair.hpp>

#include <laws/base.hpp>

#include <string>
#include <utility>
namespace hana = boost::hana;


template <int i>
struct move_only : hana::test::Tracked {
    move_only() : hana::test::Tracked(i) { }
    move_only(move_only const&) = delete;
    move_only& operator=(move_only const&) = delete;
    move_only(move_only&& x)
        : hana::test::Tracked(std::move(x))
    { }

    template <int j>
    auto operator==(move_only<j> const&) const { return hana::bool_c<i == j>; }
    template <int j>
    auto operator!=(move_only<j> const& x) const { return !(*this == x); }
};

int main() {
    {
        auto t0 = hana::make_map();
        auto t_implicit = std::move(t0);
        auto t_explicit(std::move(t_implicit));

        (void)t_explicit;
        (void)t_implicit;
    }
    {
        auto t0 = hana::make_map(hana::make_pair(move_only<1>{}, move_only<10>{}));
        auto t_implicit = std::move(t0);
        auto t_explicit(std::move(t_implicit));

        (void)t_implicit;
        (void)t_explicit;
    }
    {
        auto t0 = hana::make_map(hana::make_pair(move_only<1>{}, move_only<10>{}),
                                 hana::make_pair(move_only<2>{}, move_only<20>{}));
        auto t_implicit = std::move(t0);
        auto t_explicit(std::move(t_implicit));

        (void)t_implicit;
        (void)t_explicit;
    }
    {
        auto t0 = hana::make_map(hana::make_pair(move_only<1>{}, move_only<10>{}),
                                 hana::make_pair(move_only<2>{}, move_only<20>{}),
                                 hana::make_pair(move_only<3>{}, move_only<30>{}));
        auto t_implicit = std::move(t0);
        auto t_explicit(std::move(t_implicit));

        (void)t_implicit;
        (void)t_explicit;
    }
    {
        auto t0 = hana::make_map(hana::make_pair(hana::int_c<2>, std::string{"abcdef"}));
        auto moved = std::move(t0);
        BOOST_HANA_RUNTIME_CHECK(
            moved == hana::make_map(hana::make_pair(hana::int_c<2>, std::string{"abcdef"}))
        );
    }
}

template <int i>
struct non_tracked_move_only {
    constexpr non_tracked_move_only() { }
    constexpr non_tracked_move_only(non_tracked_move_only const&) = delete;
    constexpr non_tracked_move_only& operator=(non_tracked_move_only const&) = delete;
    constexpr non_tracked_move_only(non_tracked_move_only&&) { }

    template <int j>
    auto operator==(non_tracked_move_only<j> const&) const
    { return hana::bool_c<i == j>; }
    template <int j>
    auto operator!=(non_tracked_move_only<j> const& x) const
    { return !(*this == x); }
};

constexpr bool in_constexpr_context() {
    auto t0 = hana::make_map(
        hana::make_pair(non_tracked_move_only<2>{}, non_tracked_move_only<20>{}),
        hana::make_pair(non_tracked_move_only<3>{}, non_tracked_move_only<30>{}));
    auto t_implicit = std::move(t0);
    auto t_explicit(std::move(t_implicit));

    (void)t_implicit;
    (void)t_explicit;
    return true;
}

static_assert(in_constexpr_context(), "");

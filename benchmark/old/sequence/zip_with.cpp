/*
@copyright Louis Dionne 2013-2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/std/forward.hpp>
#include <boost/hana/fwd/sequence.hpp>

#include "benchmark.hpp"

<%= setup %>

template <int i> struct x { };


int main() {
    using L = <%= datatype %>;
    auto xs = boost::hana::make<L>(
        <%= (1..input_size).to_a.map { |i| "x<#{i}>{}" }.join(', ') %>
    );

    auto ys = xs;

    auto f = [](auto&& x, auto&& y) -> decltype(auto) {
        return boost::hana::detail::std::forward<decltype(x)>(x);
    };

    boost::hana::benchmark::measure([=] {
        boost::hana::zip.with(f, xs, ys);
    });
}

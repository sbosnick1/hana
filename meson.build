# Copyright 2016 Steven Bosnick
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

project('boost-hana', 'cpp', version:'0.6.0', license:'boost')

if not meson.is_subproject()
    error('The meson support for boost hana is designed for hana as a subproject')
endif

hana = declare_dependency(include_directories: 'include')

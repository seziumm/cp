// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2015 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif


namespace __DEBUG_UTIL__ { 
  void print(const char *x) { std::cerr << x; }
  void print(bool x) { std::cerr << x; }
  void print(char x) { std::cerr << '\'' << x << '\''; }
  void print(signed short int x) { std::cerr << x; }
  void print(unsigned short int x) { std::cerr << x; }
  void print(signed int x) { std::cerr << x; }
  void print(unsigned int x) { std::cerr << x; }
  void print(signed long int x) { std::cerr << x; }
  void print(unsigned long int x) { std::cerr << x; }
  void print(signed long long int x) { std::cerr << x; }
  void print(unsigned long long int x) { std::cerr << x; }
  void print(float x) { std::cerr << x; }
  void print(double x) { std::cerr << x; }
  void print(long double x) { std::cerr << x; }
  void print(std::string x) { std::cerr << '\"' << x << '\"'; }

  template <size_t N> void print(std::bitset<N> x) { std::cerr << x; }
  void print(std::vector<bool> &v) { /* Overloaded this because stl optimizes
                                   vector<bool> by using _Bit_reference instead of
                                   bool to conserve space. */
    int f = 0;
    std::cerr << '{';
    for (auto &&i : v)
      std::cerr << (f++ ? "," : "") << i;
    std::cerr << "}";
  }
  /* Templates Declarations to support nested datatypes */

  template <typename T> void print(T &&x);

  template <typename T> void print(std::vector<std::vector<T>> &mat);

  template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]);

  template <typename F, typename S> void print(std::pair<F, S> x);

  template <typename... T> void print(std::priority_queue<T...> pq);

  template <typename T> void print(std::stack<T> st);

  template <typename T> void print(std::queue<T> q);

  /* Template Datatypes Definitions */

  template <typename T> void print(T &&x) {
    /*  This works for every container that supports range-based loop
        i.e. vector, set, map, oset, omap, dequeue */
    int f = 0;
    std::cerr << '{';
    for (auto &&i : x)
      std::cerr << (f++ ? "," : ""), print(i);
    std::cerr << "}";
  }
  template <typename T> void print(std::vector<std::vector<T>> &mat) {
    int f = 0;
    std::cerr << "\n~~~~~\n";
    for (auto &&i : mat) {
      std::cerr << std::setw(2) << std::left << f++, print(i), std::cerr << "\n";
    }
    std::cerr << "~~~~~\n";
  }
  template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) {
    int f = 0;
    std::cerr << "\n~~~~~\n";
    for (auto &&i : mat) {
      std::cerr << std::setw(2) << std::left << f++, print(i), std::cerr << "\n";
    }
    std::cerr << "~~~~~\n";
  }
  template <typename F, typename S> void print(std::pair<F, S> x) {
    std::cerr << '(';
    print(x.first);
    std::cerr << ',';
    print(x.second);
    std::cerr << ')';
  }
  template <typename... T> void print(std::priority_queue<T...> pq) {
    int f = 0;
    std::cerr << '{';
    while (!pq.empty())
      std::cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
    std::cerr << "}";
  }
  template <typename T> void print(std::stack<T> st) {
    int f = 0;
    std::cerr << '{';
    while (!st.empty()) {
      std::cerr << (f++ ? "," : ""), print(st.top()), st.pop();
    }
    std::cerr << "}";
  }
  template <typename T> void print(std::queue<T> q) {
    int f = 0;
    std::cerr << '{';
    while (!q.empty())
      std::cerr << (f++ ? "," : ""), print(q.front()), q.pop();
    std::cerr << "}";
  }
  /* Printer functions */
  void printer(const char *) {} /* Base Recursive */
  template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
      /* Using && to capture both lvalues and rvalues */
      int i = 0;
      for (size_t bracket = 0;
          names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
        if (names[i] == '(' or names[i] == '<' or names[i] == '{')
          bracket++;
        else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
          bracket--;
      std::cerr.write(names, i) << " = ";
      print(head);
      if (sizeof...(tail))
        std::cerr << " |", printer(names + i + 1, tail...);
      else
        std::cerr << "\n";
    }
} // namespace __DEBUG_UTIL__




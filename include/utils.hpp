// The MIT License (MIT)

// Copyright (c) 2024 Liao-QiHua

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <cstring>
#include <string>
namespace graphvizwrapper {

#define DEBUG_PRINT(s)             \
  do {                             \
    std::cout << (s) << std::endl; \
  } while (false);

#define ERROR_PRINT(s)             \
  do {                             \
    std::cout << "!!!Error in "    \
              << __func__          \
              << "(" << __LINE__   \
              << ")" << ": " << s  \
              << std::endl;        \
  } while (false);

template <typename T, T v>
inline std::string enum_to_string() {
  const char* function = nullptr;
#ifdef _MSC_VER
  function = __FUNCSIG__;
#elif defined(__clang__)
  function = __PRETTY_FUNCTION__;
#elif defined(__GNUC__)
  function = __PRETTY_FUNCTION__;
#else
  std::cout << "Using an unknown compiler." << std::endl;
#endif
  auto function_len = strlen(function);
  auto start = 0u;
  auto equal_num = 0u;
  auto i = 0u;
  // find the second '='
  while (i < function_len) {
    if (function[i] != '=') {
    } else if (function[i] == '=') {
      equal_num++;
    }
    if (equal_num == 2) {
      start = i;
      break;
    }
    ++i;
  }
  // skip '=' and ' '
  start += 2;
  std::string v_str;
  while (start < function_len) {
    if (function[start] != ';') {
      v_str.append(std::string(1, function[start++]));
    } else {
      break;
    }
  }

  return v_str;
}
}  // namespace graphvizwrapper
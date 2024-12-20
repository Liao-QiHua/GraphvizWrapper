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

#include "include/html_like.h"

#include <memory>

namespace graphvizwrapper::htmllike {

// TableAttributeList begin
std::shared_ptr<std::string> TableAttributeList::GetAttrlistStr() {
  auto attr_str = std::make_shared<std::string>();
  attr_str->reserve(50);
  for (const auto& kv : attr_list_) {
    attr_str->append(" ")
            .append(kv.first)
            .append("=")
            .append("\"")
            .append(kv.second)
            .append("\"");
  }
  return attr_str;
}
// TableAttributeList end

// TableCell begin
std::shared_ptr<std::string> TableCell::to_string() {
  auto cell_str = std::make_shared<std::string>();
  cell_str->reserve(50);
  cell_str->append("<td")
          .append(*GetAttrlistStr())
          .append(">")
          .append(text_)
          .append("</td>\n");
  return cell_str;
}
// TableCell end

// TableRow begin
std::shared_ptr<std::string> TableRow::to_string() {
  auto row_str = std::make_shared<std::string>();
  row_str->reserve(50);
  row_str->append("<tr>")
         .append(*GetAttrlistStr())
         .append(">\n");
  for (auto i = 0u; i < cells_.size(); i++) {
    row_str->append(std::string(4, ' '))
           .append(*cells_[i]->to_string());
  }
  row_str->append("</tr>\n");
  return row_str;
}
// TableRow end

// Table begin
std::shared_ptr<std::string> Table::to_string() {
  auto table_str = std::make_shared<std::string>();
  table_str->reserve(50);
  table_str->append("<table")
           .append(*GetAttrlistStr())
           .append(">\n");
  for (auto i = 0u; i < rows_.size(); i++) {
    table_str->append(*rows_[i]->to_string());
  }
  table_str->append("</table>\n");
  return table_str;
}
// Table end
};  // namespace graphvizwrapper::htmllike

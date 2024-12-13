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

namespace graphvizwrapper::htmllike {

// TableAttributeList begin
std::string TableAttributeList::GetAttrlistStr() {
  std::string attr_str;
  for (const auto& kv : attr_list_) {
    attr_str += " " + kv.first + "=" + "\"" + kv.second + "\"";
  }
  return attr_str;
}
// TableAttributeList end

// TableCell begin
std::string TableCell::to_string() {
  std::string cell_str;
  cell_str = std::string("<td") + GetAttrlistStr() + std::string(">");
  cell_str += text_ + std::string("</td>");
  return std::string("<td>") + text_ + std::string("</td>\n");
}
// TableCell end

// TableRow begin
std::string TableRow::to_string() {
  std::string row_str;
  row_str = std::string("<tr") + GetAttrlistStr() + std::string(">\n");
  for (auto i = 0u; i < cells_.size(); i++) {
    row_str += std::string(4, ' ') + cells_[i]->to_string();
  }
  row_str += "  </tr>\n";
  return row_str;
}
// TableRow end

// Table begin
std::string Table::to_string() {
  std::string table_str;
  table_str = std::string("<table") + GetAttrlistStr() + std::string(">\n");
  for (auto i = 0u; i < rows_.size(); i++) {
    table_str += rows_[i]->to_string();
  }
  table_str += "</table>\n";
  return table_str;
}
// Table end
};  // namespace graphvizwrapper::htmllike

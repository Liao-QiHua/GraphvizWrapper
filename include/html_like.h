#ifndef _HTML_LIKE_H_
#define _HTML_LIKE_H_
// The MIT License (MIT)

// Copyright (c) 2014 Liao-QiHua

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

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace graphvizwrapper::htmllike {

class TableAttributeList {
 public:
  void SetAlign(std::string value) {
    attr_list_.insert({std::string("align"), value});
  }
  void SetBgcolor(std::string value) {
    attr_list_.insert({std::string("bgcolor"), value});
  }
  void SetBorder(std::string value) {
    attr_list_.insert({std::string("border"), value});
  }
  void SetCellborder(std::string value) {
    attr_list_.insert({std::string("cellborder"), value});
  }
  void SetId(std::string value) {
    attr_list_.insert({std::string("id"), value});
  }
  void SetPort(std::string value) {
    attr_list_.insert({std::string("port"), value});
  }

 protected:
  std::shared_ptr<std::string> GetAttrlistStr();

 protected:
  std::map<std::string, std::string> attr_list_;
};

class TableCell : public TableAttributeList {
 public:
  void SetText(std::string value) { text_ = value; }
  std::shared_ptr<std::string> to_string();

 protected:
  std::string text_;
};

class TableRow : public TableAttributeList {
 public:
  void AddCell(TableCell* cell) { cells_.push_back(cell); }
  std::shared_ptr<std::string> to_string();

 protected:
  std::vector<TableCell*> cells_;
};

class Table : public TableAttributeList {
 public:
  void AddRow(TableRow* row) { rows_.push_back(row); }
  std::shared_ptr<std::string> to_string();

 protected:
  std::vector<TableRow*> rows_;
};

}  // namespace graphvizwrapper::htmllike

#endif  // _HTML_LIKE_H_
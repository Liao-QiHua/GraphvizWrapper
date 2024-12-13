#ifndef _NODES_H_
#define _NODES_H_
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

#include <functional>
#include <string>
#include <vector>

#include "include/types.h"
#include "include/attributes.h"

namespace graphvizwrapper {

enum class TNodeType {
  kUnknown,
  kGraph,
  kDigraph,
  kSubGraph,
  kNodeStmt,
  kEdgeStmt,
  kAttrStmt,
  kIdAssignStmt,
};

class TNode {
 public:
  TNode(TNodeType tnode_type = TNodeType::kUnknown)
      : tnode_type_(tnode_type), level_(0), parent_(nullptr), childs_() {}

  ~TNode() = default;

  // children's type is kNodeStmt, kEdgeStmt, kAttrStmt,
  // kSubGraphStmt or kIdAssignStmt.
  void AddChild(TNode *child);

  TNodeType tnode_type() { return tnode_type_; }

  TNode *parent() { return parent_; }

  int level() { return level_; }

  virtual std::string to_string() { return ""; }

 protected:
  void set_level(int level) { level_ = level; }
  void set_level(TNode *node, int level);
  void set_parent(TNode *parent) { parent_ = parent; }

 protected:
  int level_;
  TNodeType tnode_type_;
  TNode *parent_;
  std::vector<TNode *> childs_;
};

class GGraph : public TNode {
 public:
  GGraph(TNodeType tnode_type = TNodeType::kGraph, bool strict = false)
      : TNode(tnode_type), strict_(strict) {}

  ~GGraph() = default;

  virtual std::string to_string() override;

  std::string GetName();

 protected:
  bool strict_;
};

class GAttrStmt : public TNode {
 public:
  enum AttrStmtType { kGraph, kNode, kEdge };

 public:
  GAttrStmt(AttrStmtType attr_stmt_type)
      : TNode(TNodeType::kAttrStmt), attr_stmt_type_(attr_stmt_type) {}
  ~GAttrStmt() = default;
  void AddAttr(std::string key, std::string value) {
    attr_list_.AddAttr(key, value);
  }
  virtual std::string to_string() override;

 private:
  AttrStmtType attr_stmt_type_;
  AttributeList attr_list_;
};

class GNodeStmt : public TNode {
 public:
  GNodeStmt(std::string node_id)
      : TNode(TNodeType::kNodeStmt), node_id_(node_id) {}
  ~GNodeStmt() = default;
  void set_attr_list(AttributeList &attr_list) { attr_list_ = attr_list; }
  void AddAttr(std::string key, std::string value) {
    attr_list_.AddAttr(key, value);
  }

  std::string GetNodeIdStr() { return node_id_; }
  virtual std::string to_string() override;

 private:
  std::string node_id_;
  AttributeList attr_list_;
};

class GEdgeStmt : public TNode {
 public:
  GEdgeStmt(bool directed = false)
      : TNode(TNodeType::kEdgeStmt), directed_(directed) {}
  ~GEdgeStmt() = default;
  void set_edge(GNodeStmt *begin, GNodeStmt *end);
  void set_attr_list(AttributeList &attr_list) { attr_list_ = attr_list; }
  void AddAttr(std::string key, std::string value) {
    attr_list_.AddAttr(key, value);
  }
  virtual std::string to_string() override;

 private:
  bool directed_;
  GNodeStmt *begin_;
  GNodeStmt *end_;
  AttributeList attr_list_;
};

class IdAssignStmt : public TNode {
 public:
  IdAssignStmt() : TNode(TNodeType::kIdAssignStmt) {}
  ~IdAssignStmt() = default;
  virtual std::string to_string() { return ""; }
};

}  // namespace graphvizwrapper

#endif  // _NODES_H_
#ifndef _GRAPHVIZ_NODES_H_
#define _GRAPHVIZ_NODES_H_
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
#include <vector>

namespace gvw {

enum class TNodeType {
  kUnknown,
  kGraph,
  kNodeStmt,
  kEdgeStmt,
  kAttrStmt,
  kSubGraphStmt,
  kIdAssignStmt,
};

class TNode {
 public:
  TNode() : tnode_type_(TNodeType::kUnknown), level_(0), childs_() {}
  ~TNode() = default;
  TNodeType tnode_type() { return tnode_type_; }
  // children's type is kNodeStmt, kEdgeStmt, kAttrStmt,
  // kSubGraphStmt or kIdAssignStmt.
  void AddChild(TNode* child) {
    if (child == nullptr) {
      return;
    }
    childs_.push_back(child);
    child->set_parent(this);
    set_level(this, level_);
  }

  void set_parent(TNode* parent) { parent_ = parent; }
  TNode* parent() { return parent_; }

  int level() { return level_; }

  TNodeType tnode_type() { return tnode_type_; }

 protected:
  void set_level(int level) { level_ = level; }
  void set_level(TNode* node, int level) {
    std::vector<TNode*>& childs = node->childs_;
    for (auto i = 0u; i < childs.size(); i++) {
      childs[i]->set_level(level + 1);
      set_level(childs[i], level + 1);
    }
  }

 protected:
  int level_;
  TNodeType tnode_type_;
  TNode* parent_;
  std::vector<TNode*> childs_;
};

class GGraph : public TNode {
 public:
  GGraph(TNodeType tnode_type) : TNode(), tnode_type_(TNodeType::kGraph) {}
  ~GGraph() = default;
};

class GAttrStmt : public TNode {
 public:
  enum AttrStmtType { kGraph, kNode, kEdge };

 public:
  GAttrStmt(AttrStmtType attr_stmt_type)
      : TNode(),
        tnode_type_(TNodeType::kAttrStmt),
        attr_stmt_type_(attr_stmt_type) {}
  ~GAttrStmt() = default;
  void AddAttr(std::string key, std::string value) {
    attr_list_.push_back(GAttribute(key, value));
  }
  std::string to_string() {
    std::string attr_stmt_str;
    switch (attr_type_) {
      case kGraph:
        attr_stmt_str += "graph ";
        break;
      case kNode:
        attr_stmt_str += "node ";
        break;
      default:
        attr_stmt_str += "edge ";
        break;
    }
    attr_stmt_str += attr_list_.to_string();
    return attr_stmt_str;
  }

 private:
  AttrStmtType attr_stmt_type_;
  GAttributeList attr_list_;
};

class GNodeStmt : public TNode {
 public:
  GNodeStmt(std::string node_id)
      : TNode(), tnode_type_(TNodeType::kNodeStmt), node_id_(node_id) {}
  ~GNodeStmt() = default;
  void AddAttr(std::string key, std::string value) {
    attr_list_.push_back(GAttribute(key, value));
  }

  std::string GetNodeIdStr() { return node_id_; }
  std::string to_string() {
    std::string node_stmt_str = node_id_;
    node_stmt_str += attr_list_.to_string();
    return node_stmt_str;
  }

 private:
  std::string node_id_;
  GAttributeList attr_list_;
};

class GEdgeStmt : public TNode {
 public:
  GEdgeStmt() : TNode(), tnode_type_(TNodeType::kEdgeStmt) {}
  ~GEdgeStmt() = default;
  void set_edge(GNodeStmt* begin, GNodeStmt* end) {
    if (begin == nullptr || end == nullptr) {
      return;
    }
    begin_ = begin;
    end_ = end;
  }
  std::string to_string() {
    if (begin_ == nullptr || end_ == nullptr) {
        terminate();
    }
    std::string edge_stmt_str = begin_->GetNodeIdStr();
    edge_stmt_str += " -> "
    edge_stmt_str += end_->GetNodeIdStr() + "\0";
    return edge_stmt_str;
  }

 private:
  GNodeStmt* begin_;
  GNodeStmt* end_;
};

class SubGraphStmt : public GGraph {
 public:
  SubGraphStmt() : GGraph(), tnode_type_(TNodeType::kSubGraphStmt) {}
  ~SubGraphStmt() = default;
};

class IdAssignStmt : public TNode {
 public:
  IdAssignStmt() : TNode(), tnode_type_(TNodeType::kIdAssignStmt) {}
  ~IdAssignStmt() = default;
};

}  // namespace gvw

#endif  // _GRAPHVIZ_NODES_H_
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

#include "include/nodes.h"

#include <memory>
#include <string>

namespace graphvizwrapper {

// TNode begin
void TNode::AddChild(TNode *child) {
  if (child == nullptr) {
    return;
  }
  childs_.push_back(child);
  child->set_parent(this);
  set_level(this, level_);
}

void TNode::set_level(TNode *node, int level) {
  std::vector<TNode *> &childs = node->childs_;
  for (auto i = 0u; i < childs.size(); i++) {
    childs[i]->set_level(level + 1);
    set_level(childs[i], level + 1);
  }
}
// TNode end

// Graph begin

void Graph::accept(TreeVisitor *visitor) { visitor->visitGraph(this); }

std::shared_ptr<std::string> Graph::to_string() {
  auto graph_str = std::make_shared<std::string>();
  graph_str->reserve(100);
  std::string space_str(level() * 2, ' ');
  graph_str->append(space_str).append(GetName()).append(" {\n");
  for (auto i = 0u; i < childs_.size(); i++) {
    graph_str->append(*childs_[i]->to_string());
  }
  graph_str->append(space_str).append("}\n");
  return graph_str;
}

std::string Graph::GetName() {
  if (tnode_type() == TNodeType::kSubGraph) {
    return std::string("subgraph");
  }
  if (strict_) {
    return tnode_type() == TNodeType::kGraph ? std::string("strict graph")
                                             : std::string("strict digraph");
  }
  return tnode_type() == TNodeType::kGraph ? std::string("graph")
                                           : std::string("digraph");
}
// Graph end

// AttrStmt begin
void AttrStmt::accept(TreeVisitor *visitor) { visitor->visitAttrStmt(this); }

std::shared_ptr<std::string> AttrStmt::to_string() {
  auto attr_stmt_str = std::make_shared<std::string>();
  attr_stmt_str->reserve(50);
  switch (attr_stmt_type_) {
    case kGraph:
      attr_stmt_str->append("graph ");
      break;
    case kNode:
      attr_stmt_str->append("node ");
      break;
    default:
      attr_stmt_str->append("edge ");
      break;
  }
  attr_stmt_str->append(attr_list_.to_string());
  return attr_stmt_str;
}
// AttrStmt end

// NodeStmt begin
void NodeStmt::accept(TreeVisitor *visitor) { visitor->visitNodeStmt(this); }

std::shared_ptr<std::string> NodeStmt::to_string() {
  std::string space_str(level() * 2, ' ');
  auto node_stmt_str = std::make_shared<std::string>();
  node_stmt_str->reserve(50);
  node_stmt_str->append(space_str)
      .append(node_id_)
      .append(attr_list_.to_string())
      .append(";\n");
  return node_stmt_str;
}
// NodeStmt end

// EdgeStmt begin
void EdgeStmt::accept(TreeVisitor *visitor) { visitor->visitEdgeStmt(this); }

void EdgeStmt::set_edge(NodeStmt *begin, NodeStmt *end) {
  if (begin == nullptr || end == nullptr) {
    exit(1);
  }
  begin_ = begin;
  end_ = end;
}

std::shared_ptr<std::string> EdgeStmt::to_string() {
  if (begin_ == nullptr || end_ == nullptr) {
    exit(1);
  }
  std::string space_str(level() * 2, ' ');
  auto edge_stmt_str = std::make_shared<std::string>();
  edge_stmt_str->reserve(50);
  edge_stmt_str->append(space_str)
      .append(begin_->GetNodeIdStr())
      .append(directed_ ? " -> " : " -- ")
      .append(end_->GetNodeIdStr())
      .append(attr_list_.to_string())
      .append(";\n");
  return edge_stmt_str;
}
// EdgeStmt end

// IdAssignStmt begin
void IdAssignStmt::accept(TreeVisitor *visitor) {
  visitor->visitIdAssignStmt(this);
}
// IdAssignStmt end
}  // namespace graphvizwrapper

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

// GGraph begin
std::string GGraph::to_string() {
  std::string str;
  std::string space_str(level(), ' ');
  str += space_str + GetName() + " {\n";
  for (auto i = 0u; i < childs_.size(); i++) {
    str += childs_[i]->to_string();
  }
  str += space_str + "}\n";
  return str;
}

std::string GGraph::GetName() {
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
// GGraph end

// GAttrStmt begin
std::string GAttrStmt::to_string() {
  std::string attr_stmt_str;
  switch (attr_stmt_type_) {
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
// GAttrStmt end

// GNodeStmt begin
std::string GNodeStmt::to_string() {
  std::string space_str(level(), ' ');
  std::string node_stmt_str = space_str + node_id_;
  node_stmt_str += attr_list_.to_string() + ";\n\0";
  return node_stmt_str;
}
// GNodeStmt end

// GEdgeStmt begin
void GEdgeStmt::set_edge(GNodeStmt *begin, GNodeStmt *end) {
  if (begin == nullptr || end == nullptr) {
    exit(1);
  }
  begin_ = begin;
  end_ = end;
}

std::string GEdgeStmt::to_string() {
  if (begin_ == nullptr || end_ == nullptr) {
    exit(1);
  }
  std::string space_str(level(), ' ');
  std::string edge_stmt_str = space_str + begin_->GetNodeIdStr();
  edge_stmt_str += directed_ ? " -> " : " -- ";
  edge_stmt_str += end_->GetNodeIdStr() + attr_list_.to_string() + ";\n\0";
  return edge_stmt_str;
}
// GEdgeStmt end
}  // namespace graphvizwrapper

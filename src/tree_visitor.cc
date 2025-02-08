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

#include "include/tree_visitor.h"

#include <iostream>

#include "include/nodes.h"
#include "include/utils.hpp"

namespace graphvizwrapper {

void DeleterVisitor::visitAttrStmt(AttrStmt* node) {
  DEBUG_PRINT("delete AttrStmt\n");
  delete node;
}
void DeleterVisitor::visitEdgeStmt(EdgeStmt* node) {
  DEBUG_PRINT("delete EdgeStmt\n");
  delete node;
}
void DeleterVisitor::visitGraph(Graph* node) {
  for (auto& child : node->GetChilds()) {
    switch (child->tnode_type()) {
      case TNodeType::kDigraph:
      case TNodeType::kGraph:
      case TNodeType::kSubGraph:
        visitGraph(dynamic_cast<Graph*>(child));
        break;
      case TNodeType::kAttrStmt:
        visitAttrStmt(dynamic_cast<AttrStmt*>(child));
        break;
      case TNodeType::kEdgeStmt:
        visitEdgeStmt(dynamic_cast<EdgeStmt*>(child));
        break;
      case TNodeType::kNodeStmt:
        visitNodeStmt(dynamic_cast<NodeStmt*>(child));
        break;
      case TNodeType::kIdAssignStmt:
        visitIdAssignStmt(dynamic_cast<IdAssignStmt*>(child));
        break;
      default:
        DEBUG_PRINT((enum_to_string<TNodeType, TNodeType::kUnknown>()));
        DEBUG_PRINT("!!! Error");
        exit(1);
        break;
    }
  }
  DEBUG_PRINT("delete Graph\n");
  delete node;
}
void DeleterVisitor::visitIdAssignStmt(IdAssignStmt* node) {
  DEBUG_PRINT("delete IdAssignStmt\n");
  delete node;
}
void DeleterVisitor::visitNodeStmt(NodeStmt* node) {
  DEBUG_PRINT("delete NodeStmt\n");
  delete node;
}

}  // namespace graphvizwrapper

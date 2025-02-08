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

#include "include/graphviz.h"

#include <iostream>

namespace graphvizwrapper {

void Graphviz::AddSubGraph(Graph* sub_graph) {
  if (sub_graph != nullptr) root_->AddChild(sub_graph);
}

void Graphviz::AddNodeStmt(NodeStmt* stmt) {
  if (stmt != nullptr) root_->AddChild(stmt);
}

void Graphviz::AddEdgeStmt(EdgeStmt* stmt) {
  if (stmt != nullptr) root_->AddChild(stmt);
}

void Graphviz::AddAttrStmt(AttrStmt* stmt) {
  if (stmt != nullptr) root_->AddChild(stmt);
}

void Graphviz::AddIdAssignStmt(IdAssignStmt* stmt) {
  if (stmt != nullptr) root_->AddChild(stmt);
}

// Graph *  Graphviz::CreateSubGraph(Graph * parent) {
//   return new Graph(TNodeType::kSubGraph, parent->getStrict());
// }

// NodeStmt * Graphviz::CreateNodeStmt() {

// }

// EdgeStmt * Graphviz::CreateEdgeStmt() {

// }

// AttrStmt * Graphviz::CreateAttrStmt() {

// }

// IdAssignStmt * Graphviz::CreateIdAssignStmt() {

// }

void Graphviz::free() {
  if (root_ == nullptr) return;
  DeleterVisitor deleter;
  root_->accept(&deleter);
}
}  // namespace graphvizwrapper

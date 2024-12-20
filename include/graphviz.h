#ifndef _GRAPHVIZ_H_
#define _GRAPHVIZ_H_
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

namespace graphvizwrapper {

class Graphviz {
public:
  Graphviz(TNodeType tnode_type = TNodeType::kGraph, bool strict = false)
    : root_(new Graph(tnode_type, strict)) {
  }
  ~Graphviz() { free(root_); }
  void AddSubGraph(Graph * sub_graph);
  void AddNodeStmt(NodeStmt * stmt);
  void AddEdgeStmt(EdgeStmt * stmt);
  void AddAttrStmt(AttrStmt * stmt);
  void AddIdAssignStmt(IdAssignStmt * stmt);
  // Graph * CreateSubGraph(Graph * parent = this);
  // NodeStmt * CreateNodeStmt();
  // EdgeStmt * CreateEdgeStmt();
  // AttrStmt * CreateAttrStmt();
  // IdAssignStmt * CreateIdAssignStmt();
private:
  // Release the entire tree with root_ as the root by postorder traversal.
  void free(TNode * root);
public:
  Graph * root_;
};

}  // namespace graphvizwrapper

#endif // _GRAPHVIZ_H_
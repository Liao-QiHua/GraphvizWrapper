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

#include <iostream>
#include "include/nodes.h"
#include "include/types.h"


int test0() {
    using namespace std;
    using namespace graphvizwrapper;
    GGraph * graph = new GGraph(TNodeType::kDigraph, true);
    GNodeStmt * node_A = new GNodeStmt("A");
    GNodeStmt * node_B = new GNodeStmt("B");
    GNodeStmt * node_C = new GNodeStmt("C");
    //GAttributeList * attr_list = new GAttributeList();
    node_A->AddAttr("label", "As");
    node_A->AddAttr("color", "green");
    node_B->AddAttr("color", "red");
    graph->AddChild(node_A);
    graph->AddChild(node_B);
    //node_A->AddAttr()
    GEdgeStmt * edge_stmt1 = new GEdgeStmt(true);
    GEdgeStmt * edge_stmt2 = new GEdgeStmt(true);
    edge_stmt1->set_edge(node_A, node_B);
    edge_stmt2->set_edge(node_A, node_C);
    edge_stmt1->AddAttr("label", "True");
    edge_stmt2->AddAttr("label", "False");
    graph->AddChild(edge_stmt1);
    graph->AddChild(edge_stmt2);

    GGraph* subgraph = new GGraph(TNodeType::kSubGraph, true);
    GEdgeStmt * edge_stmt3 = new GEdgeStmt(true);
    GEdgeStmt * edge_stmt4 = new GEdgeStmt(true);
    edge_stmt3->set_edge(node_B, node_C);
    edge_stmt4->set_edge(node_B, node_A);
    subgraph->AddChild(edge_stmt3);
    subgraph->AddChild(edge_stmt4);
    graph->AddChild(subgraph);
    cout << graph->to_string();
    return 0;
}
int main() {
    return test0();
}

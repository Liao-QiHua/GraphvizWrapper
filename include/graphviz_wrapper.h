#ifndef _GRAPHVIZ_WRAPPER_H_
#define _GRAPHVIZ_WRAPPER_H_
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

#include "include/attribute_types.h"

namespace gvw {

class GGraph {};

class GSubGraph : public GGraph {};

class Node {};

class Cluster {};
// Add "attr" attribute to "obj" object.
template <typename ObjectType, typename AttibuteType>
void AddAttribute(ObjectType obj, AttibuteType attr);

//
void AddEdge(GGraph& graph, Node from, Node to,
             GArrowType arrowhead = GArrowType::kNormal,
             GArrowType arrowtail = GArrowType::kNormal,
             GDouble arrowsize = 1.0);

void AddSubGraph(GGraph& graph, GSubGraph subgraph);



class GraphvizWapper {
 public:
  GraphvizWapper() {}
};
}  // namespace gvw

#endif  // _GRAPHVIZ_WRAPPER_H_
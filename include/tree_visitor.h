#ifndef _TREE_VISITOR_H_
#define _TREE_VISITOR_H_

#include "include/nodes.h"

namespace graphvizwrapper {

class TreeVisitor {
public:
    virtual void visitAttrStmt(AttrStmt* node) = 0;
    virtual void visitEdgeStmt(EdgeStmt* node) = 0;
    virtual void visitGraph(Graph* node) = 0;
    virtual void visitIdAssignStmt(IdAssignStmt* node) = 0;
    virtual void visitNodeStmt(NodeStmt* node) = 0;
};

} // graphvizwrapper

#endif // _TREE_VISITOR_H_
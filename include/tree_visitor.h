#ifndef _TREE_VISITOR_H_
#define _TREE_VISITOR_H_

#include "include/nodes.h"

namespace graphvizwrapper {

class AttrStmt;
class EdgeStmt;
class Graph;
class IdAssignStmt;
class NodeStmt;

/*
+----------------------+                            +----------------------+
|   TreeVisitor        |                            |        TNode         |
+----------------------+                            +----------------------+
| +visit(AttrStmt*)    |<---------------------------| +accept(TreeVisitor*)|      
| +visit(EdgeStmt*)    |                            | +other               |
| +visit(Graph*)       |                            +----------------------+
| +visit(IdAssignStmt*)|                                       ▲ 
| +visit(NodeStmt*)    |                                       |
+----------------------+                  +--------------------+------------------------+
          ▲                               |                                             |
          |                               |                                             |
+----------------------+      +----------------------+               +----------------------------------------+
| DeleteVisitor        |      |    AttrStmt          |               |  EdgeStmt/Graph/IdAssignStmt/NodeStmt  |
+----------------------+      +----------------------+               +----------------------------------------+
| +visit(AttrStmt*)    |      | +accept(TreeVisitor*)|               | +accept(TreeVisitor*)                  |
| +visit(EdgeStmt*)    |      | +other               |               +----------------------------------------+
| +visit(Graph*)       |      +----------------------+
| +visit(IdAssignStmt*)|                              
| +visit(NodeStmt*)    |
+----------------------+

*/

class TreeVisitor {
 public:
  virtual void visitAttrStmt(AttrStmt* node) = 0;
  virtual void visitEdgeStmt(EdgeStmt* node) = 0;
  virtual void visitGraph(Graph* node) = 0;
  virtual void visitIdAssignStmt(IdAssignStmt* node) = 0;
  virtual void visitNodeStmt(NodeStmt* node) = 0;
};

class DeleterVisitor : public TreeVisitor {
 public:
  virtual void visitAttrStmt(AttrStmt* node) override;
  virtual void visitEdgeStmt(EdgeStmt* node) override;
  virtual void visitGraph(Graph* node) override;
  virtual void visitIdAssignStmt(IdAssignStmt* node) override;
  virtual void visitNodeStmt(NodeStmt* node) override;
};

}  // namespace graphvizwrapper

#endif  // _TREE_VISITOR_H_

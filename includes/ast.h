#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);
/*
  project 5 CallNode, FuncNode, SuiteNode
*/
class CallNode : public Node {
public:
  CallNode(const std::string id) : ident(id) { }
  virtual ~CallNode(){}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class FuncNode : public Node {
public:
  FuncNode(const std::string id, Node* stmts);
  virtual ~FuncNode(){ }
  const std::string getIdent const { return ident;}
  virtual const Literal* eval() const;
private:
  std::string ident;
  Node* suite;
};

class SuiteNode : public Node {
public:
  SuiteNode(const std::vevtor<Node*> s) : Node(), stmts(s) { }
  virtual ~SuiteNode() { }
  virtual const Literal* eval() const;
private:
  std::vector<Node*> stmts;
};

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};
class UnaryNode : public Node {
public:
  UnaryNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval() const = 0;
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node *node;
};

class PosUnaryNode : public UnaryNode {
public:
  PosUnaryNode(Node* node): UnaryNode(node){}
  virtual const Literal* eval() const;
};
class NegUnaryNode : public UnaryNode {
public:
  NegUnaryNode(Node* node) : UnaryNode(node) {}
  virtual const Literal* eval() const;
};


class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};
class PerBinaryNode : public BinaryNode {
public:
  PerBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};
class DbStarBinaryNode : public BinaryNode {
public:
  DbStarBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};
class DbSlashBinaryNode : public BinaryNode {
public:
  DbSlashBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

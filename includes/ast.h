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
  CallNode(const std::string id, const std::vector<Node*> args) : ident(id), arguments(args) { }
  virtual ~CallNode(){}
  const std::string getIdent() const { return ident; }
  const std::vector<Node*> getArgs() const { return this->arguments;}
  virtual const Literal* eval() const;
private:
  std::string ident;
  std::vector<Node*> arguments;
};

class FuncNode : public Node {
public:
  FuncNode(const std::string id, Node* stmts) : ident(id), suite(stmts) {  }
  FuncNode(const FuncNode&) = delete;
  const FuncNode* operator=(const FuncNode&) = delete;
  virtual ~FuncNode(){ }
  const std::string getIdent() const { return ident;}
  virtual const Literal* eval() const;
private:
  std::string ident;
  Node* suite;
};

class SuiteNode : public Node {
public:
  SuiteNode(const std::vector<Node*> s) : Node(), stmts(s), parameters(){ }
  virtual ~SuiteNode() { }
  virtual void setParameters(const std::vector<Node*> p)  { this->parameters = p; }
  virtual const Literal* evalParam(const std::vector<Node*> actual) const;
  virtual const Literal* eval() const;
private:
  std::vector<Node*> stmts;
  std::vector<Node*> parameters;
};

class ReturnNode : public Node {
public:
  ReturnNode(Node* n) : Node(), node(n), name("__return__") { }
  ReturnNode(const ReturnNode&) = delete;
  const ReturnNode* operator=(const ReturnNode&) = delete;
  virtual ~ReturnNode() {}
  virtual const Literal* eval() const;
private:
  Node* node;
  std::string name;
};

class PrintNode : public Node {
public:
  PrintNode(Node* n) : Node(), node(n) {}
  PrintNode(const PrintNode&) = delete;
  const PrintNode* operator=(const PrintNode&) = delete;
  virtual ~PrintNode() {}
  virtual const Literal* eval() const;
private:
  Node* node;
};

class IfNode : public Node{
public:
  IfNode(Node* te, Node* iSuite, Node* eSuite) : Node(), test(te), ifSuite(iSuite), elseSuite(eSuite){ }
  IfNode(const IfNode&) = delete;
  const IfNode* operator=(const IfNode&) = delete;
  virtual ~IfNode(){}
  virtual const Literal* eval() const;
private:
  Node* test;
  Node* ifSuite;
  Node* elseSuite;
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

class LessBinaryNode : public BinaryNode {
public:
  LessBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GrtBinaryNode : public BinaryNode {
public:
  GrtBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class EqeqBinaryNode : public BinaryNode {
public:
  EqeqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class GrteqBinaryNode : public BinaryNode {
public:
  GrteqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class LeseqBinaryNode : public BinaryNode {
public:
  LeseqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class NteqBinaryNode : public BinaryNode {
public:
  NteqBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};




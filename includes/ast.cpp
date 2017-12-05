#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "symbolTable.h"

const Literal* CallNode::eval() const{
  TableManager& tm = TableManager::getInstance();
  if(!tm.checkFunc(ident)){
    std::cout << "function " << ident << " NOT FOUND" << std::endl;
    std::exception up = std::exception();
    throw up;
  }
  tm.pushScope();
  tm.getSuite(ideent)->eval();
  tm.popScope();
  return nullptr;
}

FuncNode::FuncNode(const std::string id, Node* stmts) : Node(), ident(id), suite(stmts){
  TableManager::getInstance().insert(id, suite);
}

const Literal* FuncNode::eval() const{
  return nullptr;
}

const Literal* SuiteNode::eval() const{
  for(const Node* n : stmts){
    if(n) n->eval();
  }
  return nullptr;
}

const Literal* IdentNode::eval() const { 
  const Literal* val = SymbolTable::getInstance().getValue(ident);
  return val;
}

const Literal* PosUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  const Literal* res = node->eval()->operator+();
  return res;
}
const Literal* NegUnaryNode::eval() const { 
  if (!node) {
    throw "error";
  }
  const Literal* res = node->eval()->operator-();
  return res;
}
AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  SymbolTable::getInstance().setValue(n, res);
}


const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();

  return res;
}

const Literal* AddBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}
const Literal* PerBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));

}
const Literal* DbStarBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).DouStar(*y));

}
const Literal* DbSlashBinaryNode::eval() const{
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).DouSlash(*y));

}

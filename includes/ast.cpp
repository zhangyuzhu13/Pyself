#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "tableManager.h"

const Literal* CallNode::eval() const{
  TableManager& tm = TableManager::getInstance();
  if(!tm.checkFunc(ident)){
    std::cout << "function " << ident << " NOT FOUND" << std::endl;
    std::exception up = std::exception();
    throw up;
  }
  const Node* suiteNode = tm.getSuite(ident);
  tm.pushScope();
  dynamic_cast<const SuiteNode*>(suiteNode)->evalParam(arguments);
  const Literal* ret = suiteNode->eval();
  tm.popScope();
  return ret;
} 

const Literal* FuncNode::eval() const{
  TableManager::getInstance().insertFunc(ident, suite);
  return nullptr;
}

const Literal* SuiteNode::eval() const{
  if(stmts.empty()) return nullptr;
  for(const Node* n : stmts){
    if(n){
	   	n->eval();
		if(TableManager::getInstance().checkName("__return__")){
		return TableManager::getInstance().getEntry("__return__");
		}
	}
	else{ throw std::string("nullptr in suite");}
  }
  return nullptr;
}

const Literal* SuiteNode::evalParam(const std::vector<Node*> actual) const {
	if(parameters.size() != actual.size()){
		throw std::string("invalid parameter number ");
	}
	PoolOfNodes& pool = PoolOfNodes::getInstance();
	for(int i = 0; i < parameters.size(); i++){
		AsgBinaryNode* asg = new AsgBinaryNode(parameters[i], actual[i]);
		pool.add(asg);
		asg->eval();
	}
	return nullptr;
}

const Literal* PrintNode::eval() const {
  if(node){
	  const Literal* res = node->eval();
	  if(res) res->print();
  }
  return nullptr;
}

const Literal* ReturnNode::eval() const {

  if(node){
    const Literal* result = node->eval();
    TableManager::getInstance().insertSymb(name, result);
    return result;
  }
  else{
    const Literal* result = new IntLiteral(0); 
    TableManager::getInstance().insertSymb(name, result);
    return 0;
  }

}

const Literal* IfNode::eval()const {
  if(!test) return nullptr;
  const Literal* res = test->eval();
  if(!res) throw new std::string("if suitation is not correst");
  if(res->isTrue()){
    ifSuite->eval();
  }
  else if(elseSuite){
    elseSuite->eval();
  }
  return nullptr;
}

const Literal* IdentNode::eval() const { 
  const Literal* val = TableManager::getInstance().getEntry(ident);
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
  
}


const Literal* AsgBinaryNode::eval() const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().insertSymb(n, res);
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

const Literal* LessBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).Less(*y));
}
const Literal* GrtBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).Grt(*y));;
}
const Literal* EqeqBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).Eqeq(*y));;
}
const Literal* LeseqBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).LessEq(*y));
}
const Literal* GrteqBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).GrtEq(*y));
}
const Literal* NteqBinaryNode::eval() const {
  if(!left || !right){
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x).NotEq(*y));
}





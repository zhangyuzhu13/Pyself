#include <iostream>
#include <string>
#include <map>
#include "functionTable.h"
#include "literal.h"
bool FunctionTable::found(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = functions.find(name);
  if ( it == functions.end() ){ return false;}
  else{ return true; }

}

void FunctionTable::insert(const std::string& name, const Node* suite){
  functions[name] = suite;
}

const Node* FunctionTable::getSuite(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it = functions.find(name);
  if ( it == functions.end() ){ throw std::string(" not found!!");}
  return it->second; 
}


















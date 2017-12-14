#include <vector>
#include <iostream>
#include "tableManager.h"


TableManager& TableManager::getInstance(){
  static TableManager manager;
  return manager; 
}

const Literal* TableManager::getEntry(const std::string& name){
 std::vector<SymbolTable>::reverse_iterator rit = tables.rbegin();
  for(; rit != tables.rend(); ++rit){
    if(rit->found(name))
      return rit->getEntry(name);
  }
  if(rit == tables.rend()) throw name+std::string(" not found");
  return nullptr;
}
const Node* TableManager::getSuite(const std::string& name){
 std::vector<FunctionTable>::reverse_iterator rit = functions.rbegin();
  for(; rit != functions.rend(); ++rit){
    if(rit->found(name))
      return rit->getSuite(name);
  }
  if(rit == functions.rend()) throw name+std::string(" not found");
  return nullptr;
}

void TableManager::insertSymb(const std::string& name, const Literal* node){ 
  tables[currentScope].insert(name, node);
}

void TableManager::insertFunc(const std::string& name, const Node* node){
  functions[currentScope].insert(name, node);
  
}

bool TableManager::checkName(const std::string& name)  {
  
  std::vector<SymbolTable>::reverse_iterator rit = tables.rbegin();
  for(; rit != tables.rend(); ++rit){
    if(rit->found(name))
      return true;
  }
  return false;
}

bool TableManager::checkFunc(const std::string& name) {
 
  std::vector<FunctionTable>::reverse_iterator rit = functions.rbegin();
  for(; rit != functions.rend(); ++rit){
    if(rit->found(name))
      return true;
  }
  return false;
}
void TableManager::pushScope(){
  functions.push_back(FunctionTable());
  tables.push_back(SymbolTable());
  currentScope++;
}

void TableManager::popScope(){
  functions.pop_back();
  tables.pop_back();
  currentScope--;
}





















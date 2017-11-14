#include <cmath>
#include <iostream>
#include "node.h"
#include "poolOfNodes.h"

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(float) const =0;
  virtual const Literal* opDiv(int) const =0;
  
  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opPer(float) const =0;
  virtual const Literal* opPer(int) const =0;
  
  virtual const Literal* DouStar(const Literal& rhs) const =0;
  virtual const Literal* opDouStar(float) const =0;
  virtual const Literal* opDouStar(int) const =0;
  
  virtual const Literal* DouSlash(const Literal& rhs) const =0;
  virtual const Literal* opDouSlash(float) const =0;
  virtual const Literal* opDouSlash(int) const =0;
  
  virtual const Literal* operator+() const = 0;
  virtual const Literal* operator-() const = 0;
  
  virtual const Literal* operator+=(const Literal& rhs) const = 0;
  virtual const Literal* operator-=(const Literal& rhs) const = 0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opPer(val);
  }
  virtual const Literal* opPer(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(fmod(lhs, val) + val, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPer(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(fmod(lhs, val) + val, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* DouStar(const Literal& rhs) const  {
    return rhs.opDouStar(val);
  }
  virtual const Literal* opDouStar(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouStar(int lhs) const  {
    const Literal* node = new FloatLiteral(pow(static_cast<float>(lhs), val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* DouSlash(const Literal& rhs) const  {
    return rhs.opDouSlash(val);
  }
  virtual const Literal* opDouSlash(float lhs) const  {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouSlash(int lhs) const  {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  virtual const Literal* operator+() const { 
    const Literal* node = new FloatLiteral(val);
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  virtual const Literal* operator-() const { 
    const Literal* node = new FloatLiteral(-val);
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  virtual const Literal* operator+=(const Literal& rhs) const {
  	return rhs.opPlus(val);
  }
  virtual const Literal* operator-=(const Literal& rhs) const {
    return rhs.opSubt(val);
  }
  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "FLOAT: " << val << std::endl; 
  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
 IntLiteral(int _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(floor((float)lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opPer(val);
  }
  virtual const Literal* opPer(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(fmod(lhs, val) + val, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPer(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(fmod(fmod(lhs, val) + val, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* DouStar(const Literal& rhs) const  {
    return rhs.opDouStar(val);
  }
  virtual const Literal* opDouStar(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(static_cast<float>(lhs), val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouStar(int lhs) const  {
    const Literal* node = new IntLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

 virtual const Literal* DouSlash(const Literal& rhs) const  {
    return rhs.opDouSlash(val);
  }
  virtual const Literal* opDouSlash(float lhs) const  {
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouSlash(int lhs) const  {
    const Literal* node = new IntLiteral(static_cast<float>(floor(lhs / val)));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator+() const { 
    const Literal* node = new IntLiteral(val);
  
    PoolOfNodes::getInstance().add(node);
	return node;
  }
  virtual const Literal* operator-() const { 
    const Literal* node = new IntLiteral(-val);
    PoolOfNodes::getInstance().add(node);
	return node;
  }

  virtual const Literal* operator+=(const Literal& rhs) const {
  	return rhs.opPlus(val);
  }
  virtual const Literal* operator-=(const Literal& rhs) const {
  	return rhs.opSubt(val);
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << "INT: " << val << std::endl; 
  }
private:
  int val;
};


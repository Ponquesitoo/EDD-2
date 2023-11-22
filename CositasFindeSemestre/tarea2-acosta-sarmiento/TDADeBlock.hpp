#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#pragma once

class DeBlock{
  private:
    int cant_elems;
    tListadeListas L;
  public: 
    DeBlock(tElem* elems, int n, int b);
    ~DeBlock();
    int insert(int pos, tElem elem);
    tElem get_value(int pos);
    int length();
    void clear();
};

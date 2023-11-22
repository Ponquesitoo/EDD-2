#include <iostream>
#include "TDAlista.hpp"
using namespace std;

#pragma once

class tListadeListas{
  private:
    long int maxSize;
    int listSize;
    int curr;
    tLista* listArray;

  public:
    tListadeListas(); 
    ~tListadeListas(); 
    void clear(); 
    int Insert_block(int pos, tElem elem);
    int append(tLista &lista); ;
    void moveToStart(); 
    void moveToEnd(); 
    void moveToPos(int pos); 
    void next(); 
    int Length(); 
    int Length_block();
    tLista* GetValue();
    tElem GetValue_block(int pos);
};


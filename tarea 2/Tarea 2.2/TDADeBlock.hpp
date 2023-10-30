#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#pragma once

class DeBlock{
  private:
    int cant_elems;
    tListadeListas L;
  public: 
    DeBlock(tElem* elems, int n, int b); //listo
    ~DeBlock();
    int insert(int pos, tElem elem); // listo
    //tElem erase(int pos);
    tElem get_value(int pos); //listo
    int length(); //listo
    void clear(); //listo
    void print();
};

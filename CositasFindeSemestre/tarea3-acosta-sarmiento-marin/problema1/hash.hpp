#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
# include <string>
using namespace std;

const int tamano = 32;

class Hashing{
	private:
		struct ranuras{
			string clave;
			string info;
		};
  ranuras tabla[tamano];

	int resolucion(string infoo){
    int largo, newPos;
    int pos = 0;
    int pos1 = 0;
    int i = 1;
    largo = infoo.length();

    //hash 1
    for (int j = 0; j < largo; j++){
      pos = pos + (int)infoo[j];
      pos = (pos + (3*j)) % tamano;
    }
    pos = pos % tamano; 
    
    //hash 2
    for (int j = 0; j < largo; j++){
      pos1 = pos1 + (int)infoo[j]*(j+1);
    }
    pos1 = pos1 % tamano;
    
    //resolucion
    newPos = (pos + i*pos1) % tamano;
    while (tabla[pos].clave != ""){
      i++;
      newPos = (pos + i*pos1) % tamano;
      if (i >= tamano) {  // Evitar bucle infinito
      // No se encontró una ranura vacía en la tabla
        return -2;
      }
    }
    return newPos;
  }

	public:
      /*****
  *  void Insertar
  ******
  *  Inserta un elemento en la tabla hash
  ****** 
  *Input: 
  *  string infoo : nombre del usuario
  *  string contrasena : contrasena del usuario
  ******
  *Returns: 
  *  No retorna
  *****/
    Hashing(){
      for (int i = 0; i < tamano; i++){
        tabla[i].clave = "";
        tabla[i].info = "";   
      }
    }
    
  /*****
  *  void Insertar
  ******
  *  Inserta un elemento en la tabla hash
  ****** 
  *Input: 
  *  string infoo : nombre del usuario
  *  string contrasena : contrasena del usuario
  ******
  *Returns: 
  *  No retorna
  *****/

		~Hashing(){



    }

		void Insertar(string infoo, string clave); //se le asigna una clave que corresponde a la posicion
		int Buscar(string clave);
    int Buscador(string clave, string infoo);
		void Clear();
    void Actualizar(string clave, string nueva_contrasena);

};
  /*****
  *  void Insertar
  ******
  *  Inserta un elemento en la tabla hash
  ****** 
  *Input: 
  *  string infoo : nombre del usuario
  *  string contrasena : contrasena del usuario
  ******
  *Returns: 
  *  No retorna
*****/
void Hashing::Insertar(string infoo, string contraseña){
  int largo;
  int pos = 0;
  largo = infoo.length();
  for (int i = 0; i < largo; i++){
    pos = pos + (int)infoo[i];  
  }
  pos = pos % tamano;
  if (tabla[pos].clave != ""){
    while (tabla[pos].clave != ""){
      pos = resolucion(infoo);
    }  
  }
  tabla[pos].info = contraseña;
  tabla[pos].clave = infoo;
}

/*****
*  int Buscar
******
*  Busca un usuario en la tabla
****** 
*Input: 
*  string clave : Usuario que se desea buscar
******
*Returns: 
*  int. La posicion del elemento en la tabla. En caso de no encontrarlo, retorna -1
*****/
int Hashing::Buscar(string clave){
  for (int i = 0; i < tamano; i++){
    if (tabla[i].clave == clave){
      return i;
    }
  }
  return -1;
}
  /*****
  *  int Buscador
  ******
  *  Revisa la existencia de un usuario con su respectiva contrasena
  ****** 
  *Input: 
  *  string clave : Usuario que se esta buscando
  *  string infoo : Contrasena del usuario
  ******
  *Returns: 
  *  int. Retorna 0 si el usuario no existe, -2 si es que la contrasena no coindice con la ingresada, 1 si la clave y la contrasena de la posicion coincidan con las ingresadas y -3 si es que no ocurre nada de lo anterior.
  *****/
int Hashing::Buscador(string clave, string infoo){
    int i = Buscar(clave);
    if (i == -1){
      return 0;
    }
    else{
      if (tabla[i].info != infoo){
        return -2;
      }
      if (tabla[i].clave != clave && tabla[i].info == infoo){
        return 1;
      }
      return -3;
    }  
  }

  /*****
  *  void Clear
  ******
  *  Vacía la talba
  ****** 
  *Input: 
  *  No tiene parametros
  ******
  *Returns: 
  *  No tiene retorno.
  *****/

  void Hashing::Clear(){
    for (int i = 0; i < tamano; i++){
      tabla[i].clave = "";
      tabla[i].info = "";
    }
  }
  /*****
  *  void Actualizar
  ******
  *  Actualiza la contrasena del usuario
  ****** 
  *Input: 
  *  string clave : Usuario al que se le desea cambiar la contrasena
  *  string nueva_contrasena : contrasena nueva
  ******
  *Returns: 
  *  No tiene retorno.
  *****/
void Hashing::Actualizar(string clave, string nueva_contrasena){
  int i = Buscar(clave);
  if (i != -1){
    tabla[i].info = nueva_contrasena;
  }
}


#endif
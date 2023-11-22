#include <string>
#include "hash.hpp"
#include <iostream>


#ifndef TDA_HPP
#define TDA_HPP

using namespace std;

Hashing hashi;

class Login{
private:
  struct user{
    string usuario;
    string contrasena;
  };

public:
  Login();
  ~Login();
  bool iniciar_sesion(string usuario, string contrasena);
  bool crear_nuevo_usuario(string usuario, string contrasena);
  bool cambiar_clave(string usuario, string nueva_contrasena);
};

/*****
*  Login::Login
******
*  Constructor de la clase Login
****** 
*Input: 
* No tiene parámetros
******
*Returns: 
*  No retorna
*****/
Login::Login(){
  user usuarioo;
  usuarioo.usuario = "";
  usuarioo.contrasena = "";
}

/*****
*  bool iniciar_sesion
******
*  Es una funcion que dependiendo de si el usuario existe, no existe o existe el usuario pero la contraseña es diferente, tiene un retorno diferente
****** 
*Input: 
*  string usuario : nombre del usuario
*  string contrasena : contrasena del usuario
******
*Returns: 
*  true or false dependiendo de las condiciones
*****/
bool Login::iniciar_sesion(string usuario, string contrasena) {
  int resultado = hashi.Buscador(usuario, contrasena);

  if (resultado == 0){
    cout << "El usuario no se encuentra registrado." << endl;
    return false; 
  }
  if (resultado == -2){
    cout << "La clave ingresada no coincide." << endl;
    return false; 
  }
  else{
    cout << "Sesion iniciada con exito" << endl;
    return true;
  }
}
/*****
*  bool crear_nuevo_usuario
******
*  Si el usuario existe, confirma la existencia del mismo, y si no existe, crea un nuevo usuario.
****** 
*Input: 
*  string usuario : nombre del usuario
*  string contrasena : contrasena del usuario
******
*Returns: 
*  true si no se encuentra registrado
* false si se encuentra registrado
*****/
bool Login::crear_nuevo_usuario(string usuario, string contrasena){
  
  if (usuario.length() > 32){
    cout<<"El usuario excede el limite de caracteres."<<endl;
  }
  if (contrasena.length() < 8){
    cout<<"La clave debe tener minimo de 8 caracteres."<<endl;
  }
    
  if (hashi.Buscar(usuario) == -1 && usuario.length() <= 32 && contrasena.length() >= 8 ){
    hashi.Insertar(usuario, contrasena);
    cout<<"Usuario registrado con exito."<<endl;
    return true;
  }
  if(hashi.Buscar(usuario) != -1){
    cout<<"El usuario ya se encuentra registrado."<<endl;
    return false;
  }
  return false;
}
/*****
*  bool cambiar_clave
******
*  Una funcion que a grandes rasgos permite cambiar la contraseña del usuario
****** 
*Input: 
*  string usuario : nombre del usuario
*  string nueva_contrasena : nueva contrasena del usuario
******
*Returns: 
*  No retorna
*****/
bool Login::cambiar_clave(string usuario, string nueva_contrasena){
  if (hashi.Buscar(usuario) == -1){
    cout<<"El usuario no se encuentra registrado."<<endl;
    return false;
  }else {
    if (nueva_contrasena.length() < 8){
      cout<<"La clave debe tener un minimo de 8 caracteres."<<endl;
      return false;
    }  
    if (nueva_contrasena.length() >= 8){
      hashi.Actualizar(usuario, nueva_contrasena);
      cout<<"Clave actualizada con exito."<<endl;
      return true;
    }
    return false;      
  }
}  
/*****
* Login::~login
******
*  Es el destructor de la clase Login
****** 
*Input: 
* No tiene parámetros
******
*Returns: 
*  No retorna
*****/
Login::~Login(){


}

#endif
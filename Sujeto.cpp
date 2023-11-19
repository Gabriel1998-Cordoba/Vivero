#include<iostream>
#include <cstring>

using namespace std;

#include"Sujeto.h"

//Tipo_Docu Sujeto::getTipoDoc() const { return _TipoDoc; }
//void Sujeto::setTipoDoc(const Tipo_Docu &TipoDoc) { _TipoDoc = TipoDoc; }

const char*Sujeto::getTelefono() const { return _telefono; }
void Sujeto::setTelefono(const char* telefono) { strcpy(_telefono, telefono);}

bool Sujeto::getEstado() const { return _estado; }
void Sujeto::setEstado(bool estado) { _estado = estado; }

//Direccion direccion() const { return _direccion; }
//void setDireccion(const Direccion &direccion) { _direccion = direccion; }

const char* Sujeto::getEmail() const { return _email; }
void Sujeto::setEmail(const char* email) { strcpy(_email, email);}

void Sujeto::CargarSujeto(){ //HACER

}
void Sujeto::MostrarSujeto(){ //HACER

}
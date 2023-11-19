#include<iostream>
#include <cstring>

using namespace std;

#include"Direccion.h"
#include"FuncionesGlobales.h"

// Calle
const char* Direccion::getCalle() const { return _calle; }
void Direccion::setCalle(const char* calle) { strcpy(_calle, calle); }

// Numero
int Direccion::getNumero() const { return _numero; }
void Direccion::setNumero(int numero) { _numero = numero; }

// Ciudad
const char* Direccion::getCiudad() const { return _ciudad; }
void Direccion::setCiudad(const char* ciudad) { strcpy(_ciudad, ciudad); }

// Codigo Postal
const char* Direccion::getCP() const { return _CP; }
void Direccion::setCP(const char* CP) { strcpy(_CP, CP); }

// Provincia
const char* Direccion::getProvincia() const { return _provincia; }
void Direccion::setProvincia(const char* provincia) { strcpy(_provincia, provincia); }
// Pais
const char* Direccion::getPais() const { return _pais; }
void Direccion::setPais(const char* p) { strcpy(_pais, p);}

void Direccion::CargarDireccion(){

char calle[30];
int numero;
char ciudad[30];
char CP[30]; //Codigo Postal
char provincia[30];
char pais[30];

cout<<"Su Calle es: ";
cargarCadena(calle,30);
setCalle(calle);

cout<<"Su numero es: ";
cin>>numero;
setNumero(numero);

cout<<"Su ciudad es: ";
cargarCadena(ciudad,30);
setCiudad(ciudad);

cout<<"Su Codigo Postal es: ";
cargarCadena(CP,30);
setCP(CP);

cout<<"Su provincia es: ";
cargarCadena(provincia,30);
setProvincia(provincia);

cout<<"Su pais es: ";
cargarCadena(pais,30);
setPais(pais);


}
void Direccion::MostrarDireccion(){

cout<<"Su Calle es: "<<getCalle()<<endl;
cout<<"Su numero es: "<<getNumero()<<endl;
cout<<"Su ciudad es: "<<getCiudad()<<endl;
cout<<"Su Codigo Postal es: "<<getCP()<<endl;
cout<<"Su provincia es: "<<getProvincia()<<endl;
cout<<"Su pais es: "<<getPais()<<endl<<endl;

}
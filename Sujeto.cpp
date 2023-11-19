#include<iostream>
#include <cstring>

using namespace std;

#include"Sujeto.h"
#include"FuncionesGlobales.h"

int Sujeto::getIdSujeto() const { return _idSujeto; }
void Sujeto::setIdSujeto(int idSujeto) { _idSujeto = idSujeto; }

// Tipo_Docu Sujeto::getTipoDoc() const { return _TipoDoc; }
// void Sujeto::setTipoDoc(const Tipo_Docu &TipoDoc) { _TipoDoc = TipoDoc; }

const char*Sujeto::getTelefono() const { return _telefono; }
void Sujeto::setTelefono(const char* telefono) { strcpy(_telefono, telefono);}

bool Sujeto::getEstado() const { return _estado; }
void Sujeto::setEstado(bool estado) { _estado = estado; }

// Direccion direccion() const { return _direccion; }
// void setDireccion(const Direccion &direccion) { _direccion = direccion; }

const char* Sujeto::getEmail() const { return _email; }
void Sujeto::setEmail(const char* email) { strcpy(_email, email);}

void Sujeto::CargarSujeto(int totalDeRegistros,int TipoDeArticulo){ //HACER

char telefono[30];
bool estado;
char email[30];

Fecha::Cargar();
Tipo_Docu::CargarTipoDocu();
Direccion::CargarDireccion();

    totalDeRegistros++;
    cout << "id Sujeto : " << totalDeRegistros<< endl;
    setIdSujeto(totalDeRegistros);
    
    cout<<"Su telefono es: ";
    cargarCadena(telefono,30);
    setTelefono(telefono);

    cout<<"Su estado es: ";
    cin>>estado;
    setEstado(estado);

    cout<<"Su email es: ";
    cargarCadena(email,30);
    setTelefono(email);
    

}
void Sujeto::MostrarSujeto(){ //HACER

Fecha::MostrarEnLinea();
Tipo_Docu::MostrarTipoDocu();
Direccion::MostrarDireccion();

    cout<<"id Sujeto : "<<getIdSujeto()<<endl;;
    cout<<"Su telefono es: "<<getTelefono()<<endl;
    cout<<"Su estado es: "<<getEstado()<<endl;
    cout<<"Su email es: "<<getEmail()<<endl<<endl;

}
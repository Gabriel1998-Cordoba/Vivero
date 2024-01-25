#include<iostream>
#include <cstring>

using namespace std;

#include"Sujeto.h"
#include"FuncionesGlobales.h"


//Tipo_Docu Sujeto::getTipoDoc() const { return _TipoDoc; }
//void Sujeto::setTipoDoc(const Tipo_Docu &TipoDoc) { _TipoDoc = TipoDoc; }

//int Sujeto::getIdSujeto() const { return _idSujeto; }
//void Sujeto::setIdSujeto(int idSujeto) { _idSujeto = idSujeto; }


const char*Sujeto::getTelefono() const { return _telefono; }
void Sujeto::setTelefono(const char* telefono) { strcpy(_telefono, telefono);}

bool Sujeto::getEstado() const { return _estado; }
void Sujeto::setEstado(bool estado) { _estado = estado; }



const char* Sujeto::getEmail() const { return _email; }
void Sujeto::setEmail(const char* email) { strcpy(_email, email);}

void Sujeto::CargarSujeto(int totalDeRegistros/*,int TipoDeArticulo*/){ //HACER


char telefono[30];
bool estado;
char email[30];
cout<<"FECHA DE NACIMIENTO: "<<endl;
_fecha.Cargar();//hay que tomarla del sistema
//hacer una funcion para cargar la fecha

_TipoDoc.CargarTipoDocu();

_direccion.CargarDireccion();

    // totalDeRegistros++;
    // cout << "id Sujeto : " << totalDeRegistros<< endl;
    // setIdSujeto(totalDeRegistros);
    
    cout<<"Su telefono es: ";
    cargarCadena(telefono,30);
    setTelefono(telefono);

    estado=true;
    cout<<"Su estado es: "<<estado<<endl;
    setEstado(estado);

    cout<<"Su email es: ";
    cargarCadena(email,30);
    setEmail(email);
    

}
void Sujeto::MostrarSujeto(){ //HACER

_fecha.MostrarEnLinea();
_TipoDoc.MostrarTipoDocu();
_direccion.MostrarDireccion();

    // cout<<"id Sujeto : "<<getIdSujeto()<<endl;;
    cout<<"Su telefono es: "<<getTelefono()<<endl;
    cout<<"Su estado es: "<<getEstado()<<endl;
    cout<<"Su email es: "<<getEmail()<<endl<<endl;

}
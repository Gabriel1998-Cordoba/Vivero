#include <iostream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "FuncionesGlobales.h"

void Cliente:: setIDCliente(int idCliente)
{
    _idCliente;

}
void Cliente:: setApellido(const char * apellido)
{
    strcpy(_apellido,apellido);
}
int Cliente:: getIDCliente()
{
    return _idCliente;
}
const char * Cliente:: getApellido()
{
    return _apellido;
}
void Cliente::  Cargar()
{
    int idcliente;
    char apellido[50];
    cout<<"INGRESE LOS SIGUIENTES DATOS: "<<endl;
    cout <<" ID CLIENTE: ";
    cin>>idcliente;
    setIDCliente(idcliente);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,50);
    setApellido(apellido);
    Sujeto::MostrarSujeto();

}
void Cliente::  Mostrar(){
    cout<<"ID Cliente: "<<getIDCliente()<<endl;
    cout<<"Apellido: "<<getApellido()<<endl;
    Sujeto::MostrarSujeto();
}
bool Cliente::GuardarArchivo()
{
       FILE *p;
    p=fopen("Cliente.dat","ab");
    if(p==NULL)
    {

        return false;
    }
    bool escribio=fwrite(this,sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}
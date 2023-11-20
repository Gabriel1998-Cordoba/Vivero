#include <iostream>
#include <cstring>
using namespace std;
#include "FuncionesGlobales.h"
#include "RegistroCompra.h"

void RegistroCompra:: setIdCompra(int idcompra)
{
    _idCompra=idcompra;
}
void RegistroCompra::setIdProveedor (int idProveedor ){
    _idProveedor=idProveedor;
}
void RegistroCompra::setFecha (Fecha fechita){
    _Fecha=fechita;
}
void RegistroCompra:: setModoDePago (const char *modoDePago){
   strcpy(_modoDePago,modoDePago);
}
int RegistroCompra::getIdCompra(){return _idCompra;}
int RegistroCompra::getIdProveedor(){return _idProveedor;}
Fecha RegistroCompra::getFecha(){return _Fecha;}
const char * RegistroCompra:: getModoDePago(){return _modoDePago;}
void RegistroCompra::Cargar()
{
    int idCompra,idProveedor;
    Fecha f;
    char modoDePago[30];
    cout<<"Cargar los siguientes datos: "<<endl;
    cout<<"ID Compra: ";
    cin>>idCompra;
    setIdCompra(idCompra);
    cout<<"ID Proveedor: ";
    cin>>idProveedor;
    setIdProveedor(idProveedor);
    cout<<"Fecha: ";
    f.Cargar();
    setFecha(f);
    cout<<"Modo De Pago: ";
cargarCadena(modoDePago,30);
setModoDePago(modoDePago);


}
void RegistroCompra::Mostrar()
{
    cout<<"ID COMPRA: "<<getIdCompra();
    cout<<"ID PROVEEDOR: "<<getIdProveedor();
    cout<<"FECHA: ";
    _Fecha.Mostrar();
    cout<<"MODO DE PAGO: "<<getModoDePago();
}
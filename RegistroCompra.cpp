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
void RegistroCompra::setFecha (int dia,int mes,int anio){
    _Fecha.setDia(dia);
    _Fecha.setMes(mes);
    _Fecha.setAnio(anio);
}
void RegistroCompra:: setModoDePago (const char *modoDePago){
   strcpy(_modoDePago,modoDePago);
}
int RegistroCompra::getIdCompra(){return _idCompra;}
int RegistroCompra::getIdProveedor(){return _idProveedor;}
Fecha RegistroCompra::getFecha(){return _Fecha;}
const char * RegistroCompra:: getModoDePago(){return _modoDePago;}

void RegistroCompra::CargarCompra()
{
//     int idCompra,idProveedor;
//     Fecha f;
//     char modoDePago[30];
//     cout<<"Cargar los siguientes datos: "<<endl;
//     cout<<"ID Compra: ";
//     cin>>idCompra;
//     setIdCompra(idCompra);
//     cout<<"ID Proveedor: ";
//     cin>>idProveedor;
//     setIdProveedor(idProveedor);
//     cout<<"Fecha: ";
//     f.Cargar();
//     setFecha(f);
//     cout<<"Modo De Pago: ";
// cargarCadena(modoDePago,30);
// setModoDePago(modoDePago);

    int idCompra,idProveedor;
    Fecha f;
    char modoDePago[30];
    cout<<"Cargar los siguientes datos: "<<endl;

    RegistroCompra objR;
    int tam=0;

    tam = objR.contarRegistros();
    if(tam==0){
        tam=1;
    }
   objR.setIdCompra(tam);
    cin>>idProveedor;
    setIdProveedor(idProveedor);
    cout<<"Fecha: ";
    f.Cargar();
    setFecha(f);
    cout<<"Modo De Pago: ";
cargarCadena(modoDePago,30);
setModoDePago(modoDePago);

}

// void RegistroCompra::CargarCompra(Planta obj){
// }

void RegistroCompra::Mostrar()
{
    cout<<"ID COMPRA: "<<getIdCompra();
    cout<<"ID PROVEEDOR: "<<getIdProveedor();
    cout<<"FECHA: ";
    _Fecha.Mostrar();
    cout<<"MODO DE PAGO: "<<getModoDePago();
}

int RegistroCompra::contarRegistros(){
        FILE *p;
        p=fopen("registrocompra.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(RegistroCompra);
    }
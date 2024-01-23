#include <iostream>
#include <cstring>
using namespace std;

#include "RegistroVenta.h"

void RegistroVenta:: setIdVenta(int idVenta)
{
    _idVenta=idVenta;
}
void RegistroVenta::setIdCliente (int idCliente ){
    _idCliente=idCliente;
}
void RegistroVenta::setFecha (Fecha fechita){
    _fecha=fechita;
}
void RegistroVenta::setFecha (int dia,int mes,int anio){
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
}
void RegistroVenta:: setModoDePago (const char *modoDePago){
   strcpy(_modoDePago,modoDePago);
}
int RegistroVenta::getIdVenta(){return _idVenta;}
int RegistroVenta::getIdCliente(){return _idCliente;}
Fecha RegistroVenta::getFecha(){return _fecha;}
const char * RegistroVenta:: getModoDePago(){return _modoDePago;}

void RegistroVenta::CargarCompra()
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

    int idVenta,idCliente;
    Fecha f;
    char modoDePago[30];
    cout<<"Cargar los siguientes datos: "<<endl;

    RegistroVenta objR;
    int tam=0;

    tam = objR.contarRegistros();
    tam++;

    setIdVenta(tam);
    cout<<"Proveedor: ";
    cin>>idCliente;
    setIdCliente(idCliente);
    cout<<"Fecha: ";
    f.Cargar();
    setFecha(f);
    cout<<"Modo De Pago: ";
cargarCadena(modoDePago,30);
setModoDePago(modoDePago);



}



void RegistroVenta::Mostrar()
{
    cout<<"ID COMPRA: "<<getIdVenta()<<endl;
    cout<<"ID PROVEEDOR: "<<getIdCliente()<<endl;
    _fecha.MostrarEnLinea();
    cout<<"MODO DE PAGO: "<<getModoDePago()<<endl<<endl;
}

int RegistroVenta::contarRegistros(const char* nombre){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1; //cambie el 0 por un -1, por si no ahi ningun registro me devuelva -1
                               //Fijate gabi si esto no afecta a otra parte del programa
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(RegistroVenta);
    }

void RegistroVenta::CargarArchivoVenta(){
FILE *p;
RegistroVenta ClassM;

p=fopen("registroVenta.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarCompra();

fwrite(&ClassM,sizeof (RegistroVenta),1,p);

fclose(p);


}

RegistroVenta RegistroVenta::leerRegistro(int pos,const char * nombre)
{
    RegistroVenta reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
        return reg;
    fseek(p, sizeof(RegistroVenta) * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

void RegistroVenta::MostrarArchivoVenta(){
RegistroVenta ClassM;
FILE *p;

p=fopen("registroVenta.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (RegistroVenta),1,p)==1){
ClassM.Mostrar();
}

fclose(p);
}
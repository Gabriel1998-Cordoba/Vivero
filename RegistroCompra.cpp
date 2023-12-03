#include <iostream>
#include <cstring>
using namespace std;
#include "FuncionesGlobales.h"
#include "RegistroCompra.h"

void RegistroCompra:: setIdCompra(int idcompra)
{
    _idCompra=idcompra;
}
void RegistroCompra::setIdCliente (int idcliente ){
    
    
    _idCliente=idcliente;
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
int RegistroCompra::getIdCliente(){return _idCliente;}
Fecha RegistroCompra::getFecha(){return _Fecha;}
const char * RegistroCompra:: getModoDePago(){return _modoDePago;}

void RegistroCompra::CargarCompra(int idCompra,int idcliente)//Desarrollar int idcompra,int idcliente
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


    //if(Existe()) A DESARROLLAR, NO PODEMOS TENER IDS REPETIDOS AL GUARDAR ARCHIVO
  setIdCompra(idCompra);
  setIdCliente(idcliente);
    Fecha f;
    char modoDePago[30];

    cout<<"Cargar los siguientes datos: "<<endl;

    // RegistroCompra objR;
    // int tam=0;

    // tam = objR.contarRegistros();
    // tam++;

    //setIdCompra(/*idCompra*/);
//    cout<<"Proveedor: ";
//     cin>>idProveedor;          setIdcliente(idcliente)  
// setIdProveedor(idProveedor);

    cout<<"Fecha: "<<endl;
    f.Cargar();
    setFecha(f);

int band=false;
do{
cout<<"Ingrese los siguentes metodos de pago: efectivo,debido,credito :"<<endl;
cargarCadena(modoDePago,30);
strlwr(modoDePago);

if(strcmp(modoDePago, "efectivo") == 0 || strcmp(modoDePago, "debito") == 0 || strcmp(modoDePago, "credito") == 0){
    band=true;
}else{
    cout<<"El Modo De Pago: "<<modoDePago<<endl;
    cout<<"Ingresado no existe, vuelva a ingresar"<<endl<<endl;
}

}while(band==false);

setModoDePago(modoDePago);






// cout<<"Ingrese Tipo de Documento"<<endl;
// cout<<"(1 DNI, 2 Cuit, 3 Cuil)"<<endl;
// int numero,tipo;
// cin>>tipo;
// cout<<"Ingrese numero"<<endl;
// cin>>numero;




// getSujeto().getTipoDoc().setTipoDocu(tipo,numero);
// setSujeto(_Sujeto);
// cout<<"<<getSujeto().getTipoDoc().getTipoDoc(tipo)<<endl : "<<getSujeto().getTipoDoc().getTipoDocu(tipo)<<endl;
// //tengo que hacer un set_Sujeto(_Sujeto);

// getSujeto().getTipoDoc().setIndice(tipo);
// setSujeto(_Sujeto);

// cout<<"getSujeto().getTipoDoc().getIndice()<<endl; : "<<getSujeto().getTipoDoc().getIndice()<<endl;
// //tengo que hacer un set_Sujeto(_Sujeto);
// // setSujeto(_Sujeto);

system("pause");
}



void RegistroCompra::Mostrar()
{
    cout<<"ID COMPRA: "<<getIdCompra()<<endl;
    cout<<"ID PROVEEDOR: "<<getIdCliente()<<endl;
    _Fecha.MostrarEnLinea();
    cout<<"MODO DE PAGO: "<<getModoDePago()<<endl<<endl;
    
    //int indice = getSujeto().getTipoDoc().getIndice();
    //cout<<"Tipo Documento "<<indice<<" : "<<getSujeto().getTipoDoc().getTipoDocu(indice)<<endl;

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

bool RegistroCompra::GuardarCompra(){
FILE *p;
// RegistroCompra ClassM;Se activa el guardado del archivo cuando el obj  llama al metodo

p=fopen("registrocompra.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
    return false;
}


// ClassM.CargarCompra();

bool escribio=fwrite(/*&ClassM*/this,sizeof (RegistroCompra),1,p);

fclose(p);
return escribio;

}

void RegistroCompra::MostrarArchivoCompra(){
RegistroCompra ClassM;
FILE *p;

p=fopen("registrocompra.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (RegistroCompra),1,p)==1){
ClassM.Mostrar();
}

fclose(p);
}

RegistroCompra RegistroCompra::leerRegistro(int pos){
        RegistroCompra reg;
        FILE *p;
        p=fopen("registrocompra.dat", "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(RegistroCompra)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

// RegistroCompra RegistroCompra::LeerRegistrosPorIdCompra(int IdCompra){
//     RegistroCompra reg;
//     FILE *p;
//     p=fopen("registrocompra.dat", "rb");
//     if(p==NULL){
//         cout<<"NO PUDO LEERLO : RegistroCompra RegistroCompra::LeerRegistrosPorIdCompra(int IdCompra)"<<endl;
//          return reg;
//     }
//     while(fread(&reg, sizeof reg,1, p)){
//         if(reg.getIdCompra() == IdCompra){
//             fclose(p);
//             return reg;
//         }
//     }
//     fclose(p);
//     return reg;
// }
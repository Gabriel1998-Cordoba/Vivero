#include<iostream>
#include <cstring>

using namespace std;

#include "DetalleFacturaCompra.h"
#include"RegistroCompra.h"


//void DetalleFacturaCompra:: setIdArticulo(int idArticulo){
//    _idArticulo=idArticulo;
//}
void DetalleFacturaCompra::setIdCompra(int idCompra){
    _idCompra=idCompra;
}
void DetalleFacturaCompra::setCantidad(int cantidad ){_cantidad=cantidad;}
void DetalleFacturaCompra::setPrecio(float precio){_precio=precio;}
//int DetalleFacturaCompra::getIdArticulo(){return _idArticulo;}
int DetalleFacturaCompra::getIdCompra(){return _idCompra;}
int DetalleFacturaCompra::getCantidad(){return _cantidad;}
float DetalleFacturaCompra::getPrecio(){return _precio;}

void DetalleFacturaCompra::Mostrar(){
//cout<<"ID Articulo: "<<getIdArticulo()<<endl;
cout<<"ID Compra: "<<getIdCompra()<<endl;
cout<<"Cantidad: "<<getCantidad()<<endl;
cout<<"Precio: "<<getPrecio()<<endl;
}
void DetalleFacturaCompra::MostrarPlanta(){
getFecha().MostrarEnLinea();
cout<<"ID Detalle Factura Compra: "<<getIdDetalleFacturaCompra()<<endl;
cout<<"ID Compra: "<<getIdCompra()<<endl;
cout<<"Cantidad: "<<getCantidad()<<endl;
cout<<"Precio: "<<getPrecio()<<endl;
cout<<"Estacion: "<<getEstacion()<<endl;
cout<<"Estado: "<<getEstado()<<endl<<endl;

// getFecha().MostrarEnLineaSinSaltoDeLinea(); cout<<"\t";
// cout<<getIdDetalleFacturaCompra(); cout<<"\t\t";
// cout<<getIdArticulo(); cout<<"\t\t";
// cout<<getIdCompra(); cout<<"\t\t";
// cout<<getCantidad(); cout<<"\t\t";
// cout<<getPrecio(); cout<<"\t";
// cout<<getEstacion(); cout<<"\t\t";
// cout<<getEstado()<<endl;
}

int DetalleFacturaCompra::getTipoDeArticulo() const { return _TipoDeArticulo; }
void DetalleFacturaCompra::setTipoDeArticulo(int TipoDeArticulo) { _TipoDeArticulo = TipoDeArticulo; }

bool DetalleFacturaCompra::getEstado() const { return _estado; }
void DetalleFacturaCompra::setEstado(bool estado) { _estado = estado; }

const char * DetalleFacturaCompra::getNombre() const { return _nombre; }
void DetalleFacturaCompra::setNombre(const char *nombre){strcpy(_nombre, nombre);}

Fecha DetalleFacturaCompra::getFecha() const { return _fecha; }
void DetalleFacturaCompra::setFecha(const Fecha &fecha) { _fecha = fecha; }
void DetalleFacturaCompra::setDiaMesAnioFecha(int dia,int mes,int anio){

    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);

}

int DetalleFacturaCompra::tipoAgroquimico() const { return _tipoAgroquimico; }
void DetalleFacturaCompra::setTipoAgroquimico(int tipoAgroquimico) { _tipoAgroquimico = tipoAgroquimico; }

const char* DetalleFacturaCompra::getEstacion() const { return _estacion; }
void DetalleFacturaCompra::setEstacion(const char* estacion) {strcpy(_estacion, estacion);}
//
DetalleFacturaCompra::DetalleFacturaCompra(){
    // int _idArticulo;
    // int _idCompra;
    // int _cantidad;
    // float _precio;
    // int _TipoDeArticulo;//
    // bool _estado;//
    // char _nombre[30];//
    // Fecha _fecha;//
    //char  _estacion[30];
    //int _tipoAgroquimico; //1-Ecologico,2-Quimico

    //setIdArticulo(0);
    setIdCompra(0);
    setCantidad(0);
    setPrecio(0);
    setTipoDeArticulo(0);
    setEstado(true);
    setNombre("");
    _fecha.setDia(0);
    _fecha.setMes(0);
    _fecha.setAnio(0);
    setEstacion("");
    setTipoAgroquimico(0);
}

    

/**************************************************************/
void DetalleFacturaCompra::AutoCargar(Herramientas objH,int idCompra){

//AHI que armar el COMPRa y VENTA de

//setIdArticulo(objH.getIdArticulo);
//setIdCompra(objH.getIdCompra);
//setCantidad(objH.getCantidad);
//setPrecio(objH.getPrecio);
//setTipoDeArticulo(objH.getTipoDeArticulo);
//setEstado(objH.getEstado);

//hacer un calculo para guardar dentro de un archivo con 'ab'
//y el archivo se llamara detallefacturacompra.dat

}
/**************************************************************/
void DetalleFacturaCompra::AutoCargar(Planta objP,int idCompra){

//AHI que armar el COMPRa y VENTA de
DetalleFacturaCompra objD;

RegistroCompra objR;

objR = objR.LeerRegistrosPorIdCompra(idCompra);

int tam=0;

tam = objD.contarRegistros();
tam++;
objD.setIdDetalleFacturaCompra(tam);

//int tam1=0;
//tam1 = objP.contarRegistros();
//tam1++;
//objD.setIdArticulo(tam1);

objD.setIdCompra(objR.getIdCompra());

objD.setCantidad(objP.getStock());
objD.setPrecio(objP.getPrecio());
objD.setTipoDeArticulo(2);
objD.setEstado(objP.getEstado());
objD.setDiaMesAnioFecha((objP.getDia()),(objP.getMes()),(objP.getAnio()));
objD.setEstacion(objP.getEstacion());

//hacer un calculo para guardar dentro de un archivo con 'ab'
//y el archivo se llamara detallefacturacompra.dat

FILE *p;

p=fopen("detallefacturacompra.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

fwrite(&objD,sizeof (DetalleFacturaCompra),1,p);

fclose(p);

}
/**************************************************************/
void DetalleFacturaCompra::AutoCargar(Agroquimicos objA,int idCompra){

//AHI que armar el COMPRa y VENTA de

//setIdArticulo(objA.getIdArticulo);
//setIdCompra(objA.getIdCompra);
//setCantidad(objA.getCantidad);
//setPrecio(objA.getPrecio);
//setTipoDeArticulo(objA.getTipoDeArticulo);
//setEstado(objA.getEstado);
//setTipoAgroquimico(objA.getTipoDeArticulo());

//hacer un calculo para guardar dentro de un archivo con 'ab'
//y el archivo se llamara detallefacturacompra.dat

}
/**************************************************************/
void DetalleFacturaCompra::MostrarAutoCargarPlanta(int valorDNI){
DetalleFacturaCompra ClassM;
FILE *p;

int band=true;

p=fopen("detallefacturacompra.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (DetalleFacturaCompra),1,p)==1){
    if(band==true){
    //cout<<"Fecha"; cout<<"\t";
    //cout<<"ID Detalle Factura Compra"; cout<<"\t";
    //cout<<"ID Articulo"; cout<<"\t";
    //cout<<"ID Compra"; cout<<"\t";
    //cout<<"Cantidad"; cout<<"\t";
    //cout<<"Precio"; cout<<"\t";
    //cout<<"Estacion"; cout<<"\t";
    //cout<<"Estado";  cout<<"\t";
    //cout<<endl;
        band=false;
    }

int indice= ClassM.getSujeto().getTipoDoc().getIndice();
cout<<"INDICE: "<<indice<<endl;

int valor1 = ClassM.getSujeto().getTipoDoc().getTipoDocu(indice);
cout<<"valor1: "<<valor1<<endl;

if(valor1==valorDNI){
ClassM.MostrarPlanta();
}

}

fclose(p);
}
/**************************************************************/
int DetalleFacturaCompra::contarRegistros(){
        FILE *p;
        p=fopen("detallefacturacompra.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(DetalleFacturaCompra);
    }
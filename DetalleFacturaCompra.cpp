#include<iostream>
#include <cstring>

using namespace std;

#include "DetalleFacturaCompra.h"



void DetalleFacturaCompra:: setIdArticulo(int idArticulo){
    _idArticulo=idArticulo;
}
void DetalleFacturaCompra::setIdCompra(int idCompra){
    _idCompra=idCompra;
}
void DetalleFacturaCompra::setCantidad(int cantidad ){_cantidad=cantidad;}
void DetalleFacturaCompra::setPrecio(float precio){_precio=precio;}
int DetalleFacturaCompra::getIdArticulo(){return _idArticulo;}
int DetalleFacturaCompra::getIdCompra(){return _idCompra;}
int DetalleFacturaCompra::getCantidad(){return _cantidad;}
float DetalleFacturaCompra::getPrecio(){return _precio;}

void DetalleFacturaCompra::Mostrar(){
cout<<"ID Articulo: "<<getIdArticulo();
cout<<"ID Compra: "<<getIdCompra();
cout<<"Cantidad: "<<getCantidad();
cout<<"Precio: "<<getPrecio();
}

int DetalleFacturaCompra::getTipoDeArticulo() const { return _TipoDeArticulo; }
void DetalleFacturaCompra::setTipoDeArticulo(int TipoDeArticulo) { _TipoDeArticulo = TipoDeArticulo; }

bool DetalleFacturaCompra::getEstado() const { return _estado; }
void DetalleFacturaCompra::setEstado(bool estado) { _estado = estado; }

const char * DetalleFacturaCompra::getNombre() const { return _nombre; }
void DetalleFacturaCompra::setNombre(const char *nombre){strcpy(_nombre, nombre);}

Fecha DetalleFacturaCompra::getFecha() const { return _fecha; }
void DetalleFacturaCompra::setFecha(const Fecha &fecha) { _fecha = fecha; }

int DetalleFacturaCompra::tipoAgroquimico() const { return _tipoAgroquimico; }
void DetalleFacturaCompra::setTipoAgroquimico(int tipoAgroquimico) { _tipoAgroquimico = tipoAgroquimico; }

const char* DetalleFacturaCompra::getEstacion() const { return _estacion; }
void DetalleFacturaCompra::setEstacion(const char* estacion) {strcpy(_estacion, estacion);}

/**************************************************************/
void DetalleFacturaCompra::AutoCargar(Herramientas objH){

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
void DetalleFacturaCompra::AutoCargar(Planta objP){

//AHI que armar el COMPRa y VENTA de

//setIdArticulo(objP.getIdArticulo);
//setIdCompra(objP.getIdCompra);
//setCantidad(objP.getCantidad);
//setPrecio(objP.getPrecio);
//setTipoDeArticulo(objP.getTipoDeArticulo);
//setEstado(objP.getEstado);
//setEstacion(objP.getEstacion());

//hacer un calculo para guardar dentro de un archivo con 'ab'
//y el archivo se llamara detallefacturacompra.dat

}
/**************************************************************/
void DetalleFacturaCompra::AutoCargar(Agroquimicos objA){

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

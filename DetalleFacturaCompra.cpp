#include<iostream>

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

void DetalleFacturaCompra::AutoCargar(){

//AHI que armar el COMPRa y VENTA de 

//setIdArticulo();
//setIdCompra();
//setCantidad();
//setPrecio();

}

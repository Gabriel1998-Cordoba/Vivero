#include<iostream>
using namespace std;


#include "DetalleFacturaVenta.h"

int DetalleFacturaVenta::getIdVenta() const { return _idVenta; }
void DetalleFacturaVenta::setIdVenta(int idVenta) { _idVenta = idVenta; }

int DetalleFacturaVenta::getIdArticulo() const { return _idArticulo; }

void DetalleFacturaVenta::setIdArticulo(int idArticulo) { _idArticulo = idArticulo; }

int DetalleFacturaVenta::getCantidad() const { return _cantidad; }
void DetalleFacturaVenta::setCantidad(int cantidad) { _cantidad = cantidad; }

float DetalleFacturaVenta::getPrecioUnitario() const { return _precioUnitario; }
void DetalleFacturaVenta::setPrecioUnitario(float precioUnitario) { _precioUnitario = precioUnitario; }

float DetalleFacturaVenta::getSubtotal() const { return _subtotal; }
void DetalleFacturaVenta::setSubtotal(float subtotal) { _subtotal = subtotal; }

float DetalleFacturaVenta::getPrecioTotal() const { return _precioTotal; }
void DetalleFacturaVenta::setPrecioTotal(float precioTotal) { _precioTotal = precioTotal; }
bool DetalleFacturaVenta::cargar(int idArticulo,int idcompra,float precio)
{
    int cant=0;
    setIdVenta(idcompra);
    setIdArticulo(idArticulo);
    cout<<"Ingrese la Cantidad que desea llevar: ";
    cin>>cant;
    if(cant>=0)
    {
    
    setCantidad(cant);
    }else{return false;}
    setPrecioUnitario(precio);
    int subtotal=cant*precio;
    setSubtotal(subtotal);
return true;
    
}
bool DetalleFacturaVenta::GuardarEnArchivo()
{
    FILE *p;
    p=fopen("DetalleFacturaVenta.dat","ab");
    if(p==NULL)
    {

        return false;
    }
    bool escribio=fwrite(this,sizeof(DetalleFacturaVenta),1,p);
    fclose(p);
    return escribio;
}
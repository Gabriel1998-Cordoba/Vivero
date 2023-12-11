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

void DetalleFacturaVenta::mostrar(){
    cout<<"id Detalle Factura Compra: "<<getIdVenta()<<endl;
    cout<<"ID Articulo: "<<getIdArticulo()<<endl;
    cout<<"Cantidad: "<<getCantidad()<<endl;
    cout<<"Precio Unitario: "<<getPrecioUnitario()<<endl;
    cout<<"Subtotal: "<<getSubtotal()<<endl;
    cout<<"Precio Total: "<<getPrecioTotal()<<endl;
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

void DetalleFacturaVenta::MostrarDetalleDeFacturaCompraCompleto(){

DetalleFacturaVenta ClassM;
    FILE *p;
    p=fopen("DetalleFacturaVenta.dat","ab");
    if(p==NULL){
        cout<<"ERROR de ARCHIVO"<<endl;
        system("pause");
    }

while(fread(&ClassM,sizeof (DetalleFacturaVenta),1,p)==1){
ClassM.mostrar();
cout<<"//////////////////"<<endl;
}

fclose(p);


}
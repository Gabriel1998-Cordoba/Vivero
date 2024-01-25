#include <iostream>
#include <cstring>

using namespace std;

#include "DetalleFacturaCompra.h"
#include "RegistroCompra.h"

/*SETTERS*/
void DetalleFacturaCompra::setIdArticulo(int idArticulo) { _idArticulo = idArticulo; }
void DetalleFacturaCompra::setIdCompra(int idCompra) { _idCompra = idCompra; }
void DetalleFacturaCompra::setCantidad(int cantidad) { _cantidad = cantidad; }
void DetalleFacturaCompra::setPrecio(float precio) { _precio = precio; }
void DetalleFacturaCompra::setTipoDeArticulo(int tipoArticulo) { _TipoDeArticulo = tipoArticulo; } // prueba
void DetalleFacturaCompra::setEstado(bool estado) { _estado = estado; }
/*GETTERS*/
bool DetalleFacturaCompra::getEstado() const { return _estado; }
int DetalleFacturaCompra::getIdArticulo() { return _idArticulo; }
int DetalleFacturaCompra::getIdCompra() { return _idCompra; }
int DetalleFacturaCompra::getCantidad() { return _cantidad; }
float DetalleFacturaCompra::getPrecio() { return _precio; }
int DetalleFacturaCompra::getTipoDeArticulo() { return _TipoDeArticulo; }

void DetalleFacturaCompra::Mostrar()
{
    // cout<<"ID Articulo: "<<getIdArticulo()<<endl;
    cout << "ID Compra: " << getIdCompra() << endl;
    cout << "ID Articulo: " << getIdArticulo() << endl;
    cout << "Cantidad: " << getCantidad() << endl;
    cout << "Precio: " << getPrecio() << endl;
    cout << "Tipo Articulo: " << getTipoDeArticulo() << endl;
}

DetalleFacturaCompra::DetalleFacturaCompra()
{
     // int _tipoAgroquimico; //1-Ecologico,2-Quimico
    setIdArticulo(0);
    setIdCompra(0);
    setCantidad(0);
    setPrecio(0);
    setTipoDeArticulo(0);
    setEstado(false);


}
DetalleFacturaCompra:: ~DetalleFacturaCompra(){}
bool DetalleFacturaCompra::AutoCargar(int idArticulo, int idCompra, float precio, int tipoArticulo) // prueba
{
    int cant = 0;
    setIdCompra(idCompra);
    setIdArticulo(idArticulo);
    cout << "Ingrese la Cantidad que desea llevar: ";
    cin >> cant;
    if (cant >= 0)
    {

        setCantidad(cant);
    }
    else
    {
        return false;
    }
    setPrecio(precio);
    setTipoDeArticulo(tipoArticulo); // prueba

    return true;
}
int DetalleFacturaCompra::contarRegistros(const char *nombre)
{
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(DetalleFacturaCompra);
}

bool DetalleFacturaCompra::GuardarEnArchivo()
{
    FILE *p;
    p = fopen("DetalleFacturaCompra.dat", "ab");
    if (p == NULL)
    {

        return false;
    }
    bool escribio = fwrite(this, sizeof(DetalleFacturaCompra), 1, p);
    fclose(p);
    return escribio;
}

bool DetalleFacturaCompra::leerRegistroIdCompra(int pos)
{
    
    
    FILE *p;
    p = fopen("DetalleFacturaCompra.dat", "rb");
    if (p == NULL)
    {
        cout << "Error = DetalleFacturaCompra leerRegistroIdCompra(int IdComp)" << endl;
        return false;
    }
    fseek(p, sizeof (DetalleFacturaCompra) * pos, 0);
   bool leyo= fread(this, sizeof (DetalleFacturaCompra), 1, p);
    fclose(p);
    return leyo;
}
void DetalleFacturaCompra::MostrarDatosDetalleFacturaCompraEnArchivo(){
    DetalleFacturaCompra reg;
    FILE *p;

    p = fopen("DetalleFacturaCompra.dat", "rb");
    if (p == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while(fread(&reg, sizeof (DetalleFacturaCompra), 1, p)){
        reg.Mostrar();
    }
    fclose(p);
}

DetalleFacturaCompra DetalleFacturaCompra::leerRegistro(int pos,const char* nombre){


    DetalleFacturaCompra reg;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"ERRRO = DetalleFacturaCompra leerRegistro(int pos)"<<endl;
        return reg;
    }
    fseek(p, sizeof(DetalleFacturaCompra)*pos,0);
    fread(&reg, sizeof (DetalleFacturaCompra),1, p);
    fclose(p);
    return reg;

}
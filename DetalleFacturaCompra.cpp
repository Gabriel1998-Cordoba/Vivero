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
// const char *DetalleFacturaCompra::getNombre() const { return _nombre; }
// void DetalleFacturaCompra::setNombre(const char *nombre) { strcpy(_nombre, nombre); }

// Fecha DetalleFacturaCompra::getFecha() const { return _fecha; }
// void DetalleFacturaCompra::setFecha(const Fecha &fecha) { _fecha = fecha; }
// void DetalleFacturaCompra::setDiaMesAnioFecha(int dia, int mes, int anio)
// {

//     _fecha.setDia(dia);
//     _fecha.setMes(mes);
//     _fecha.setAnio(anio);
// }

// int DetalleFacturaCompra::tipoAgroquimico() const { return _tipoAgroquimico; }
// void DetalleFacturaCompra::setTipoAgroquimico(int tipoAgroquimico) { _tipoAgroquimico = tipoAgroquimico; }

// const char *DetalleFacturaCompra::getEstacion() const { return _estacion; }
// void DetalleFacturaCompra::setEstacion(const char *estacion) { strcpy(_estacion, estacion); }

/*CONSTRUCTOR*/
DetalleFacturaCompra::DetalleFacturaCompra()
{
    // int _idArticulo;
    // int _idCompra;
    // int _cantidad;
    // float _precio;
    // int _TipoDeArticulo;//
    // bool _estado;//
    // char _nombre[30];//
    // Fecha _fecha;//
    // char  _estacion[30];
    // int _tipoAgroquimico; //1-Ecologico,2-Quimico

    setIdArticulo(0);
    setIdCompra(0);
    setCantidad(0);
    setPrecio(0);
    setTipoDeArticulo(0);
    setEstado(false);
    // setNombre("");
    // _fecha.setDia(0);
    // _fecha.setMes(0);
    // _fecha.setAnio(0);
}
DetalleFacturaCompra:: ~DetalleFacturaCompra(){}
/**************************************************************/
// void DetalleFacturaCompra::AutoCargar(Herramientas objH, int idCompra)
//{

// AHI que armar el COMPRa y VENTA de

// setIdArticulo(objH.getIdArticulo);
// setIdCompra(objH.getIdCompra);
// setCantidad(objH.getCantidad);
// setPrecio(objH.getPrecio);
// setTipoDeArticulo(objH.getTipoDeArticulo);
// setEstado(objH.getEstado);

// hacer un calculo para guardar dentro de un archivo con 'ab'
// y el archivo se llamara detallefacturacompra.dat
//}
/**************************************************************/
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
/**************************************************************/
// void DetalleFacturaCompra::AutoCargar(Agroquimicos objA, int idCompra)
//{

// AHI que armar el COMPRa y VENTA de

// setIdArticulo(objA.getIdArticulo);
// setIdCompra(objA.getIdCompra);
// setCantidad(objA.getCantidad);
// setPrecio(objA.getPrecio);
// setTipoDeArticulo(objA.getTipoDeArticulo);
// setEstado(objA.getEstado);
// setTipoAgroquimico(objA.getTipoDeArticulo());

// hacer un calculo para guardar dentro de un archivo con 'ab'
// y el archivo se llamara detallefacturacompra.dat
//}
/**************************************************************/
// void DetalleFacturaCompra::MostrarAutoCargarPlanta(int valor)
// {
//     DetalleFacturaCompra ClassM;
//     FILE *p;

//     int band = true;
//     int aux;

//     p = fopen("detallefacturacompra.dat", "rb");
//     if (p == NULL)
//     {
//         cout << "ERROR de ARCHIVO" << endl;
//         system("pause");
//     }

//     while (fread(&ClassM, sizeof(DetalleFacturaCompra), 1, p) == 1)
//     {
//         if (band == true)
//         {
//             // cout<<"Fecha"; cout<<"\t";
//             // cout<<"ID Detalle Factura Compra"; cout<<"\t";
//             // cout<<"ID Articulo"; cout<<"\t";
//             // cout<<"ID Compra"; cout<<"\t";
//             // cout<<"Cantidad"; cout<<"\t";
//             // cout<<"Precio"; cout<<"\t";
//             // cout<<"Estacion"; cout<<"\t";
//             // cout<<"Estado";  cout<<"\t";
//             // cout<<endl;
//             band = false;
//         }
//         ClassM.MostrarPlanta();
//             // if(valor==-1){
//             //     ClassM.MostrarPlanta();
//             //     cout<<"retorno todo"<<endl;

//             // }else if((aux=(ClassM.getIdCompra()))==valor){
//             //     ClassM.MostrarPlanta();
//             // }

//     }

//     fclose(p);
// }
/**************************************************************/
int DetalleFacturaCompra::contarRegistros()
{
    FILE *p;
    p = fopen("DetalleFacturaCompra.dat", "rb");
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

// void DetalleFacturaCompra::MostrarAutoCargarAgroquimicos(int valor)
// {
//     DetalleFacturaCompra ClassM;
//     FILE *p;
//     int band = true;
//     int aux;

//     p = fopen("detallefacturacompra.dat", "rb");
//     if (p == NULL)
//     {
//         cout << "ERROR de ARCHIVO" << endl;
//         system("pause");
//     }
//     while (fread(&ClassM, sizeof(DetalleFacturaCompra), 1, p) == 1)
//     {
//         if (band == true)
//         {
//             // cout<<"Fecha"; cout<<"\t";
//             // cout<<"ID Detalle Factura Compra"; cout<<"\t";
//             // cout<<"ID Articulo"; cout<<"\t";
//             // cout<<"ID Compra"; cout<<"\t";
//             // cout<<"Cantidad"; cout<<"\t";
//             // cout<<"Precio"; cout<<"\t";
//             // cout<<"Estacion"; cout<<"\t";
//             // cout<<"Estado";  cout<<"\t";
//             // cout<<endl;
//             band = false;
//         }
//         ClassM.MostrarAgroquimicos();
//         // if(valor==-1){
//         //     ClassM.MostrarPlanta();
//         //     cout<<"retorno todo"<<endl;
//         // }else if((aux=(ClassM.getIdCompra()))==valor){
//         //     ClassM.MostrarPlanta();
//         // }
//     }

//     fclose(p);
// }

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
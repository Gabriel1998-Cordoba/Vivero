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
DetalleFacturaCompra::~DetalleFacturaCompra() {}
bool DetalleFacturaCompra::AutoCargar(int idCompra, Herramientas objH) // prueba
{

    int cant = 0, PosicionHerramienta;

    setIdCompra(idCompra);
    setIdArticulo(objH.getID());

    int band = true;

    do
    {

        if (objH.getStock() == 0)
        {
            SaltoDeLinea();
            system("cls");
            cout << "no hay stock para esta herramienta" << endl;
            band = false;
        }
        else
        {

            cout << "Ingrese la Cantidad que desea llevar: ";
            cin >> cant;

            if (cant >= 0)
            {

                if (cant <= objH.getStock())
                {
                    setCantidad(cant);
                    setPrecio(objH.getPrecio());
                    setTipoDeArticulo(objH.getTipoDeArticulo()); // prueba
                    PosicionHerramienta = BuscarPosicion(objH);


                    if (PosicionHerramienta > 0)
                    {
                        objH.setStock(objH.getStock()-cant);
                        objH.reemplazarRegistroHerramienta(objH, PosicionHerramienta);
                    }

                    return true;
                }
                else
                {
                    SaltoDeLinea();
                    system("cls");
                    cout << "la cantidad disponible es: " << objH.getStock() << endl;
                    band = true;
                }
            }
            else if (cant < 0)
            {
                SaltoDeLinea();
                system("cls");
                cout << "la cantidad debe de ser positivo" << endl;
                band = true;
            }
        }

    } while (band == true);

    return false;
}
bool DetalleFacturaCompra::AutoCargar(int idCompra, Planta objP) // prueba
{

    int cant = 0, PosicionPlanta;

    setIdCompra(idCompra);
    setIdArticulo(objP.getID());

    int band = true;

    do
    {

        if (objP.getStock() == 0)
        {
            SaltoDeLinea();
            system("cls");
            cout << "no hay stock para esta herramienta" << endl;
            band = false;
        }
        else
        {

            cout << "Ingrese la Cantidad que desea llevar: ";
            cin >> cant;

            if (cant >= 0)
            {

                if (cant <= objP.getStock())
                {
                    setCantidad(cant);
                    setPrecio(objP.getPrecio());
                    setTipoDeArticulo(objP.getTipoDeArticulo()); // prueba
                    PosicionPlanta = BuscarPosicion(objP);


                    if (PosicionPlanta > 0)
                    {
                        objP.setStock(objP.getStock()-cant);
                        objP.reemplazarRegistroPlanta(objP, PosicionPlanta);
                    }

                    return true;
                }
                else
                {
                    SaltoDeLinea();
                    system("cls");
                    cout << "la cantidad disponible es: " << objP.getStock() << endl;
                    band = true;
                }
            }
            else if (cant < 0)
            {
                SaltoDeLinea();
                system("cls");
                cout << "la cantidad debe de ser positivo" << endl;
                band = true;
            }
        }

    } while (band == true);

    return false;
}
bool DetalleFacturaCompra::AutoCargar(int idCompra, Agroquimicos objA) // prueba
{

    int cant = 0, PosicionAgroquimicos;

    setIdCompra(idCompra);
    setIdArticulo(objA.getID());

    int band = true;

    do
    {

        if (objA.getStock() == 0)
        {
            SaltoDeLinea();
            system("cls");
            cout << "no hay stock para esta herramienta" << endl;
            band = false;
        }
        else
        {

            cout << "Ingrese la Cantidad que desea llevar: ";
            cin >> cant;

            if (cant >= 0)
            {

                if (cant <= objA.getStock())
                {
                    setCantidad(cant);
                    setPrecio(objA.getPrecio());
                    setTipoDeArticulo(objA.getTipoDeArticulo()); // prueba
                    PosicionAgroquimicos = BuscarPosicion(objA);


                    if (PosicionAgroquimicos > 0)
                    {
                        objA.setStock(objA.getStock()-cant);
                        objA.reemplazarRegistroAgroquimicos(objA, PosicionAgroquimicos);
                    }

                    return true;
                }
                else
                {
                    SaltoDeLinea();
                    system("cls");
                    cout << "la cantidad disponible es: " << objA.getStock() << endl;
                    band = true;
                }
            }
            else if (cant < 0)
            {
                SaltoDeLinea();
                system("cls");
                cout << "la cantidad debe de ser positivo" << endl;
                band = true;
            }
        }

    } while (band == true);

    return false;
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
    fseek(p, sizeof(DetalleFacturaCompra) * pos, 0);
    bool leyo = fread(this, sizeof(DetalleFacturaCompra), 1, p);
    fclose(p);
    return leyo;
}
void DetalleFacturaCompra::MostrarDatosDetalleFacturaCompraEnArchivo()
{
    
    DetalleFacturaCompra reg;
    FILE *p;

    p = fopen("DetalleFacturaCompra.dat", "rb");
    if (p == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while (fread(&reg, sizeof(DetalleFacturaCompra), 1, p))
    {
        reg.Mostrar();
        cout << endl;
    }
    fclose(p);
}

DetalleFacturaCompra DetalleFacturaCompra::leerRegistro(int pos, const char *nombre)
{

    DetalleFacturaCompra reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << "ERRRO = DetalleFacturaCompra leerRegistro(int pos)" << endl;
        return reg;
    }
    fseek(p, sizeof(DetalleFacturaCompra) * pos, 0);
    fread(&reg, sizeof(DetalleFacturaCompra), 1, p);
    fclose(p);
    return reg;
}
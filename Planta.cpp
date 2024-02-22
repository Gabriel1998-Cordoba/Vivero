#include <iostream>
#include <cstring>

using namespace std;

#include "RegistroCompra.h"
#include "Planta.h"
#include "FuncionesGlobales.h"
#include "Articulo.h"
#include "DetalleFacturaCompra.h"
#include "bkpDetalleFacturaCompra.h"

const char *Planta::getEstacion()
{
    return _estacion;
}

void Planta::setEstacion(const char *estacion)
{
    strcpy(_estacion, estacion);
}

void Planta::CargarArchivoPlanta(int totalDeRegistros, int TipoDeArticulo)
{ // ab
    FILE *p;
    Planta ClassM;

    p = fopen("planta.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    ClassM.CargarPlanta(TipoDeArticulo);
    fwrite(&ClassM, sizeof(Planta), 1, p);

    fclose(p);
}

void Planta::CargarPlanta(int TipoDeArticulo)
{
    int totalDeRegistros = contarRegistros();

    if (totalDeRegistros == -1)
    {
        totalDeRegistros = 0;
    }
    Articulo::Cargar(totalDeRegistros, TipoDeArticulo);

    char estacion[30];

    cout << "Ingrese Estacion = ";
    cargarCadena(estacion, 30);
    setEstacion(estacion);
    cout << endl;
}

void Planta::MostrarPlanta()
{
    Articulo::Mostrar();
    cout << "Estacion: " << getEstacion() << endl
         << endl;
}
void Planta::Mostrarr()
{
    MostrarPlanta();
}

int Planta::contarRegistros(const char *nombre)
{
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
        return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Planta);
}

bool Planta::borrarRegistroPlanta()
{
    FILE *p;
    p = fopen("planta.dat", "wb");
    if (p == nullptr)
    {
        return false;
    }
    fclose(p);
    return true;
}

Planta Planta::leerRegistroPlanta(int pos, const char *nombre)
{
    Planta reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << "Error = Planta Planta::leerRegistroPlanta(int pos)" << endl;
        return reg;
    }
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

void Planta::ListarPlanta()
{

    Planta ClassM;
    FILE *p;

    p = fopen("planta.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }
    for (int i = 0; i < contarRegistros(); i++)
    {
        ClassM = leerRegistroPlanta(i, "planta.dat");
        if (ClassM.getEstado() == 1)
        {
            ClassM.MostrarPlanta();
        }
    }

    fclose(p);
}

bool Planta::reemplazarRegistroPlanta(Planta reg, int posicionAReemplazar)
{
    FILE *p = fopen("planta.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicionAReemplazar * sizeof(Planta), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Planta), 1, p);
    fclose(p);
    return pudoEscribir;
}

void Planta::Opcion1Compra()
{
    Planta objT;

    int tam = 0;
    tam = objT.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        objT = objT.leerRegistroPlanta(i);
        cout << "Planta: " << objT.getNombre() << endl;
        cout << "Precio: " << objT.getPrecio() << endl;
        cout << "Stock: " << objT.getStock() << endl
             << endl;

        cout << "//////////////////////////" << endl
             << endl;
    }
}
void Planta::Opcion2Compra()
{

    Planta objT;

    int tam = 0;
    bool Encontro = false;
    tam = objT.contarRegistros();

    char nombrePlanta[30], auxnombre[30];
    cout << "Ingrese Nombre:" << endl;
    cargarCadena(nombrePlanta, 30);
    strlwr(nombrePlanta);
    for (int i = 0; i < tam; i++)
    {

        objT = objT.leerRegistroPlanta(i);
        strcpy(auxnombre, objT.getNombre());
        strlwr(auxnombre);
        if (strcmp(nombrePlanta, auxnombre) == 0)
        {
            Encontro = true;
            cout << "//////////////////////////" << endl;
            cout << "Nombre: " << objT.getNombre() << endl;
            cout << "Precio: " << objT.getPrecio() << endl;
            cout << "Stock: " << objT.getStock() << endl;
            cout << "//////////////////////////" << endl
                 << endl;
        }
    }

    if (Encontro == false)
    {
        cout << "PLANTA INGRESADA, no fue encontrada" << endl;
    }
}
void Planta::Opcion3Compra(RegistroCompra objRegistroCompra)
{

    char nombreP[30], auxnombre[30];
    int tam = 0;

    bkpDetalleFacturaCompra objBkpDetalleFCompra;
    objBkpDetalleFCompra.CrearBackup();

    DetalleFacturaCompra descripcionFactura;
    Planta reg, aux;
    tam = reg.contarRegistros();

    cout << "Ingrese Nombre de la Planta: ";
    cargarCadena(nombreP, 30);
    strlwr(nombreP);
    for (int i = 0; i < tam; i++)
    {
        aux = reg.leerRegistroPlanta(i);
        strcpy(auxnombre, aux.getNombre());
        strlwr(auxnombre);
        if (strcmp(auxnombre, nombreP) == 0)
        {

            if (descripcionFactura.AutoCargar(objRegistroCompra.getIdCompra(), aux) == true)
            {
                if (descripcionFactura.GuardarEnArchivo())
                {
                    cout << "Guardado Correctamente el detalle del Articulo" << endl;
                    system("pause");
                    return;
                }
            }
        }
    }
}

bool Planta::MostrarArchivoPlanta()
{

    Planta objP;
    int tam = objP.contarRegistros();

    if (tam == -1)
    {
        return false;
    }

    for (int i = 0; i < tam; i++)
    {
        objP = objP.leerRegistroPlanta(i);
        objP.MostrarPlanta();
    }

    return true;
}

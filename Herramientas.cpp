#include <iostream>
#include <cstring>

using namespace std;

#include "FuncionesGlobales.h"
#include "DetalleFacturaVenta.h"
#include "Articulo.h"
#include "Herramientas.h"

void Herramientas::CargarArchivoHerramienta(int totalDeRegistros, int TipoDeArticulo)
{
    FILE *p;
    Herramientas ClassM;

    p = fopen("herramientas.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    ClassM.CargarHerramienta(totalDeRegistros, TipoDeArticulo);
    fwrite(&ClassM, sizeof(Herramientas), 1, p);

    fclose(p);
}

void Herramientas::CargarHerramienta(int totalDeRegistros, int TipoDeArticulo)
{
    Articulo::Cargar(totalDeRegistros, TipoDeArticulo);
}

void Herramientas::MostrarHerramienta()
{
    Articulo::Mostrar();
    cout << endl;
}

int Herramientas::contarRegistros()
{
    FILE *p;
    p = fopen("herramientas.dat", "rb");
    if (p == NULL)
        return 0;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Herramientas);
}

bool Herramientas::borrarRegistroHerramienta()
{
    FILE *p;
    p = fopen("herramientas.dat", "wb");
    if (p == nullptr)
    {
        return false;
    }
    fclose(p);
    return true;
}

Herramientas Herramientas::leerRegistroHerramienta(int pos)
{
    Herramientas reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen("herramientas.dat", "rb");
    if (p == NULL)
    {
        cout << "Error = Herramientas Herramientas::leerRegistroHerramienta(int pos)" << endl;
        return reg;
    }
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

void Herramientas::ListarHerramienta()
{
    Herramientas ClassM;
    FILE *p;

    p = fopen("herramientas.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    while (fread(&ClassM, sizeof(Herramientas), 1, p) == 1)
    {
        ClassM.MostrarHerramienta();
    }

    fclose(p);
}

void Herramientas::Opcion1Compra()
{
}
void Herramientas::Opcion2Compra()
{
}
void Herramientas::Opcion3Compra(int idCompra)
{
///// ECHO POR GABI


    // char nombreH[30];
    // int tam = 0;
    // DetalleFacturaVenta descripcionFactura;
    // Herramientas reg, aux;
    // tam = reg.contarRegistros();

    // cout << "Ingrese Nombre de la Herramienta: ";
    // cargarCadena(nombreH, 30);
    // for (int i = 0; i < tam; i++)
    // {
    //     aux = reg.leerRegistroHerramienta(i);
    //     if (strcmp(aux.getNombre(), nombreH) == 0)
    //     {
    //         if (descripcionFactura.cargar(idcompra, aux.getID(), aux.getPrecio()) == true)
    //         {
    //             if (descripcionFactura.GuardarEnArchivo())
    //             {
    //                 cout << "Guardado Correctamente ";
    //                 system("pause");
    //                 return;
    //             }
    //         }
    //     }
    // }

///// ECHO POR MAXI


}
// void Herramientas::Opcion4Compra(){

// }
// void Herramientas::Opcion5Compra(){

// }
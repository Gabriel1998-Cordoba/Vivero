#include <iostream>
#include <cstring>

using namespace std;

#include "FuncionesGlobales.h"
#include "DetalleFacturaCompra.h"
#include "bkpDetalleFacturaCompra.h"
#include "Articulo.h"
#include "Herramientas.h"

void Herramientas::setMaterial(const char *material)
{
    strcpy(_material, material);
}
void Herramientas::CargarArchivoHerramienta(int TipoDeArticulo)
{
    Herramientas ClassM;

    int totalDeRegistros = contarRegistros();

    if (totalDeRegistros == -1)
    {
        totalDeRegistros = 0;
    }

    ClassM.CargarHerramienta(totalDeRegistros, TipoDeArticulo);

    FILE *p;

    p = fopen("herramientas.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }
    fwrite(&ClassM, sizeof(Herramientas), 1, p);

    fclose(p);
}

void Herramientas::CargarHerramienta(int totalDeRegistros, int TipoDeArticulo)
{
    char material[30];
    Articulo::Cargar(totalDeRegistros, TipoDeArticulo);
    cout << "MATERIAL: ";
    cargarCadena(material, 30);
    setMaterial(material);
}

void Herramientas::MostrarHerramienta()
{
    Articulo::Mostrar();
    cout << endl;
}

int Herramientas::contarRegistros(const char *nombre)
{
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
        return -1; // cambie el 0 por un -1, por si no ahi ningun registro me devuelva -1
                   // Fijate gabi si esto no afecta a otra parte del programa
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

Herramientas Herramientas::leerRegistroHerramienta(int pos, const char *nombre)
{
    Herramientas reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(nombre, "rb");
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

bool Herramientas::ListarHerramientaPorCodigoHerramienta(int codigoHerramienta)
{

    int pos = 0;

    Herramientas reg;

    int cont = reg.contarRegistros();

    for (int i = 0; i < cont; i++)
    {

        reg = leerRegistroHerramienta(i);

        if (reg.getID() == codigoHerramienta)
        {

            reg.MostrarHerramienta();
            return true;
        }
    }

    return false;
}

void Herramientas::Opcion1Compra()
{
    ListarHerramienta();
}
void Herramientas::Opcion2Compra()
{
    Herramientas ClassM;
    int ID;

    cout << "ingrese el ID de la herramienta" << endl;
    cin >> ID;
    bool existe = ListarHerramientaPorCodigoHerramienta(ID);

    if (existe)
    {

        cout << "herramienta encontrada" << endl;
    }
    else
    {

        cout << "herramienta no encontrada" << endl;
    }

    // ValidarID(ID);
}
bool Herramientas::reemplazarRegistroHerramienta(Herramientas objHerramienta, int posicionAReemplazar)
{
    FILE *p = fopen("herramientas.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicionAReemplazar * sizeof(Herramientas), SEEK_SET);
    bool pudoEscribir = fwrite(&objHerramienta, sizeof(Herramientas), 1, p);
    fclose(p);
    return pudoEscribir;
}
void Herramientas::Opcion3Compra(RegistroCompra objR)
{
    ///// ECHO POR GABI

    char nombreH[30];
    int tam = 0;

    bkpDetalleFacturaCompra objBkpDetalleFCompra;
    objBkpDetalleFCompra.CrearBackup();

    DetalleFacturaCompra descripcionFactura;

    Herramientas herramienta, aux;

    tam = herramienta.contarRegistros();

    cout << "Ingrese Nombre de la Herramienta: ";
    cargarCadena(nombreH, 30);

    for (int i = 0; i < tam; i++)
    {
        aux = herramienta.leerRegistroHerramienta(i);

        if (strcmp(aux.getNombre(), nombreH) == 0)
        {

            if (descripcionFactura.AutoCargar(objR.getIdCompra(), aux) == true)
            {
                if (descripcionFactura.GuardarEnArchivo())
                {

                    objBkpDetalleFCompra.CrearBackup();

                    cout << "Guardado Correctamente ";
                    system("pause");
                    return;
                }
            }
        }
    }
}
// void Herramientas::Opcion4Compra(){

// }
// void Herramientas::Opcion5Compra(){

// }

bool Herramientas::MostrarArchivoHerramienta()
{

    Herramientas ClassM;

    FILE *p;
    p = fopen("herramientas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }

    while (fread(&ClassM, sizeof(Herramientas), 1, p) == 1)
    {

        ClassM.MostrarHerramienta();
    }

    fclose(p);
    return true;
}
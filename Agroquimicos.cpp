#include <iostream>
#include <cstring>

using namespace std;

#include "Agroquimicos.h"
#include "FuncionesGlobales.h"
#include "Articulo.h"
#include "DetalleFacturaCompra.h"
#include "bkpDetalleFacturaCompra.h"

/***************************************************************/
void Agroquimicos::setTipoAgroquimico(int tipoAgroquimico)
{
    _tipoAgroquimico = tipoAgroquimico;
}
/***************************************************************/
int Agroquimicos::getTipoAgroquimico()
{
    return _tipoAgroquimico;
}
/***************************************************************/
void Agroquimicos::CargarArchivoAgroquimicos(int TipoDeArticulo)
{
    FILE *p;
    Agroquimicos ClassM;

    p = fopen("agroquimicos.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    ClassM.CargarAgroquimicos(TipoDeArticulo);
    fwrite(&ClassM, sizeof(Agroquimicos), 1, p);

    fclose(p);
}

void Agroquimicos::CargarAgroquimicos(int TipoDeArticulo)
{

    int totalDeRegistros = contarRegistros();

    if (totalDeRegistros == -1)
    {
        totalDeRegistros = 0;
    }

    Articulo::Cargar(totalDeRegistros, TipoDeArticulo);

    int tipoAgroquimico = 0;

    do
    {
        cout << "Agroquimico 1 == Ecologico" << endl;
        cout << "Agroquimico 2 == Quimico" << endl
             << endl;

        cout << "Ingrese tipo Agroquimico" << endl;
        cin >> tipoAgroquimico;
        if ((tipoAgroquimico != 1) && (tipoAgroquimico != 2))
        {
            cout << "El valor ingresado en tipo Agroquimico no existe" << endl;
        }
        else
        {
            setTipoAgroquimico(tipoAgroquimico);
        }

    } while ((tipoAgroquimico != 1) && (tipoAgroquimico != 2));
}

void Agroquimicos::MostrarAgroquimicos()
{
    Articulo::Mostrar();
    cout << "Agroquimico: " << getTipoAgroquimico() << endl;
    cout << endl;
}

int Agroquimicos::contarRegistros(const char *ruta)
{
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL)
        return -1; // cambie el 0 por un -1, por si no ahi ningun registro me devuelva -1
                   // Fijate gabi si esto no afecta a otra parte del programa
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Agroquimicos);
}

bool Agroquimicos::borrarRegistroAgroquimicos()
{
    FILE *p;
    p = fopen("agroquimicos.dat", "wb");
    if (p == nullptr)
    {
        return false;
    }
    fclose(p);
    return true;
}

Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos, const char *ruta)
{
    Agroquimicos reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL)
    {
        cout << "Error = Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos)" << endl;
        return reg;
    }
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

void Agroquimicos::ListarAgroquimicos()
{

    Agroquimicos ClassM;
    FILE *p;

    p = fopen("agroquimicos.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    while ((fread(&ClassM, sizeof(Agroquimicos), 1, p)) == 1)
    {
        ClassM.MostrarAgroquimicos();
    }

    fclose(p);
}


bool Agroquimicos::reemplazarRegistroAgroquimicos(Agroquimicos objAgroquimico, int posicionAReemplazar)
{
    FILE *p = fopen("agroquimicos.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicionAReemplazar * sizeof(Agroquimicos), SEEK_SET);
    bool pudoEscribir = fwrite(&objAgroquimico, sizeof(Agroquimicos), 1, p);
    fclose(p);
    return pudoEscribir;
}

void Agroquimicos::Opcion1Compra()
{
    Agroquimicos objT;

    int tam = 0;
    tam = objT.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        objT = objT.leerRegistroAgroquimicos(i);
        cout << "Agroquimicos: " << objT.getNombre() << endl;
        cout << "Precio: " << objT.getPrecio() << endl;
        cout << "Stock: " << objT.getStock() << endl
             << endl;

        cout << "//////////////////////////" << endl
             << endl;
    }
}
void Agroquimicos::Opcion2Compra()
{

    Agroquimicos objT;

    int tam = 0;
    bool Encontro = false;
    tam = objT.contarRegistros();

    char nombreAgroquimicos[30];
    cout << "Ingrese Nombre:" << endl;
    cargarCadena(nombreAgroquimicos, 30);

    for (int i = 0; i < tam; i++)
    {

        objT = objT.leerRegistroAgroquimicos(i);

        if (strcmp(nombreAgroquimicos, objT.getNombre()) == 0)
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
        cout << "Agroquimico INGRESADO, no fue encontrada" << endl;
    }
}
void Agroquimicos::Opcion3Compra(int idCompra)
{

    char nombreP[30];
    int tam = 0;

    bkpDetalleFacturaCompra objBkpDetalleFCompra;
    objBkpDetalleFCompra.CrearBackup();

    DetalleFacturaCompra descripcionFactura;
    Agroquimicos reg, aux;
    tam = reg.contarRegistros();

    cout << "Ingrese Nombre del Agroquimico: ";
    cargarCadena(nombreP, 30);
    for (int i = 0; i < tam; i++)
    {
        aux = reg.leerRegistroAgroquimicos(i);
        if (strcmp(aux.getNombre(), nombreP) == 0)
        {
            if (descripcionFactura.AutoCargar(idCompra, aux) == true)
            {
                if (descripcionFactura.GuardarEnArchivo())
                {
                    cout << "Guardado Correctamente " << endl;
                  
                    return;
                }
            }
        }
    }
}

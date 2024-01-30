#include <iostream>

using namespace std;

#include "Duenio.h"

void Duenio::CargarDuenio(/*int totalDeRegistros ,int TipoDeArticulo*/)
{

    int tamRegistro = this->contarRegistros("duenio.dat");
    float sueldo;

    if (tamRegistro == -1)
    {
        _idDuenio = tamRegistro + 2;
    }

    else
    {
        _idDuenio = tamRegistro + 1;
    }
    cout << "ID DUENIO Nro : " << GetIdDuenio() << endl;
    Sujeto::CargarSujeto(/*,TipoDeArticulo*/);

    do
    {
        cout << "CAPITAL VIVERO: ";
        cin >> sueldo;

        if (sueldo < 0)
        {
            cout << "dato ingresado tiene que ser positivo" << endl;
        }

    } while (sueldo < 0);
    setSueldo(sueldo);
}

void Duenio::MostrarDuenio()
{
    Sujeto::MostrarSujeto();
    cout << "Su Sueldo es: " << getSueldo() << endl;
    cout << "Su id Duenio es: " << GetIdDuenio() << endl
         << endl;
}

void Duenio::CargarDatosDeDuenioEnArchivo(/*int totalDeRegistros ,int TipoDeArticulo*/)
{

    // cout<<"hola mundo"<<endl;
    // system("pause");

    Duenio ClassM;
    ClassM.CargarDuenio(/*totalDeRegistros ,TipoDeArticulo*/);

    FILE *p;

    p = fopen("duenio.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }
    fwrite(&ClassM, sizeof(Duenio), 1, p);

    fclose(p);
}

void Duenio::MostrarDatosDeDuenioEnArchivo()
{
    Duenio ClassM;
    FILE *p;

    p = fopen("duenio.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    while (fread(&ClassM, sizeof(Duenio), 1, p) == 1)
    {
        if (ClassM.getEstado() != false)
        {
            ClassM.MostrarDuenio();
        }
        cout << "//////////////////" << endl;
    }

    fclose(p);
}

void Duenio::CambiarSueldoCargadoEnArchivo()
{
    Duenio objD;

    float sueldo;

    int tam = 0, cantidad;
    tam = objD.contarRegistros("duenio.dat");

    objD = objD.leerRegistro((tam - 1), "duenio.dat");

    cout << "Ingrese sueldo:";
    cin >> sueldo;

    objD.setSueldo(sueldo);

    objD.reemplazarRegistroDuenio(objD, (tam - 1));
}

void Duenio::MostrarSueldoCargadoEnArchivo()
{

    Duenio objD;

    int tam = 0, cantidad;
    tam = objD.contarRegistros("duenio.dat");

    objD = objD.leerRegistro((tam - 1), "duenio.dat");

    cout << "Su sueldo Es :" << objD.getSueldo() << endl;
}

int Duenio::contarRegistros(const char *ruta)
{
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL)
        return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Duenio);
}

void Duenio::BorrarDatosDelDuenio()
{
    Duenio ClassM;
    FILE *p;

    p = fopen("duenio.dat", "wb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }
}

Duenio Duenio::leerRegistro(int pos, const char *nombre)
{
    Duenio reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
    {
        cout << "ERRRO = Duenio Duenio::leerRegistro(int pos)" << endl;
        return reg;
    }
    fseek(p, sizeof(Duenio) * pos, 0);
    fread(&reg, sizeof(Duenio), 1, p);
    fclose(p);
    return reg;
}

bool Duenio::reemplazarRegistroDuenio(Duenio reg, int posicionAReemplazar)
{
    FILE *p = fopen("duenio.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicionAReemplazar * sizeof(Duenio), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Duenio), 1, p);
    fclose(p);
    return pudoEscribir;
}

void Duenio::leer(Duenio *vec, int cantidadRegistrosALeer, const char *ruta)
{
    FILE *p = fopen(ruta, "rb");
    if (p == NULL)
    {
        return;
    }

    fread(vec, sizeof(Duenio), cantidadRegistrosALeer, p);
    fclose(p);
}
void Duenio::vaciar(const char *ruta)
{
    FILE *p = fopen(ruta, "wb");
    if (p == NULL)
    {
        return;
    }
    fclose(p);
}

bool Duenio::guardar(Duenio *vec, int cantidadRegistrosAEscribir, const char *ruta)
{
    FILE *p = fopen(ruta, "ab");
    if (p == NULL)
    {
        return false;
    }

    int cantidadRegistrosEscritos = fwrite(vec, sizeof(Duenio), cantidadRegistrosAEscribir, p);
    fclose(p);
    return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

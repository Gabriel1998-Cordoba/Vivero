#include <iostream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "FuncionesGlobales.h"

void Cliente::Mostrarr()
{
    Mostrar();
}

Cliente::Cliente()
{
    _idCliente = 0;
}
void Cliente::setNombre(const char *nombre)
{
    strcpy(_nombre, nombre);
}
const char *Cliente::getNombre()
{
    return _nombre;
}
void Cliente::setIDCliente(int idCliente)
{
    _idCliente = idCliente;
}
void Cliente::setApellido(const char *apellido)
{
    strcpy(_apellido, apellido);
}
int Cliente::getIDCliente()
{
    return _idCliente;
}
const char *Cliente::getApellido()
{
    return _apellido;
}
void Cliente::Cargar()
{
    int auxiliarValidacion = CONtarRegistros();
    if (auxiliarValidacion == -1)
    {
        _idCliente = auxiliarValidacion + 2;
    }
    else
    {
        _idCliente = auxiliarValidacion + 1;
    }

    char apellido[50];
    char nombre[50];
    cout << "ID CLIENTE: " << this->getIDCliente() << endl;

    cout << "APELLIDO: ";
    cargarCadena(apellido, 50);
    setApellido(apellido);
    cout << "NOMBRE: ";
    cargarCadena(nombre, 50);
    setNombre(nombre);
    Sujeto::CargarSujeto(/*0*/);
}
void Cliente::Mostrar()
{
    cout << "ID Cliente: " << this->getIDCliente() << endl;
    cout << "Apellido: " << this->getApellido() << endl;
    Sujeto::MostrarSujeto();
}
bool Cliente::GuardarArchivo()
{
    FILE *p;
    p = fopen("Cliente.dat", "ab");
    if (p == NULL)
    {

        return false;
    }
    bool escribio = fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}
bool Cliente::LeerArchivo(int indice)
{

    FILE *p;
    p = fopen("Cliente.dat", "rb");
    if (p == NULL)
    {

        return false;
    }
    fseek(p, sizeof(Cliente) * indice, 0);
    bool leyo = fread(this, sizeof(Cliente), 1, p);
    fclose(p);
    return leyo;
}
/*--------------------------------------------------*/

int Cliente::CONtarRegistros(const char *ruta)
{
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL)
        return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Cliente);
}
bool Existe(Cliente cli)
{
    Cliente reg;
    int tam = 0;
    tam = reg.CONtarRegistros();

    for (int i = 0; i < tam; i++)
    {
        reg.LeerArchivo(i);
        if (cli.getIDCliente() == reg.getIDCliente())
        {
            return true;
        }
    }
    return false;
}

void Cliente::CargarDatosClienteEnArchivo()
{
    FILE *p;
    Cliente reg;
    p = fopen("Cliente.dat", "ab");
    if (p == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    reg.Cargar();
    fwrite(&reg, sizeof reg, 1, p);

    fclose(p);
}
void Cliente::MostrarDatosClienteEnArchivo()
{

    Cliente reg;
    FILE *p;

    p = fopen("Cliente.dat", "rb");
    if (p == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while (fread(&reg, sizeof reg, 1, p) == 1)
    {
        if (reg.getEstado() == 1)
        {
            reg.Mostrar();
        }
    }

    fclose(p);
}

Cliente Cliente::leerRegistros(int indice, const char *ruta)
{
    Cliente reg;
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL)
    {
        return reg;
    }
    fseek(p, sizeof reg * indice, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

bool ValidarCliente(int id)
{
    Cliente reg;

    int tam = 0;
    tam = reg.CONtarRegistros();

    if (tam == -1)
    {
        return false;
    }
    else
    {

        for (int i = 0; i < tam; i++)
        {
            reg = reg.leerRegistros(i);
            if ((reg.getIDCliente()) == (id)) //-1
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
bool Cliente::reemplazarRegistroCliente(Cliente reg, int posicionAReemplazar)
{
    FILE *p = fopen("Cliente.dat", "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, posicionAReemplazar * sizeof(Duenio), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Duenio), 1, p);
    fclose(p);
    return pudoEscribir;
}

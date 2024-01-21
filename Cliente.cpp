#include <iostream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "FuncionesGlobales.h"

void Cliente::setIDCliente(int idCliente)
{
    _idCliente;
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
    int idcliente=0;
    char apellido[50];
    cout << "INGRESE LOS SIGUIENTES DATOS: " << endl;
    cout << " ID CLIENTE: ";
    cin >> idcliente;
    setIDCliente(idcliente);
    cout << "APELLIDO: ";
    cargarCadena(apellido, 50);
    setApellido(apellido);
    Sujeto::CargarSujeto(0);
}
void Cliente::Mostrar()
{
    cout << "ID Cliente: " << getIDCliente() << endl;
    cout << "Apellido: " << getApellido() << endl;
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
int contarRegistros()
    {
        FILE *p;
        p = fopen("Cliente.dat", "rb");
        if (p == NULL)
            return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Cliente);
    }

bool Existe( Cliente cli )
{
    Cliente reg;
    int tam = 0;
    tam = contarRegistros();

    for (int i = 0; i < tam; i++)
    {
      reg.LeerArchivo(i);
        if (cli.getIDCliente() ==reg.getIDCliente())
        {
            return true;
        }
    }
    return false;
}

void Cliente::CargarDatosClienteEnArchivo(){
    FILE *p;
    Cliente reg;
    p = fopen("Cliente.dat", "ab");
    if (p == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    reg.Cargar();
    fwrite(&reg, sizeof reg, 1, p);

    fclose(p);
}
void Cliente::MostrarDatosClienteEnArchivo(){
    Cliente reg;
    FILE *p;

    p = fopen("Cliente.dat", "rb");
    if (p == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while (fread(&reg, sizeof reg, 1, p)==1){
        reg.Mostrar();
    }

    fclose(p);
}

Cliente Cliente::leerRegistros(int indice,const char* ruta){
    Cliente reg;
    FILE *p;
    p = fopen(ruta, "rb");
    if (p == NULL){
        return reg;
    }
    fseek(p, sizeof reg * indice, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}
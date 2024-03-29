#include <iostream>
#include <cstring>
using namespace std;
#include "FuncionesGlobales.h"
#include "Articulo.h"

void Articulo::setNombre(const char *nombre)
{
    strcpy(_nombre, nombre);
}

Articulo::Articulo()
{
    _idArticulo = 0;
}
int Articulo::getID() const
{
    return _idArticulo;
}

const char *Articulo::getNombre() const
{
    return _nombre;
}

void Articulo::setId(int id)
{
    _idArticulo = id;
}

void Articulo::setPrecio(float precio)
{
    _precio = precio;
}

float Articulo::getPrecio() const
{
    return _precio;
}

int Articulo::getTipoDeArticulo() const { return _TipoDeArticulo; }
void Articulo::setTipoDeArticulo(int TipoDeArticulo)
{
    _TipoDeArticulo = TipoDeArticulo;
}
int Articulo::getStock() const
{
    return _stock;
}
void Articulo::setStock(int stock)
{
    _stock = stock;
}
bool Articulo::getEstado() const { return _estado; }
void Articulo::setEstado(bool estado)
{
    _estado = estado;
}

void Articulo::Cargar(int totalDeRegistros, int TipoDeArticulo)
{

    char nombre[30];
    float precio;
    int stock;

    char texto[30];

    totalDeRegistros++;
    cout << "ID: " << totalDeRegistros << endl;
    setId(totalDeRegistros);
    cout << "Nombre: ";
    cargarCadena(nombre, 30);
    setNombre(nombre);

    do
    {
        cout << "Precio: ";
        cargarCadena(texto, 30);

        precio = (float)EsUnNumeroYConvierteEnNumero(texto);

        if (precio == -1)
        {
            cout << "se debe de ingresar numeros enteros" << endl;
        }

    } while (precio == -1);

    setPrecio(precio);
    setTipoDeArticulo(TipoDeArticulo);
    cout << "Stock: ";
    cin >> stock;
    if(stock>0){setStock(stock);}
    setEstado(1);
}

void Articulo::Mostrar()
{

    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Precio: " << getPrecio() << endl;
    cout << "Tipo De Articulo: " << getTipoDeArticulo() << endl;
    cout << "Stock: " << getStock() << endl;
    setEstado(1);
    cout << "ESTADO: : " << getEstado() << endl;
}

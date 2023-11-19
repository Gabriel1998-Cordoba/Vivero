#include<iostream>
#include <cstring>

using namespace std;

#include "Proveedor.h"

void Proveedor::setIDProveedor(int idproveedor)
{
    _idProveedor = idproveedor;
}
int Proveedor::getIDProveedor()
{
    return _idProveedor;
}
void Proveedor::Cargar()
{
    cout << "INGRESE EL ID: " << endl;
    cin >> _idProveedor;
    Sujeto::CargarSujeto();
}
void Proveedor::Mostrar()
{
cout<<"ID PROVEEDOR: "<<getIDProveedor();
MostrarSujeto();
}
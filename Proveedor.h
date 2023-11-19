#pragma once
#include "Sujeto.h"
class Proveedor : public Sujeto
{
private:
    int _idProveedor;

public:
    void setIDProveedor(int);
    int getIDProveedor();
    void Cargar();
    void Mostrar();
};
#pragma once
#include "Fecha.h"
class RegistroCompra{

private:
int _idCompra;
int _idProveedor;
Fecha _Fecha;
char _modoDePago[30];

public:
void setIdCompra(int);
void setIdProveedor (int );
void setFecha (Fecha);
void setModoDePago (const char *);
int getIdCompra();
int getIdProveedor();
Fecha getFecha();
const char *getModoDePago();
void Cargar();
void Mostrar();

int contarRegistros();


};
#pragma once
#include "Fecha.h"
#include"Herramientas.h"
#include"Planta.h"
#include"Agroquimicos.h"
#include"Sujeto.h"

class RegistroCompra{

private:
int _idCompra;
int _idProveedor;
Fecha _Fecha;
char _modoDePago[30];
Sujeto _Sujeto;

public:
void setIdCompra(int);
void setIdProveedor (int );
void setFecha (Fecha);
void setFecha (int dia,int mes,int anio);
void setModoDePago (const char *);
int getIdCompra();
int getIdProveedor();
Fecha getFecha();
const char *getModoDePago();

void CargarCompra();

void Mostrar();

int contarRegistros();
void CargarArchivoCompra();
void MostrarArchivoCompra();

RegistroCompra leerRegistro(int pos);
RegistroCompra LeerRegistrosPorIdCompra(int IdCompra);

Sujeto getSujeto() const { return _Sujeto; }
void setSujeto(const Sujeto &Sujeto) { _Sujeto = Sujeto; }

};
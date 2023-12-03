#pragma once
#include "Fecha.h"
#include"Herramientas.h"
#include"Planta.h"
#include"Agroquimicos.h"
#include"Sujeto.h"

class RegistroCompra{

private:
int _idCompra;
int _idCliente;
Fecha _Fecha;
char _modoDePago[30];
// Sujeto _Sujeto;//este no 
public:

void setIdCompra(int);
void setIdCliente (int );
void setFecha (Fecha);
void setFecha (int dia,int mes,int anio);
void setModoDePago (const char *);
int getIdCompra();
int getIdCliente();
Fecha getFecha();
const char *getModoDePago();

void CargarCompra(int,int );

void Mostrar();

int contarRegistros();
bool GuardarCompra();
void MostrarArchivoCompra();

RegistroCompra leerRegistro(int pos);
// RegistroCompra LeerRegistrosPorIdCompra(int IdCompra);

//     Sujeto& getSujeto() { return _Sujeto; }
//     void setSujeto(const Sujeto &Sujeto) { _Sujeto = Sujeto; }
 };
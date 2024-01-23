#pragma once
#include "FuncionesGlobales.h"
#include "Fecha.h"

class RegistroVenta{
private:
int _idVenta;
int _idCliente;
Fecha _fecha;
char _modoDePago[30];
public:
void setIdVenta(int );
void setIdCliente(int );
void setFecha (Fecha );
void setFecha(int,int,int);
void setModoDePago(const char *);

int getIdVenta();
int getIdCliente();
Fecha getFecha();
const char * getModoDePago();
void CargarCompra();

void Mostrar();

int contarRegistros(const char* nombre = "registroVenta.dat");
void CargarArchivoVenta();
void MostrarArchivoVenta();
RegistroVenta leerRegistro(int pos,const char * nombre = "registroVenta.dat");

};
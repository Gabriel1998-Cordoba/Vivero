#pragma once



#include "Fecha.h"
// #include"Herramientas.h"
// #include"Planta.h"
// #include"Agroquimicos.h"
// #include"Sujeto.h"


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

void CargarCompra(RegistroCompra ,int );

void Mostrar();

int contarRegistros(const char * nombre = "registrocompra.dat");
bool GuardarCompra();

void CargarDatosRegistroCompraEnArchivo(RegistroCompra objR ,int idcliente);
void MostrarArchivoCompra();

RegistroCompra leerRegistro(int pos,const char * nombre = "registrocompra.dat");

 };
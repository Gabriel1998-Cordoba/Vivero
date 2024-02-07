#pragma once
#include"RegistroCompra.h"
#include"DetalleFacturaCompra.h"
#include"Cliente.h"
#include "Herramientas.h"
#include "Planta.h"
#include "Agroquimicos.h"
void cargarCadena(char *palabra, int tamano);
void SaltoDeLinea(int tam=10);
void GenerarFactura(RegistroCompra objR,int id);


Planta BuscarPlanta(int idArticulo);
Herramientas BuscarHerramienta(int idArticulo);

int BuscarPosicion(Planta obj);
int BuscarPosicion(Agroquimicos obj);
int BuscarPosicion(Herramientas obj);
void FacturaXNroFactura();
void CambiarID(int& id);

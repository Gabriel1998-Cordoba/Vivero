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
Agroquimicos BuscarAgroquimicos(int idArticulo);
Cliente buscarCliente(int idCliente);

int BuscarPosicion(Planta obj);
int BuscarPosicion(Agroquimicos obj);
int BuscarPosicion(Herramientas obj);
float BuscarPrecioCompra(int IdCompra);
int buscarMaximo(int *vPlanta,int tamRegPlanta);
void FacturaXNroFactura();
void CambiarID(int& id);
void RecaudacionMensual(int mesIngresado);
void RecaudacionAnual(int AnioIngresado);
void ponerEnCeroVector(int *v,int tamanio);
void cargarVectordeAcumulacion(int *v, Cliente objC);
int ContadorDeCliente(int idCliente);

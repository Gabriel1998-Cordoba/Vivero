#pragma once
#include"RegistroCompra.h"
#include"DetalleFacturaCompra.h"
#include"Cliente.h"


void cargarCadena(char *palabra, int tamano);
void SaltoDeLinea(int tam=10);
void GenerarFactura(RegistroCompra objR,int id);

//void CambiarID(int& id);
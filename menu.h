#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "FuncionesGlobales.h"
#include "RegistroCompra.h"
#include "DetalleFacturaCompra.h"
#include "bkpDetalleFacturaCompra.h"
#include "Cliente.h"
#include "menu.h"
#include "Duenio.h"
#include "bkpDuenio.h"
#include "Planta.h"
#include "bkpPlanta.h"
#include "bkpHerramientas.h"
#include "Herramientas.h"
#include "bkpAgroquimicos.h"
#include "Agroquimicos.h"

#include "Cliente.h"
#include "bkpCliente.h"
#include "bkpRegistroCompra.h"
#include "bkpRegistroVenta.h"

void menuPrincipal();

/*****************************************************************************************/

//                EMPRESA
void menuEmpresa(int opcion);

/*****************************************************************************************/

//                PERSONA
void menuPersona(int opcion);
// Compra
void menuCompraPersona(int opcion/*, RegistroCompra objR*/);

void menuCompraPlantaPersona(int opcion);
void menuCompraHerramientaPersona(int opcion,Herramientas *v,int tam,int *vPosH);
void menuCompraAgroquimicosPersona(int opcion);

// Venta
void menuVentaPersona(int opcion);

void menuCompraPlantaPersona(int opcion, RegistroCompra objR);
void menuCompraHerramientaPersona(int opcion, RegistroCompra objR);
void menuCompraAgroquimicosPersona(int opcion, RegistroCompra objR);

void menuVentaPlantaPersona(int opcion);
void menuVentaHerramientaPersona(int opcion);
void menuVentaAgroquimicosPersona(int opcion);

/*****************************************************************************************/
//                DUEÑO
void menuDuenio(int opcion);
/// CargarDatos
void CargarDatos(int opcion);     //'ab' de archivos
void ModificarDatos(int opcion);  //'rb' que lo lea y modifique
// void LimpiarDatos(int opcion);    //'wb' de archivos == 'baja Fisica'
void ListarDatos(int opcion);     // seleccionar el archivo que quieres que abra y muestre
void ContarRegistros(int opcion); // Cuenta todos los registros dentro del bloc de notas
void CargarDatosDelDuenio(int opcion);

/*****************************************************************************************/
// Funciones Backups

void configuracionBackup();

void CrearBackups();
void RestarurarBackups();
void MostrarBackups();
/*****************************************************************************************/
//Funcion para borar archivos.dat

void LimpiarDatosDeArchivo();
/*****************************************************************************************/


void Informes();


/*****************************************************************************************/

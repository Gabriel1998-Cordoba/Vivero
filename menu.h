#pragma once

void menuPrincipal();

/*****************************************************************************************/

//                EMPRESA
void menuEmpresa(int opcion);

/*****************************************************************************************/

//                PERSONA
void menuPersona(int opcion);

/*****************************************************************************************/
//                DUEÑO
void menuDuenio(int opcion);
///CargarDatos
void CargarDatos(int opcion);//'ab' de archivos
void ModificarDatos(int opcion);//'rb' que lo lea y modifique
void LimpiarDatos(int opcion);//'wb' de archivos == 'baja Fisica'
void ListarDatos(int opcion);//seleccionar el archivo que quieres que abra y muestre
void ContarRegistros(int opcion);//Cuenta todos los registros dentro del bloc de notas

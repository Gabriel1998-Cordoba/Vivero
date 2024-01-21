#pragma once
#include "Sujeto.h"
class Cliente: public Sujeto{
private:
int _idCliente;
char _apellido[50];
public:
void setIDCliente(int);
void setApellido(const char *);
int getIDCliente();
const char *getApellido();
void Cargar();
void Mostrar();
bool GuardarArchivo();
bool LeerArchivo(int);//2/12/2023 gabi desarrollo
int CONtarRegistros(const char *ruta = "Cliente.dat");
void CargarDatosClienteEnArchivo();
void MostrarDatosClienteEnArchivo();
Cliente leerRegistros(int indice,const char* ruta = "Cliente.dat");
};
/////
bool Existe(Cliente cli );
int contarRegistros();
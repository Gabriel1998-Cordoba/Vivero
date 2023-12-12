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
};
/////
int ContarRegistros();
bool Existe(Cliente cli );
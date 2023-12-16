#pragma once

#include"Fecha.h"
#include"Herramientas.h"
#include"Planta.h"
#include"Agroquimicos.h"

class DetalleFacturaCompra {
    
private:
    int _idArticulo;
     int _TipoDeArticulo;//prueba
    int _idCompra;
    int _cantidad;
    float _precio;
   //  int _TipoDeArticulo;
    bool _estado;
   //  char _nombre[30];//
    //Fecha _fecha;//


/*--------------------------*/
//HERRAMIENTA
// char marca[30];
/*--------------------------*/
//PLANTA
char  _estacion[30];
/*--------------------------*/
//AGROQUIMICO
int _tipoAgroquimico; //1-Ecologico,2-Quimico
/*--------------------------*/

public:
DetalleFacturaCompra();
/*SETTERS*/
void setIdArticulo(int);
void setIdCompra(int);
void setCantidad(int );
void setPrecio(float);
void setTipoDeArticulo(int);
void setEstado(bool estado);
/*GETTERS*/
bool getEstado() const;
int getIdArticulo();
int getIdCompra();
int getTipoDeArticulo();//prueba
int getCantidad();
float getPrecio();

/*METODOS DE MANEJOS DE ARCHIVO*/
bool AutoCargar(int idCliente,int idCompra,float precio,int tipoArticulo); //prueba
bool GuardarEnArchivo();
int contarRegistros();
bool leerRegistroIdCompra(int IdComp);

void Mostrar();

~DetalleFacturaCompra();
};
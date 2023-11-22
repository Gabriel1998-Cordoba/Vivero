#pragma once

#include"Fecha.h"
#include"Herramientas.h"
#include"Planta.h"
#include"Agroquimicos.h"
#include"RegistroCompra.h"
class DetalleFacturaCompra : public RegistroCompra{
    
private:
    int _idDetalleFacturaCompra;
   // int _idArticulo;
    int _idCompra;
    int _cantidad;
    float _precio;
    int _TipoDeArticulo;// 
    bool _estado;//
    char _nombre[30];//
    Fecha _fecha;//


/*--------------------------*/
//HERRAMIENTA
/*--------------------------*/
//PLANTA
char  _estacion[30];
/*--------------------------*/
//AGROQUIMICO
int _tipoAgroquimico; //1-Ecologico,2-Quimico
/*--------------------------*/

public:

void setIdArticulo(int);
void setIdCompra(int);
void setCantidad(int );
void setPrecio(float);
int getIdArticulo();
int getIdCompra();
int getCantidad();
float getPrecio();
void Mostrar();
void MostrarPlanta();
const char * getEstacion() const;
void setEstacion(const char * estacion);
int tipoAgroquimico() const;
void setTipoAgroquimico(int tipoAgroquimico);
int getTipoDeArticulo() const;
void setTipoDeArticulo(int TipoDeArticulo);
bool getEstado() const;
void setEstado(bool estado);
const char * getNombre() const;
void setNombre(const char *nombre);
Fecha getFecha() const;
void setFecha(const Fecha &fecha);
void setDiaMesAnioFecha(int dia,int mes,int anio);

DetalleFacturaCompra();
~DetalleFacturaCompra(){}

void AutoCargar(Herramientas objH,int idCompra); //HACER
void AutoCargar(Planta objP,int idCompra); //HACER
void AutoCargar(Agroquimicos objA,int idCompra); //HACER

void MostrarAutoCargarHerramienta(); //HACER
void MostrarAutoCargarPlanta(int valorDNI); //HACER
void MostrarAutoCargarAgroquimicos(); //HACER


int contarRegistros();

int getIdDetalleFacturaCompra() const { return _idDetalleFacturaCompra; }
void setIdDetalleFacturaCompra(int idDetalleFacturaCompra) { _idDetalleFacturaCompra = idDetalleFacturaCompra; }

};
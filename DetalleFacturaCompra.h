#pragma once

#include"Fecha.h"
#include"Herramientas.h"
#include"Planta.h"
#include"Agroquimicos.h"
#include"RegistroCompra.h"
class DetalleFacturaCompra : public RegistroCompra{
    
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

void setIdArticulo(int);
void setIdCompra(int);
void setCantidad(int );
void setPrecio(float);
void setTipoDeArticulo(int);
int getIdArticulo();
int getIdCompra();
int getTipoDeArticulo();//prueba
int getCantidad();
float getPrecio();
void Mostrar();
//void MostrarPlanta();
//void MostrarAgroquimicos();
//const char * getEstacion() const;
//void setEstacion(const char * estacion);
//int tipoAgroquimico() const;
//void setTipoAgroquimico(int tipoAgroquimico);
// int getTipoDeArticulo() const;
// void setTipoDeArticulo(int TipoDeArticulo);
bool getEstado() const;
void setEstado(bool estado);
// const char * getNombre() const;
// void setNombre(const char *nombre);
// Fecha getFecha() const;

// void setFecha(const Fecha &fecha);
// void setDiaMesAnioFecha(int dia,int mes,int anio);

DetalleFacturaCompra();
~DetalleFacturaCompra(){}

//void AutoCargar(Herramientas objH,int idCompra); //HACER
bool AutoCargar(int idCliente,int idCompra,float precio,int tipoArticulo); //prueba
//void AutoCargar(Agroquimicos objA,int idCompra); //HACER

// void MostrarAutoCargarHerramienta(); //HACER
// //void MostrarAutoCargarPlanta(int valor=-1);
// void MostrarAutoCargarAgroquimicos(int valor=-1); //HACER

 bool GuardarEnArchivo();
int contarRegistros();

DetalleFacturaCompra leerRegistroIdCompra(int IdComp);

// int getIdDetalleFacturaCompra() const { return _idDetalleFacturaCompra; }
// void setIdDetalleFacturaCompra(int idDetalleFacturaCompra) { _idDetalleFacturaCompra = idDetalleFacturaCompra; }

};
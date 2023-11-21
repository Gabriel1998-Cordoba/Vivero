#pragma once

#include"Articulo.h"

class Planta : public Articulo{

    private:
        char  _estacion[30];
    public:

    void setEstacion(const char *);
    const char *getEstacion();

    void CargarArchivoPlanta(int totalDeRegistros,int TipoDeArticulo); //ab
    void CrearArchivoPlanta(int totalDeRegistros,int TipoDeArticulo); //wb

    void CargarPlanta(int totalDeRegistros,int TipoDeArticulo); //int TipoDeArticulo == opcion en el menu, donde ingresas que quiere cargar = Plantas,Herramientas,Agroquimicos,etc
    void MostrarPlanta();
    int contarRegistros();
    bool borrarRegistroPlanta();
    Planta leerRegistroPlanta(int pos);
    void ListarPlanta();

void Opcion1Compra();
void Opcion2Compra();
void Opcion3Compra();
void Opcion4Compra();
void Opcion5Compra();

};
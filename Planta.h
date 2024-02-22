#pragma once

#include"Articulo.h"
#include"RegistroCompra.h"

class Planta : public Articulo{

    private:
        char  _estacion[30];
    public:

    void setEstacion(const char *);
    const char *getEstacion();

    void CargarArchivoPlanta(int totalDeRegistros,int TipoDeArticulo); //ab
    void CrearArchivoPlanta(int totalDeRegistros,int TipoDeArticulo); //wb

    void CargarPlanta(int TipoDeArticulo); //int TipoDeArticulo == opcion en el menu, donde ingresas que quiere cargar = Plantas,Herramientas,Agroquimicos,etc
    void MostrarPlanta();
    void Mostrarr();
    int contarRegistros(const char* nombre = "planta.dat");
    bool borrarRegistroPlanta();
    Planta leerRegistroPlanta(int pos,const char* nombre = "planta.dat");
    void ListarPlanta();
    bool reemplazarRegistroPlanta(Planta reg, int posicionAReemplazar);
    bool MostrarArchivoPlanta();
    


void Opcion1Compra();
void Opcion2Compra();
void Opcion3Compra(RegistroCompra objR);


};
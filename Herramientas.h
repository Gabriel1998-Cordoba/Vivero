#pragma once
#include"Articulo.h"
#include"RegistroCompra.h"

class Herramientas : public Articulo{
    private:

    public:
        void CargarArchivoHerramienta(int totalDeRegistros,int TipoDeArticulo); //ab

        void CargarHerramienta(int totalDeRegistros,int TipoDeArticulo);
        void MostrarHerramienta();

        int contarRegistros(const char* nombre = "herramientas.dat");
        bool borrarRegistroHerramienta();
        Herramientas leerRegistroHerramienta(int pos,const char* nombre = "herramientas.dat");
        void ListarHerramienta();

        bool ListarHerramientaPorCodigoHerramienta(int codigoHerramienta);
        bool MostrarArchivoHerramienta();

void Opcion1Compra();   //HACER
void Opcion2Compra();   //HACER
void Opcion3Compra(RegistroCompra objR);   //HACER
// void Opcion4Compra();   //HACER
// void Opcion5Compra();   //HACER

};
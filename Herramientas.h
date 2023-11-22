#pragma once
#include"Articulo.h"

class Herramientas : public Articulo{
    private:

    public:
        void CargarArchivoHerramienta(int totalDeRegistros,int TipoDeArticulo); //ab

        void CargarHerramienta(int totalDeRegistros,int TipoDeArticulo);
        void MostrarHerramienta();

        int contarRegistros();
        bool borrarRegistroHerramienta();
        Herramientas leerRegistroHerramienta(int pos);
        void ListarHerramienta();
    

void Opcion1Compra();   //HACER
void Opcion2Compra();   //HACER
void Opcion3Compra(int );   //HACER
// void Opcion4Compra();   //HACER
// void Opcion5Compra();   //HACER

};
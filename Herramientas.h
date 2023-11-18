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
    
};
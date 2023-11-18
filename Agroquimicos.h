#pragma once

#include"Articulo.h"

class Agroquimicos : public Articulo{

    private:
    int _tipoAgroquimico; //1-Ecologico,2-Quimico
    public:
    void setTipoAgroquimico(int tipoAgroquimico);
    int getTipoAgroquimico();

    void CargarArchivoAgroquimicos(int totalDeRegistros,int TipoDeArticulo); //ab

    void CargarAgroquimicos(int totalDeRegistros,int TipoDeArticulo);
    void MostrarAgroquimicos();

        int contarRegistros();
        bool borrarRegistroAgroquimicos();
        Agroquimicos leerRegistroAgroquimicos(int pos);
        void ListarAgroquimicos();
};
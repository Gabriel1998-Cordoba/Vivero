#pragma once

#include "Articulo.h"

class Agroquimicos : public Articulo
{

private:
    int _tipoAgroquimico; // 1-Ecologico,2-Quimico
public:
    void setTipoAgroquimico(int tipoAgroquimico);
    int getTipoAgroquimico();

    void CargarArchivoAgroquimicos(int TipoDeArticulo); // ab

    void CargarAgroquimicos(int TipoDeArticulo);
    void MostrarAgroquimicos();

    void Mostrarr();



    int contarRegistros(const char *ruta = "agroquimicos.dat");
    bool borrarRegistroAgroquimicos();
    Agroquimicos leerRegistroAgroquimicos(int pos, const char *ruta = "agroquimicos.dat");
    bool reemplazarRegistroAgroquimicos(Agroquimicos objA, int posicionAReemplazar);
    void ListarAgroquimicos();

    void Opcion1Compra();             // HACER
    void Opcion2Compra();             // HACER
    void Opcion3Compra(int idCompra); // HACER
};
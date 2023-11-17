#pragma once

class Articulo{

    private:
    int _id;
    char _nombre[30];
    float _precio;
    int _TipoDeArticulo; // cambiar a _TipoDeArticulo
    int _stock;
    bool _estado;
    public:
    Articulo();
    /// SETERS
    void setNombre(const char *nombre);
    void setTipoDeArticulo(int TipoDeArticulo);
    void setPrecio(float precio); //
    void setId(int id);       //       //
    void setStock(int stock);
    void setEstado(bool estado);
    /// GETTERS
    int getID()const;
    const char * getNombre ()const;
    float getPrecio()const;
    int getTipoDeArticulo()const;
    int getStock()const;
    bool getEstado()const;
    void Mostrar();

    void Cargar(int totalDeRegistros,int TipoDeArticulo); //int TipoDeArticulo == opcion en el menu, donde ingresas que quiere cargar = Plantas,Herramientas,Agroquimicos,etc
};
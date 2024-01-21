#pragma once
#include "DetalleFacturaCompra.h"

class bkpDetalleFacturaCompra{

    private:
        DetalleFacturaCompra objDetalleFacturaCompra;
    public:
        //setters y getters
        void setIdArticulo(int idArticulo){objDetalleFacturaCompra.setIdArticulo(idArticulo);}
        int getIdArticulo(){return objDetalleFacturaCompra.getIdArticulo();}

    //metodos

    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();

};
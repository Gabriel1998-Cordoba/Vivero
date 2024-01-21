#pragma once
#include "RegistroCompra.h"

class bkpRegistroCompra{

    private:
        RegistroCompra objRegistroCompra;
    public:
        //setters y getters
        void setObjRegistroCompra(RegistroCompra objRegistroCompra){this->objRegistroCompra = objRegistroCompra;}
        RegistroCompra getObjRegistroCompra(){return objRegistroCompra;}

    //metodos
    
    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};
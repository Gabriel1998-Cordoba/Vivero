#pragma once

#include"Planta.h"

class bkpPlanta {

    private:
        Planta objPlanta;
    public:
        //setters y getters
        void setObjPlanta(Planta objPlanta){this->objPlanta = objPlanta;}
        Planta getObjPlanta(){return objPlanta;}

    //metodos

    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};
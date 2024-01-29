#pragma once
#include"Duenio.h"

class bkpDuenio{

    private:
        Duenio objDuenio;
       /// Duenio objbkpDuenio();
    public:
        //setters y getters
        void setObjDuenio(Duenio objDuenio){this->objDuenio = objDuenio;}
        Duenio getObjDuenio(){return objDuenio;}

    //metodos
    
    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
    
};
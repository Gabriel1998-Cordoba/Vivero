#pragma once
#include"RegistroVenta.h"

class bkpRegistroVenta{

    private:
        RegistroVenta objRegistroVenta;
    public:
        //setters y getters
        void setRegistroVenta(RegistroVenta objRegistroVenta){this->objRegistroVenta = objRegistroVenta;}
        RegistroVenta getRegistroVenta(){return objRegistroVenta;}

    //metodos
    
    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};

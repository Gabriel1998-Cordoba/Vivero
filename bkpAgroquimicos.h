#pragma once
#include"Agroquimicos.h"

class bkpAgroquimicos{

    private:
        Agroquimicos objAgroquimicos;
    public:
        //setters y getters
        void setAgroquimicos(Agroquimicos objAgroquimicos){this->objAgroquimicos=objAgroquimicos;}
        Agroquimicos getAgroquimicos(){return objAgroquimicos;}

    //metodos

    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};
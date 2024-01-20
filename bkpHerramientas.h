#pragma once
#include"Herramientas.h"

class bkpHerramientas{

    private:
        Herramientas objHerramientas;
    public:
        //setters y getters
        void setObjHerramientas(Herramientas objHerramientas){this->objHerramientas = objHerramientas;}
        Herramientas getObjHerramientas(){return objHerramientas;}

    //metodos
    
    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};
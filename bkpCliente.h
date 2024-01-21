#pragma once
#include"Cliente.h"

class bkpCliente{

    private:
        Cliente objCliente;
    public:
        //setters y getters
        void setObjCliente(const Cliente& cliente){objCliente = cliente;}
        const Cliente& getObjCliente() const {return objCliente;}
    //metodos

    //Aqui quiero crear un Backup que sea un archivo .bkp
        bool CrearBackup();
    //Una vez creado mi backup, lo quiero mostrar en pantalla
        void MostrarBackup();
    //tambien quiero hacer una funcion que me reempieze todo lo que tiene el backup en el archivo original
        bool RestaurarBackup();
};
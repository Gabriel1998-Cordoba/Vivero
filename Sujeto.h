#pragma once

#include"Fecha.h"

class Sujeto{

    private:
        int _idSujeto;
        //Tipo_Docu _TipoDoc[3];
        char _telefono[30];
        bool _estado;
        //Direccion _direccion;
        char _email[30];

    public:
        
        int getIdSujeto() const;
        void setIdSujeto(int idSujeto);


        //Tipo_Docu getTipoDoc();
        //void setTipoDoc(const Tipo_Docu &TipoDoc);

        const char*getTelefono() const;
        void setTelefono(const char* telefono);

        bool getEstado() const;
        void setEstado(bool estado);

        //Direccion direccion() const;
        //void setDireccion(const Direccion &direccion);
        
        const char* email() const;
        void setEmail(const char* email);

        void CargarSujeto(); //HACER
        void MostrarSujeto(); //HACER
};
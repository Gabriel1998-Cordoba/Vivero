#pragma once

#include"Fecha.h"
#include"Tipo_Docu.h"
#include"Fecha.h"
class Sujeto{

    private:
       
        //Tipo_Docu _TipoDoc[3];
        char _telefono[30];
        bool _estado;
        //Direccion _direccion;
        char _email[30];
        Fecha _fecha;

    public:
        
        int getIdSujeto() const;
        void setIdSujeto(int idSujeto);


        Tipo_Docu getTipoDoc();
        void setTipoDoc(const Tipo_Docu &TipoDoc);

        const char*getTelefono() const;
        void setTelefono(const char* telefono);

        bool getEstado() const;
        void setEstado(bool estado);

        //Direccion direccion() const;
        //void setDireccion(const Direccion &direccion);
        
        const char* getEmail() const;
        void setEmail(const char* email);

        void CargarSujeto(); //HACER
        void MostrarSujeto(); //HACER

        Fecha fecha() const { return _fecha; }
        void setFecha(const Fecha &fecha) { _fecha = fecha; }
};
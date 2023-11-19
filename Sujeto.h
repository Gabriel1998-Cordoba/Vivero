#pragma once

#include"Fecha.h"
#include"Tipo_Docu.h"
#include"Direccion.h"
#include"Fecha.h"
class Sujeto : public Fecha,public Direccion,public Tipo_Docu{

    private:
<<<<<<< HEAD
       
        //Tipo_Docu _TipoDoc[3];
=======
        Tipo_Docu _TipoDoc;
        Direccion _direccion;
        Fecha _fecha;
        int _idSujeto;
>>>>>>> fcb7e83b18a9b7d2476d11ee1eb81025f77be14c
        char _telefono[30];
        bool _estado;
        char _email[30];

    public:
        
        int getIdSujeto() const;
        void setIdSujeto(int idSujeto);

        const char*getTelefono() const;
        void setTelefono(const char* telefono);

        bool getEstado() const;
        void setEstado(bool estado);

        const char* getEmail() const;
        void setEmail(const char* email);

        void CargarSujeto(int totalDeRegistros,int TipoDeArticulo);
        void MostrarSujeto();

        Tipo_Docu getTipoDoc() const { return _TipoDoc; }
        void setTipoDoc(const Tipo_Docu &TipoDoc) { _TipoDoc = TipoDoc; }

        Direccion getDireccion() const { return _direccion; }
        void setDireccion(const Direccion &direccion) { _direccion = direccion; }

        Fecha getFecha() const { return _fecha; }
        void setFecha(const Fecha &fecha) { _fecha = fecha; }

};
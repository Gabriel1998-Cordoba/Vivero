#pragma once

class Direccion{

    private:
        char _calle[30];
        int _numero;
        char _ciudad[30];
        char _CP[30]; //Codigo Postal
        char _provincia[30];
        char _pais[30];
    public:
        const char* getCalle() const;
        int getNumero() const;
        const char* getCiudad() const;
        const char* getCP() const;
        const char* getProvincia() const;
        const char* getPais() const;

        void setCalle(const char* calle);
        void setNumero(int numero);
        void setCiudad(const char* ciudad);
        void setCP(const char*cp);
        void setProvincia(const char* provincia);
        void setPais(const char* pais);

        void CargarDireccion();
        void MostrarDireccion();
};
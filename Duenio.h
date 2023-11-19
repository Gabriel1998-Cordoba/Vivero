#pragma once

class Duenio{

    private:
    int _idDuenio;
    float _sueldo;

public:
    
    float getSueldo() const { return _sueldo; }
    void setSueldo(float sueldo) { _sueldo = sueldo; }

    int GetIdDuenio() const { return _idDuenio; }
    void setIdDuenio(int idDuenio) { _idDuenio = idDuenio; }

    void CargarDuenio();
    void MostrarDuenio();

    void CargarDatosDeDuenioEnArchivo(); //HACER
    void MostrarDatosDeDuenioEnArchivo(); //HACER
    void CambiarSueldoCargadoEnArchivo(); //HACER


};
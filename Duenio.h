#pragma once

#include"Sujeto.h"

class Duenio : public Sujeto{

    private:
    int _idDuenio;
    float _sueldo;

public:
    
    float getSueldo() const { return _sueldo; }
    void setSueldo(float sueldo) { _sueldo = sueldo; }

    int GetIdDuenio() const { return _idDuenio; }
    void setIdDuenio(int idDuenio) { _idDuenio = idDuenio; }

    void CargarDuenio(int totalDeRegistros/*,int TipoDeArticulo*/);
    void MostrarDuenio();

    void CargarDatosDeDuenioEnArchivo(int totalDeRegistros/*,int TipoDeArticulo*/);
    void MostrarDatosDeDuenioEnArchivo(); 
    void CambiarSueldoCargadoEnArchivo();
    void MostrarSueldoCargadoEnArchivo(); //HACER
    void BorrarDatosDelDuenio();

    int contarRegistros(const char *);
    Duenio leerRegistro(int pos);
void leer(Duenio *vec, int cantidadRegistrosALeer,const char*);


void vaciar(const char *);

bool guardar(Duenio*vec, int cantidadRegistrosAEscribir,const char *);
    bool reemplazarRegistroDuenio(Duenio reg, int posicionAReemplazar);
    

};
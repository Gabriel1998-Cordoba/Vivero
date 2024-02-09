#include <iostream>
#include <string>
#include "Fecha.h"
#include <ctime>

using namespace std;

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 1900;
}

int Fecha::getDiaActual(){
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _dia = (*f).tm_mday;
    return _dia;
}

int Fecha::getMesActual(){
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _mes = f->tm_mon + 1;
    return _mes;
}

int Fecha::getAnioActual(){
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _anio = f->tm_year + 1900;
    return _anio;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

Fecha::~Fecha(){
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}
void Fecha::Cargar(){
    cout<<"Ingrese DIA= ";
    cin>>_dia;
    cout<<"Ingrese MES= ";
    cin>>_mes;
    cout<<"Ingrese ANIO= ";
    cin>>_anio;
}

void Fecha::Mostrar(){
    cout<<"Su DIA es: "<<_dia<<endl;
    cout<<"Su MES es: "<<_mes<<endl;
    cout<<"Su ANIO es: "<<_anio<<endl;
}

void Fecha::MostrarEnLinea(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

void Fecha::MostrarEnLineaSinSaltoDeLinea(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio;
}
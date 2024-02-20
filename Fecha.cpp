#include <iostream>
#include <string>
#include "Fecha.h"
#include <ctime>
#include "FuncionesGlobales.h"

using namespace std;

Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 1900;
}

int Fecha::getDiaActual()
{
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _dia = (*f).tm_mday;
    return _dia;
}

int Fecha::getMesActual()
{
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _mes = f->tm_mon + 1;
    return _mes;
}

int Fecha::getAnioActual()
{
    time_t t = time(NULL);
    struct tm *f = localtime(&t);

    _anio = f->tm_year + 1900;
    return _anio;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

Fecha::~Fecha()
{
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}
void Fecha::Cargar()
{

    bool band = true;

    do
    {
        band = true;

        cout << "Ingrese DIA= ";
        cin >> _dia;

        cout << "Ingrese MES= ";
        cin >> _mes;
        cout << "Ingrese ANIO= ";
        cin >> _anio;

        band = prueba(_dia, _mes, _anio);

        if ((_anio < 1900) | (_anio > getAnioActual()))
        {
            cout << "ERROR --> Anio mal ingresado" << endl;
            band = false;
        }
        else
        {
            // band = prueba(_dia,_mes,_anio);
        }

        if ((_mes < 1) || (_mes > 12))
        {
            cout << "ERROR --> fuera de rango" << endl;
            cout << "vuelva a ingresar el mes" << endl;
            system("pause");
            band = false;
        }
        else
        {
            if ((_mes == 1) || (_mes == 3) || (_mes == 5) || (_mes == 7) || (_mes == 8) || (_mes == 10) || (_mes == 12))
            {
                if ((_dia < 1) || (_dia > 31))
                {
                    cout << "ERROR --> Fuera de rango" << endl;
                    cout << "vuelva a ingresar el dia" << endl;
                    system("pause");
                    band = false;
                }
            } // cae el mes en 30
            else if ((_mes == 4) || (_mes == 6) || (_mes == 9) || (_mes == 11))
            {
                if ((_dia < 1) || (_dia > 30))
                {
                    cout << "ERROR --> Fuera de rango" << endl;
                    cout << "vuelva a ingresar el dia" << endl;
                    system("pause");
                    band = false;
                }
            }
        }

        // cae el mes en 31

    } while (band == false);
}

void Fecha::Mostrar()
{
    cout << "Su DIA es: " << _dia << endl;
    cout << "Su MES es: " << _mes << endl;
    cout << "Su ANIO es: " << _anio << endl;
}

void Fecha::MostrarEnLinea()
{
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

void Fecha::MostrarEnLineaSinSaltoDeLinea()
{
    cout << _dia << "/" << _mes << "/" << _anio;
}
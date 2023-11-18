#include<iostream>

using namespace std;

#include"Duenio.h"

void Duenio::CargarDuenio(){
float sueldo;
float idDuenio;
cout<<"Su Sueldo es: ";
cin>>sueldo;
setSueldo(sueldo);
cout<<"Su id Duenio es: ";
cin>>idDuenio;
setIdDuenio(idDuenio);
}

void Duenio::MostrarDuenio(){
cout<<"Su Sueldo es: "<<getSueldo();
cout<<"Su id Duenio es: "<<GetIdDuenio();
}

void Duenio::CargarDatosDeDuenioEnArchivo(){

}

void Duenio::MostrarDatosDeDuenioEnArchivo(){

}

void Duenio::CambiarSueldoCargadoEnArchivo(){

}

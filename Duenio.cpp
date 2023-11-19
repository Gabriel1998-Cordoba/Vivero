#include<iostream>

using namespace std;

#include"Duenio.h"

void Duenio::CargarDuenio(int totalDeRegistros,int TipoDeArticulo){

Sujeto::CargarSujeto(totalDeRegistros,TipoDeArticulo);

float sueldo;

cout<<"Su Sueldo es: ";
cin>>sueldo;
setSueldo(sueldo);

totalDeRegistros++;
cout<<"Su id Duenio es: "<< totalDeRegistros<< endl;
setIdDuenio(totalDeRegistros);

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

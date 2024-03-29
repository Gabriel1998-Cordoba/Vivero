#pragma once
#include"RegistroCompra.h"
#include"DetalleFacturaCompra.h"
#include"Cliente.h"
#include "Herramientas.h"
#include "Planta.h"
#include "Agroquimicos.h"
#include "Duenio.h"


using namespace std;

#include<iostream>
#include<string>
#include<cstring>

void cargarCadena(char *palabra, int tamano);
void SaltoDeLinea(int tam=100);
void GenerarFactura(RegistroCompra objR);


Planta BuscarPlanta(int idArticulo);
Herramientas BuscarHerramienta(int idArticulo);
Agroquimicos BuscarAgroquimicos(int idArticulo);
Cliente buscarCliente(int idCliente);

int BuscarPosicion(Planta obj);
int BuscarPosicion(Agroquimicos obj);
int BuscarPosicion(Herramientas obj);
float BuscarPrecioCompra(int IdCompra);
int buscarMaximo(int *vPlanta,int tamRegPlanta);
void FacturaXNroFactura();
void CambiarID(int& id);
void RecaudacionMensual(int mesIngresado);
void RecaudacionAnual(int AnioIngresado);
void ponerEnCeroVector(int *v,int tamanio);
void cargarVectordeAcumulacion(int *v, Cliente objC);
int ContadorDeCliente(int idCliente);
bool AnioBisiesto(int anio);
bool prueba(int _dia,int _mes,int _anio);
bool existeDNI(int indice,int numero);
void MostrarMaximo(int *vP ,int indice1 ,int *vH2,int indice2 ,int *vA3,int indice3);

void ponerEnCeroVector(int *v, int tamanio);
void ponerEnCeroVector(bool *v, int tamanio);


// int EsUnNumeroYConvierteEnNumero(const char* texto, int hasta=1000);
float EsUnNumeroYConvierteEnNumero(const char* texto);

int EsUnNumero(const char* texto, int hasta=1000);

template <typename T>
void MostrarPorPosicion(const char* ruta, T& obj){
    int cont=0;
    FILE *p;
    p=fopen(ruta,"rb");
    if(p==NULL){
        std::cout<<"ERROR --> MostrarPorPosicion()"<<std::endl;
        return;
    }

    while(fread(&obj,sizeof obj,1,p)==1){
        cont++;
        std::cout<<"Posicion "<<cont<<std::endl;
        obj.Mostrarr();    
    }
    
    fclose(p);
}
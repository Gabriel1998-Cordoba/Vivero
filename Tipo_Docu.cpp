#include<iostream>

using namespace std;

#include"Tipo_Docu.h"

void Tipo_Docu::CargarTipoDocu(){

int indice;
int TipoDoc[3]={0};
int numero;

do{

cout<<"SU Tipo Documento es: ";
cin>>indice;
cout<<"Ingrese numero: ";
cin>>numero;

if(setTipoDoc(indice,numero)==false){
cout<<"Tipo de Documento No valido"<<endl;
}

}while(setTipoDoc(indice,numero)==false);



}
void Tipo_Docu::MostrarTipoDocu(){

int valor=-1;

for(int i=0; i<3;i++){

valor = getTipoDoc(i);

if(valor>=0){
    cout<<"SU Tipo Documento es: "<<i+1<<endl;
    cout<<"Ingrese numero: "<<valor<<endl;

}

}

}
#include<iostream>

using namespace std;

#include"Tipo_Docu.h"

void Tipo_Docu::CargarTipoDocu(){

int indice;
int TipoDoc[3]={0};
int numero;

do{

cout<<"SU Tipo Documento es: "<<endl;
cout<<"1 - DNI, 2 - Cuit, 3 - Cuil"<<endl;
cin>>indice;

indice--;

if(setTipoDoc(indice,numero)==false){
system("cls");
cout<<"Tipo de Documento No valido"<<endl<<endl;
}else{
cout<<"Ingrese numero: ";
cin>>numero;
}



}while(setTipoDoc(indice,numero)==false);



}
void Tipo_Docu::MostrarTipoDocu(){

int valor=-1;

for(int i=0; i<3;i++){

valor = getTipoDoc(i);

if(valor>0){
    cout<<"SU Tipo Documento es: "<<i+1;

    if(i==0){
        cout<<" DNI"<<endl;
    }else if(i==1){
        cout<<" Cuit"<<endl;
    }else if(i==2){
        cout<<" Cuil"<<endl;
    }

    cout<<"Ingrese numero: "<<valor<<endl;

}

}

}
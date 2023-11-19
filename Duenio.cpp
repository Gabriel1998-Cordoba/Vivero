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
Sujeto::MostrarSujeto();
cout<<"Su Sueldo es: "<<getSueldo()<<endl;
cout<<"Su id Duenio es: "<<GetIdDuenio()<<endl<<endl;
}

void Duenio::CargarDatosDeDuenioEnArchivo(int totalDeRegistros,int TipoDeArticulo){
FILE *p;
Duenio ClassM;

p=fopen("duenio.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarDuenio(totalDeRegistros,TipoDeArticulo);
fwrite(&ClassM,sizeof (Duenio),1,p);


fclose(p);
}

void Duenio::MostrarDatosDeDuenioEnArchivo(){
Duenio ClassM;
FILE *p;

p=fopen("duenio.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Duenio),1,p)==1){
ClassM.MostrarDuenio();
cout<<"//////////////////"<<endl;
}

fclose(p);

}

void Duenio::CambiarSueldoCargadoEnArchivo(){

}

int Duenio::contarRegistros(){
        FILE *p;
        p=fopen("duenio.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Duenio);
    }


void Duenio::BorrarDatosDelDuenio(){
Duenio ClassM;
FILE *p;

p=fopen("duenio.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

}
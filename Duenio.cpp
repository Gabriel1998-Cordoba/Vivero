#include<iostream>

using namespace std;

#include"Duenio.h"

void Duenio::CargarDuenio(int totalDeRegistros/*,int TipoDeArticulo*/){

Sujeto::CargarSujeto(totalDeRegistros/*,TipoDeArticulo*/);

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

void Duenio::CargarDatosDeDuenioEnArchivo(int totalDeRegistros/*,int TipoDeArticulo*/){
FILE *p;
Duenio ClassM;

p=fopen("duenio.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarDuenio(totalDeRegistros/*,TipoDeArticulo*/);
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
Duenio objD;

float sueldo;

int tam=0,cantidad;
tam=objD.contarRegistros();

objD = objD.leerRegistro(tam-1);

cout<<"Ingrese sueldo:";
cin>>sueldo;

objD.setSueldo(sueldo);

objD.reemplazarRegistroDuenio(objD,(tam-1));

}

void Duenio::MostrarSueldoCargadoEnArchivo(){

Duenio objD;

int tam=0,cantidad;
tam=objD.contarRegistros();

objD = objD.leerRegistro(tam-1);

cout<<"Su sueldo Es :"<<objD.getSueldo()<<endl;

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

Duenio Duenio::leerRegistro(int pos){
        Duenio reg;
        FILE *p;
        p=fopen("duenio.dat", "rb");
        if(p==NULL){
        cout<<"ERRRO = Duenio Duenio::leerRegistro(int pos)"<<endl;
        return reg;
        }
        fseek(p, sizeof(Duenio)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool Duenio::reemplazarRegistroDuenio(Duenio reg, int posicionAReemplazar){
    FILE *p = fopen("duenio.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, posicionAReemplazar * sizeof(Duenio), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Duenio), 1, p);
    fclose(p);
    return pudoEscribir;
}


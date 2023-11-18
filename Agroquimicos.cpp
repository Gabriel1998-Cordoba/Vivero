#include<iostream>
#include <cstring>

using namespace std;

#include"Agroquimicos.h"
#include"FuncionesGlobales.h"
#include"Articulo.h"

/***************************************************************/
void Agroquimicos::setTipoAgroquimico(int tipoAgroquimico){
    _tipoAgroquimico=tipoAgroquimico;
}
/***************************************************************/
int Agroquimicos::getTipoAgroquimico(){
    return _tipoAgroquimico;
}
/***************************************************************/
void Agroquimicos::CargarArchivoAgroquimicos(int totalDeRegistros,int TipoDeArticulo){
FILE *p;
Agroquimicos ClassM;

p=fopen("agroquimicos.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarAgroquimicos(totalDeRegistros,TipoDeArticulo);
fwrite(&ClassM,sizeof (Agroquimicos),1,p);


fclose(p);
}

void Agroquimicos::CargarAgroquimicos(int totalDeRegistros,int TipoDeArticulo){
    Articulo::Cargar(totalDeRegistros,TipoDeArticulo);

int tipoAgroquimico=0;


    do{
        cout<<"Agroquimico 1 == Ecologico"<<endl;
        cout<<"Agroquimico 2 == Quimico"<<endl<<endl;

        cout<<"Ingrese tipo Agroquimico"<<endl;
        cin>>tipoAgroquimico;
        if((tipoAgroquimico!=1)&&(tipoAgroquimico!=2)){
            cout<<"El valor ingresado en tipo Agroquimico no existe"<<endl;
        }else{
            setTipoAgroquimico(tipoAgroquimico);
        }

    }while((tipoAgroquimico!=1)&&(tipoAgroquimico!=2));

}

void Agroquimicos::MostrarAgroquimicos()
{
 Articulo::Mostrar();
 cout<<"Agroquimico: "<<getTipoAgroquimico()<<endl;
 cout<<endl;

}

int Agroquimicos::contarRegistros(){
        FILE *p;
        p=fopen("agroquimicos.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Agroquimicos);
    }

bool Agroquimicos::borrarRegistroAgroquimicos(){
    FILE *p;
    p=fopen("agroquimicos.dat", "wb");
    if(p==nullptr){ return false;}
    fclose(p);
    return true;
}

Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos){
   Agroquimicos reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen("agroquimicos.dat", "rb");
    if(p==NULL){
     cout<<"Error = Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos)"<<endl;
     return reg;
    }
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

void Agroquimicos::ListarAgroquimicos(){



Agroquimicos ClassM;
FILE *p;

p=fopen("agroquimicos.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Agroquimicos),1,p)==1){
ClassM.MostrarAgroquimicos();
}

fclose(p);

}
#include<iostream>

using namespace std;

#include"bkpPlanta.h"

/*****************************************************************/
bool bkpPlanta::CrearBackup(){
    FILE *p;
    bkpPlanta objbkpPlanta;
    p = fopen("bkpPlanta.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpPlanta::CrearBackup()"<<endl;
        system("pause");
        return false;
    }

    int tam = objPlanta.contarRegistros();

    for(int i=0; i<tam; i++){
        objbkpPlanta.setObjPlanta(objPlanta.leerRegistroPlanta(i));
        fwrite(&objbkpPlanta, sizeof(bkpPlanta), 1, p);
    }

    fclose(p);
    return true;
}
/*****************************************************************/
void bkpPlanta::MostrarBackup(){
    FILE *p;
    bkpPlanta objbkpPlanta;
    p = fopen("bkpPlanta.dat", "rb");
    if(p==NULL){
        cout<<"ERROR de bool bkpPlanta::MostrarBackup()"<<endl;
        system("pause");
        return;
    }

    while(fread(&objbkpPlanta, sizeof(bkpPlanta), 1, p)==1){
        objbkpPlanta.getObjPlanta().MostrarPlanta();
        cout<<endl;
    }

    fclose(p);
}
/*****************************************************************/
bool bkpPlanta::RestaurarBackup(){
    //primero quiero que el archivos planta.dat quede vacio
    FILE *p;
    p = fopen("planta.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpPlanta::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }
    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de planta.dat
    int tam = objPlanta.contarRegistros();

    if(tam==-1){
        cout<<"ERROR de bool bkpPlanta::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objPlanta = objPlanta.leerRegistroPlanta(i);
        fwrite(&objPlanta, sizeof(Planta), 1, p);

        //quiero mostrarlo
        objPlanta.MostrarPlanta();
    }

    fclose(p);
    return true;
}
/*****************************************************************/
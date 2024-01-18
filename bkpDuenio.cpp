#include<iostream>

using namespace std;

#include"bkpDuenio.h"

/*****************************************************************/
bool bkpDuenio::CrearBackup(){

    FILE *p;
    bkpDuenio objbkpDuenio;
    p = fopen("bkpDuenio.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpDuenio::CrearBackup()"<<endl;
        system("pause");
        return false;
    }

    int tam = objDuenio.contarRegistros("duenio.dat");

    for(int i=0; i<tam; i++){
        objbkpDuenio.setObjDuenio(objDuenio.leerRegistro(i));
        fwrite(&objbkpDuenio, sizeof(bkpDuenio), 1, p);
    }
    fclose(p);
    return true;

}
/*****************************************************************/
void bkpDuenio::MostrarBackup(){
    FILE *p;
    bkpDuenio objbkpDuenio;
    p = fopen("bkpDuenio.dat", "rb");
    if(p==NULL){
        cout<<"ERROR de bool bkpDuenio::MostrarBackup()"<<endl;
        system("pause");
        return;
    }

    while(fread(&objbkpDuenio, sizeof(bkpDuenio), 1, p)==1){
        objbkpDuenio.getObjDuenio().MostrarDuenio();
    }
    fclose(p);
}
/*****************************************************************/
// bool bkpDuenio::RestaurarBackup(){
//     //primero quiero que el archivos mujer.dat quede vacio
//     FILE *p;
//     p = fopen("duenio.dat", "wb");
//     if(p==NULL){
//         cout<<"ERROR de bool bkpDuenio::RestaurarBackup()"<<endl;
//         system("pause");
//         return false;
//     }
//     //segundo quiero que todo lo que tenga el archivo de backup
//     //lo reemplaze por lo que tiene el archivo de mujeres.dat
//     int tam = objDuenio.contarRegistros("bkpDuenio.dat");

//     if(tam==-1){
//         cout<<"ERROR de bool bkpDuenio::RestaurarBackup()"<<endl;
//         system("pause");
//         return false;
//     }

//     for(int i=0; i<tam; i++){
//         objDuenio = objDuenio.leerRegistro(i);
//         fwrite(&objDuenio, sizeof(Duenio), 1, p);
//     }
//     fclose(p);
//     return true;

// }
// /*****************************************************************/
#include<iostream>

using namespace std;

#include"bkpDuenio.h"

/*****************************************************************/
bool bkpDuenio::CrearBackup(){
    FILE *original, *backup;
    Duenio objD;

    bkpDuenio objBkp;

    //abre el archivo original para lectura
    original = fopen("duenio.dat","rb");
    if(original==NULL){
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout<<"ERROR de bool bkpDuenio::CrearBackup()"<<endl;
        return false;
    }
    //abre el archivo de respaldo para escritura
    backup = fopen("bkpduenio.dat","wb");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpDuenio::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpduenio.dat","ab");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpDuenio::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objD.contarRegistros("duenio.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpDuenio::CrearBackup()"<<endl;
        fclose(original);
        fclose(backup);
        return false;
    }

    int band=0;

    for(int i=0; i<tam; i++){
        objD = objD.leerRegistro(i,"duenio.dat");

        if(band==i){
            fwrite(&objD,sizeof(Duenio),1,backup);
            band=i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpDuenio::MostrarBackup(){
    FILE *p;

    // Abre el archivo de respaldo para lectura
    p = fopen("bkpduenio.dat","rb");
    if(p==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de void bkpDuenio::MostrarBackup()"<<endl;
        return;
    }

    // Obtiene el número de registros en el archivo de respaldo
    int tam = objDuenio.contarRegistros("bkpduenio.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for(int i=0; i<tam; i++){
        objDuenio = objDuenio.leerRegistro(i,"bkpduenio.dat");
        objDuenio.MostrarDuenio();
    }
    fclose(p);
}
/*****************************************************************/
bool bkpDuenio::RestaurarBackup(){
    //primero quiero que el archivos ninio.dat quede vacio
    FILE *p;
    Duenio objD;
    p = fopen("duenio.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpDuenio::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat
    int tam = objDuenio.contarRegistros("bkpduenio.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpDuenio::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objD = objDuenio.leerRegistro(i,"bkpduenio.dat");
    
        fwrite(&objD, sizeof(Duenio), 1, p);
    }

    fclose(p);
    return true;
}
// /*****************************************************************/
#include<iostream>

using namespace std;

#include"bkpPlanta.h"

/*****************************************************************/
bool bkpPlanta::CrearBackup(){
    FILE *original, *backup;
    Planta objPlanta;

    bkpPlanta objBkp;

    //abre el archivo original para lectura
    original = fopen("planta.dat","rb");
    if(original==NULL){
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout<<"ERROR de bool bkpPlanta::CrearBackup()"<<endl;
        return false;
    }

    //abre el archivo de respaldo para escritura
    backup = fopen("bkpplanta.dat","wb");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpPlanta::CrearBackup()"<<endl;
        return false;    // Cierra el archivo original antes de salir
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpplanta.dat","ab");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpPlanta::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objPlanta.contarRegistros();

    if(tam==-1){
        cout<<"ERROR de bool bkpPlanta::CrearBackup()"<<endl;
        fclose(original);
        fclose(backup);
        return false;
    }

    int band=0;

    for(int i=0; i<tam; i++){
        objPlanta = objPlanta.leerRegistroPlanta(i,"planta.dat");

        if(band==i){
            fwrite(&objPlanta,sizeof (Planta),1,backup);
            band=i+1;
        }
    }

    // Cierra los archivos

    fclose(original);
    fclose(backup);

    return true;

}
/*****************************************************************/
void bkpPlanta::MostrarBackup(){

    // Obtiene el número de registros en el archivo de respaldo
    int tam = objPlanta.contarRegistros("bkpplanta.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for(int i=0; i<tam; i++){
        objPlanta = objPlanta.leerRegistroPlanta(i,"bkpplanta.dat");
        objPlanta.MostrarPlanta();
    }

}
/*****************************************************************/
bool bkpPlanta::RestaurarBackup(){
    //primero quiero que el archivos planta.dat quede vacio
    FILE *p;
    Planta objP;
    p = fopen("planta.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpPlanta::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat
    int tam = objPlanta.contarRegistros("bkpplanta.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpPlanta::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objP = objPlanta.leerRegistroPlanta(i,"bkpplanta.dat");

        fwrite(&objP, sizeof(Planta), 1, p);
    }

    fclose(p);
    return true;
}
/*****************************************************************/
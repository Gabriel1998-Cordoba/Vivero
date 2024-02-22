#include<iostream>

using namespace std;

#include"bkpAgroquimicos.h"

/*****************************************************************/
bool bkpAgroquimicos::CrearBackup(){
    FILE *original, *backup;
    Agroquimicos objAgro;

    bkpAgroquimicos objBkp;

    //abre el archivo original para lectura
    original = fopen("agroquimicos.dat","rb");
    if(original==NULL){
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout<<"ERROR de bool bkpAgroquimicos::CrearBackup()"<<endl;
        return false;
    }

    //abre el archivo de respaldo para escritura
    backup = fopen("bkpagroquimicos","wb");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpAgroquimicos::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);  // Cierra el archivo de respaldo antes de leer
    
    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpagroquimicos.dat","ab");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpAgroquimicos::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objAgro.contarRegistros("agroquimicos.dat");

    if(tam == -1){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpAgroquimicos::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        fclose(backup);
        return false;
    }

    int band=0;

    for(int i=0;i<tam;i++){
        objAgro = objAgro.leerRegistroAgroquimicos(i,"agroquimicos.dat");

        if(band==i){
            fwrite(&objAgro,sizeof (Agroquimicos),1,backup);
            band=i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpAgroquimicos::MostrarBackup(){
    
    int tam = objAgroquimicos.contarRegistros("bkpagroquimicos.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for(int i=0; i<tam; i++){
        objAgroquimicos = objAgroquimicos.leerRegistroAgroquimicos(i,"bkpagroquimicos.dat");
        objAgroquimicos.MostrarAgroquimicos();
    }
   

}
/*****************************************************************/
bool bkpAgroquimicos::RestaurarBackup(){

    //primero quiero que el archivos agroquimicos.dat quede vacio
    FILE *p;
    Agroquimicos objA;
    p = fopen("agroquimicos.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpAgroquimicos::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat
    int tam = objAgroquimicos.contarRegistros("bkpagroquimicos.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpAgroquimicos::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objA = objAgroquimicos.leerRegistroAgroquimicos(i,"bkpagroquimicos.dat");

        fwrite(&objA, sizeof(Agroquimicos), 1, p);
    }    

    fclose(p);
    return true;
}
/*****************************************************************/
#include<iostream>

using namespace std;

#include"bkpCliente.h"

/*****************************************************************/
bool bkpCliente::CrearBackup(){
    FILE *original, *backup;
    Cliente objClie;

    bkpCliente objBkp;

    //abre el archivo original para lectura
    original = fopen("Cliente.dat","rb");
    if(original==NULL){
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout << "ERROR de bool bkpCliente::CrearBackup()" << endl;
        return false;
    }

    //abre el archivo de respaldo para escritura
    backup = fopen("bkpCliente.dat","wb");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpCliente::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpCliente.dat","ab");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpCliente::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objClie.CONtarRegistros("Cliente.dat");

    if(tam==-1){
        cout << "ERROR: No se pudo leer el archivo original." << endl;
        cout << "ERROR de bool bkpCliente::CrearBackup()" << endl;
        fclose(original);
        fclose(backup);
        return false;
    }

    int band=0;

    for(int i=0; i<tam; i++){
        objClie = objClie.leerRegistros(i,"Cliente.dat");
        if(band==i){
            fwrite(&objClie, sizeof(Cliente), 1, backup);
            band = i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpCliente::MostrarBackup(){
    // Obtiene el número de registros en el archivo de respaldo
    int tam = objCliente.CONtarRegistros("bkpCliente.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for(int i=0; i<tam; i++){
        objCliente = objCliente.leerRegistros(i,"bkpCliente.dat");
        objCliente.Mostrar();
    }

}
/*****************************************************************/
bool bkpCliente::RestaurarBackup(){
    //primero quiero que el archivos Cliente.dat quede vacio
    FILE *p;
    Cliente objClie;
    p = fopen("Cliente.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpCliente::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat

    int tam = objCliente.CONtarRegistros("bkpCliente.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpCliente::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objClie = objCliente.leerRegistros(i,"bkpCliente.dat");

        fwrite(&objClie, sizeof(Cliente), 1, p);
    }

    fclose(p);
    return true;
}
/*****************************************************************/
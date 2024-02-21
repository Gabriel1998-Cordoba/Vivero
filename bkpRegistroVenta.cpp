#include<iostream>

using namespace std;

#include"bkpRegistroVenta.h"

/*****************************************************************/
bool bkpRegistroVenta::CrearBackup(){
    FILE *original, *backup;
    RegistroVenta objBkp;

    bkpRegistroVenta objBkpBkp;

    //abre el archivo original para lectura
    original = fopen("registroVenta.dat", "rb");
    if (original == NULL) {
        cout << "ERROR: No se pudo abrir el archivo original. 1" << endl;
        cout << "ERROR de bool bkpRegistroVenta::CrearBackup()" << endl;
        return false;
    }
    //abre el archivo de respaldo para escritura
    backup = fopen("bkregistroVenta.dat", "wb");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo. 2" << endl;
        cout << "ERROR de bool bkpRegistroVenta::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);
    
    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpregistroVenta.dat", "ab");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo. 3" << endl;
        cout << "ERROR de bool bkpRegistroVenta::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objBkp.contarRegistros("registroVenta.dat");

    if (tam == -1) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo. 4" << endl;
        cout << "ERROR de bool bkpRegistroVenta::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int band=0;

    for(int i=0;i<tam;i++){
        objBkp = objBkp.leerRegistro(i,"registroVenta.dat");

        if(band==i){
            fwrite(&objBkp, sizeof(RegistroVenta), 1, backup);
            band=i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpRegistroVenta::MostrarBackup(){

    //obtiene el número de registros en el archivo de respaldo
    int tam = objRegistroVenta.contarRegistros("bkpregistroVenta.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for (int i = 0; i < tam; i++) {
        objRegistroVenta = objRegistroVenta.leerRegistro(i, "bkpregistroVenta.dat");
        objRegistroVenta.Mostrar();
    }

}
/*****************************************************************/
bool bkpRegistroVenta::RestaurarBackup(){
    //primero quiero que el archivos ninio.dat quede vacio
    FILE *p;
    RegistroVenta objBkp;
    p = fopen("registroVenta.dat", "wb");
    if (p == NULL) {
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout << "ERROR de bool bkpRegistroVenta::RestaurarBackup()" << endl;
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat
    int tam = objRegistroVenta.contarRegistros("bkpregistroVenta.dat");

    if (tam == -1) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpRegistroVenta::RestaurarBackup()" << endl;
        return false;
    }

    for (int i = 0; i < tam; i++) {
        objBkp = objRegistroVenta.leerRegistro(i, "bkpregistroVenta.dat");
        fwrite(&objBkp, sizeof(RegistroVenta), 1, p);
    }

    fclose(p);
    return true;
}
/*****************************************************************/

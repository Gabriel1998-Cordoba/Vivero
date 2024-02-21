#include<iostream>

using namespace std;

#include"bkpRegistroCompra.h"

/*****************************************************************/
bool bkpRegistroCompra::CrearBackup(){
    FILE *original, *backup;
    RegistroCompra objBkp;

    bkpRegistroCompra objBkpBkp;

    //abre el archivo original para lectura
    original = fopen("registrocompra.dat", "rb");
    if (original == NULL) {
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout << "ERROR de bool bkpRegistroCompra::CrearBackup()" << endl;
        return false;
    }
    //abre el archivo de respaldo para escritura
    backup = fopen("bkpregistrocompra.dat", "wb");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpRegistroCompra::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpregistrocompra.dat", "ab");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpRegistroCompra::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objBkp.contarRegistros("registrocompra.dat");

    if (tam == -1) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpRegistroCompra::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int band=0;

    for(int i=0;i<tam;i++){
        objBkp = objBkp.leerRegistro(i,"registrocompra.dat");

        if(band==i){
            fwrite(&objBkp, sizeof(RegistroCompra), 1, backup);
            band=i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpRegistroCompra::MostrarBackup(){

    //obtiene el número de registros en el archivo de respaldo
    int tam = objRegistroCompra.contarRegistros("bkpregistrocompra.dat");
    //lee y muestra cada registro en el archivo de respaldo

    for (int i = 0; i < tam; i++) {
        objRegistroCompra = objRegistroCompra.leerRegistro(i, "bkpregistrocompra.dat");
        objRegistroCompra.Mostrar();
    }

}
/*****************************************************************/
bool bkpRegistroCompra::RestaurarBackup(){
    //primero quiero que el archivos ninio.dat quede vacio
    FILE *p;
    RegistroCompra objBkp;
    p = fopen("registrocompra.dat", "wb");
    if (p == NULL) {
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout << "ERROR de bool bkpRegistroCompra::RestaurarBackup()" << endl;
        return false;
    }

    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpninio.dat
    int tam = objRegistroCompra.contarRegistros("bkpregistrocompra.dat");

    if (tam == -1) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpRegistroCompra::RestaurarBackup()" << endl;
        return false;
    }

    for (int i = 0; i < tam; i++) {
        objBkp = objRegistroCompra.leerRegistro(i, "bkpregistrocompra.dat");

        fwrite(&objBkp, sizeof(RegistroCompra), 1, p);
    }

    fclose(p);
    return true;
}
/*****************************************************************/
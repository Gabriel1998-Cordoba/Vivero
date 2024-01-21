#include<iostream>

using namespace std;

#include"bkpDetalleFacturaCompra.h"

bool bkpDetalleFacturaCompra::CrearBackup(){
    FILE *original, *backup;
    DetalleFacturaCompra objBkp;

    bkpDetalleFacturaCompra objBkpBkp;

    //abre el archivo original para lectura
    original = fopen("DetalleFacturaCompra.dat", "rb");
    if (original == NULL) {
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout << "ERROR de bool bkpDetalleFacturaCompra::CrearBackup()" << endl;
        return false;
    }
    //abre el archivo de respaldo para escritura
    backup = fopen("bkpDetalleFacturaCompra.dat", "wb");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpCompraFacturaCompra::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpDetalleFacturaCompra.dat", "ab");
    if (backup == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de bool bkpCompraFacturaCompra::CrearBackup()" << endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objBkp.contarRegistros("DetalleFacturaCompra.dat");

    if(tam == -1){
        cout<<"ERROR de bool bkpCompraFacturaCompra::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        fclose(backup);
        return false;
    }

    int band=0;

    for(int i=0;i<tam;i++){
        objBkp = objBkp.leerRegistro(i,"DetalleFacturaCompra.dat");
        if(band == i){
            fwrite(&objBkp, sizeof(DetalleFacturaCompra), 1, backup);
            band=i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
}
/*****************************************************************/
void bkpDetalleFacturaCompra::MostrarBackup(){
    FILE *p;

    //abre el archivo de respaldo para lectura
    p = fopen("bkpDetalleFacturaCompra.dat", "rb");
    if (p == NULL) {
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout << "ERROR de void bkpCompraFacturaCompra::MostrarBackup()" << endl;
        return;
    }

    //obtiene el número de registros en el archivo de respaldo
    int tam = objDetalleFacturaCompra.contarRegistros("bkpDetalleFacturaCompra.dat");
    //lee y muestra cada registro en el archivo de respaldo
    
    for(int i=0; i<tam; i++){
        objDetalleFacturaCompra = objDetalleFacturaCompra.leerRegistro(i,"bkpDetalleFacturaCompra.dat");
        objDetalleFacturaCompra.Mostrar();
    }

    fclose(p);
}
/*****************************************************************/
bool bkpDetalleFacturaCompra::RestaurarBackup(){
    //primero quiero que el archivos bkpDetalleFacturaCompra.dat quede vacio
    FILE *p;
    DetalleFacturaCompra objD;
    p = fopen("DetalleFacturaCompra.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpDetalleFacturaCompra::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }
    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpDetalleFacturaCompra.dat
    int tam = objDetalleFacturaCompra.contarRegistros("bkpDetalleFacturaCompra.dat");

    if(tam == -1){
        cout<<"ERROR de bool bkpCompraFacturaCompra::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }

    for(int i=0; i<tam; i++){
        objD = objDetalleFacturaCompra.leerRegistro(i,"bkpCompraFacturaCompra.dat");
        fwrite(&objD, sizeof(DetalleFacturaCompra), 1, p);
    }
    fclose(p);
    return true;
}
/*****************************************************************/
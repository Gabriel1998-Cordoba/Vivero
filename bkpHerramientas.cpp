#include <iostream>

using namespace std;

#include"bkpHerramientas.h"

/*****************************************************************/

bool bkpHerramientas::CrearBackup(){
    FILE *original,*backup;
    Herramientas objH;

    bkpHerramientas objBkp;

    //abre el archivo original para lectura
    original = fopen("herramientas.dat","rb");
    if(original==NULL){
        cout << "ERROR: No se pudo abrir el archivo original." << endl;
        cout<<"ERROR de bool bkpHerramientas::CrearBackup()"<<endl;
        return false;
    }

    //abre el archivo de respaldo para escritura
    backup = fopen("bkpherramientas.dat","wb");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpHerramientas::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }
    fclose(backup);

    //abre el archivo de respaldo para lectura y escritura
    backup = fopen("bkpherramientas.dat","ab");
    if(backup==NULL){
        cout << "ERROR: No se pudo abrir el archivo de respaldo." << endl;
        cout<<"ERROR de bool bkpHerramientas::CrearBackup()"<<endl;
        fclose(original);  // Cierra el archivo original antes de salir
        return false;
    }

    int tam = objH.contarRegistros("herramientas.dat");

    if (tam == -1){
        cout<<"ERROR de bool bkpHerramientas::CrearBackup()"<<endl;
        system("pause");
        fclose(backup);
        fclose(original);
        return false;
    }

    int band = 0;


    for(int i=0; i<tam; i++){
        objH = objH.leerRegistroHerramienta(i,"herramientas.dat");

        if(band==i){
            fwrite(&objH, sizeof(Herramientas), 1, backup);
            //objH.MostrarHerramienta();
            band = i+1;
        }
    }

    //cierra ambos archivo

    fclose(original);
    fclose(backup);

    return true;
    
}
/*****************************************************************/
void bkpHerramientas::MostrarBackup(){
    FILE *p;
    //abre el archivo de respaldo para lectura y escritura
    p = fopen("bkpherramientas.dat","rb");
    if(p==NULL){
        cout<<"ERROR de void bkpHerramientas::MostrarBackup()"<<endl;
        system("pause");
        return;
    }

    //lee y muestra cada registro en el archivo de respaldo
    int tam = objHerramientas.contarRegistros("bkpherramientas.dat");
    //lee y muestra cada registro en el archivo de respaldo
    for(int i=0; i<tam; i++){
        objHerramientas = objHerramientas.leerRegistroHerramienta(i,"bkpherramientas.dat");
        objHerramientas.MostrarHerramienta();
    }
    fclose(p);
    
}
/*****************************************************************/
bool bkpHerramientas::RestaurarBackup(){
    //primero quiero que el archivos herramientas.dat quede vacio
    FILE *p;
    Herramientas objH;
    p = fopen("herramientas.dat", "wb");
    if(p==NULL){
        cout<<"ERROR de bool bkpHerramientas::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }
    
    //segundo quiero que todo lo que tenga el archivo de backup
    //lo reemplaze por lo que tiene el archivo de bkpherramientas.dat
    int tam = objHerramientas.contarRegistros("bkpherramientas.dat");
    
    if (tam == -1){
        cout<<"ERROR de bool bkpHerramientas::RestaurarBackup()"<<endl;
        system("pause");
        return false;
    }
    
    for(int i=0; i<tam; i++){
        objH = objHerramientas.leerRegistroHerramienta(i,"bkpherramientas.dat");
        
        fwrite(&objH, sizeof(Herramientas), 1, p);
    }
    
    fclose(p);
    return true;
}
/*****************************************************************/
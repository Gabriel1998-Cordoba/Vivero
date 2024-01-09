#include<iostream>

using namespace std;

#include<Backup.h>



Backup::Backup(/* args */)
{
}

Backup::~Backup()
{
}

void Backup::BackupGeneral()
{

    BackupDatosDuenio();

}

void Backup::RestauracionGeneralconBackup(){

}
/////////////////////////////////////////////
void Backup::RestaurarBackupDatosDuenio(){
// Duenio objD;

// int tam = objD.contarRegistros();


// FILE *p;
// //Backup objB;

// p=fopen("BackupDatosDuenio.bkp","rb");
// if(p==NULL){
//     cout<<"ERROR de ARCHIVO"<<endl;
//     system("pause");
// }


// for(int i=0; i<tam; i++){
//     objAux = objAux.leerRegistro(i);
//     for(int j=0;j<)
// }
Backup objBkp;
Duenio objD;

int tam=objBkp.contarRegistrosBkpDuenio();

for(int i=0;i<tam;i++)
{
objD = objBkp.leerRegistroBkpDuenio(i);

objD.reemplazarRegistroDuenio(objD,i);
}


}
/////////////////////////////////////////////
void Backup::BackupDatosDuenio()
{
Duenio objD;

int tam = objD.contarRegistros();


FILE *p;
//Backup objB;

p=fopen("BackupDatosDuenio.bkp","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


for(int i=0; i<tam; i++){
    objD = objD.leerRegistro(i);
    fwrite(&objD,sizeof (Duenio),1,p);
}




}

int Backup::contarRegistrosBkpDuenio(){
    
  Duenio objD;
    FILE *p2;

    p2=fopen("BackupDatosDuenio", "rb");

        
        if(p2==NULL) return 0;
        fseek(p2, 0,2);
        int tam=ftell(p2);
        fclose(p2);
        return tam/sizeof(Duenio);
    }

Duenio Backup::leerRegistroBkpDuenio(int pos){
       Duenio reg;
        FILE *p;
        p=fopen("BackupDatosDuenio", "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
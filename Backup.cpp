#include <iostream>

using namespace std;

#include "Backup.h"

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

void Backup::RestauracionGeneralconBackup()
{
}
/////////////////////////////////////////////
void Backup::RestaurarBackupDatosDuenio()
{
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

    int tam = objBkp.contarRegistrosBkpDuenio();

    for (int i = 0; i < tam; i++)
    {
        objD = objBkp.leerRegistroBkpDuenio(i);

        objD.reemplazarRegistroDuenio(objD, i);
    }
}
/////////////////////////////////////////////
void Backup::
    BackupDatosDuenio()
{
    Duenio objD, *aux, objBKP;

    int tam = objD.contarRegistros("duenio.dat");
    aux = new Duenio[tam];
    if (aux == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    cout << "tamanio" << tam << endl;
    system("pause");
    objD.leer(aux, tam, "duenio.dat");
    objBKP.vaciar("BackupDatosDuenio.bkp");

    if (objBKP.guardar(aux, tam,"BackupDatosDuenio.bkp"))
    {

        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete[] aux;

    //     FILE *p;
    //     Backup objB;

    //     p = fopen("BackupDatosDuenio.bkp", "ab");
    //     if (p == NULL)
    //     {
    //         cout << "ERROR de ARCHIVO" << endl;
    //         system("pause");
    //     }

    //     for (int i = 0; i < tam; i++)
    //     {
    //        aux = objD.leerRegistro(i);
    //         fwrite(&aux, sizeof(Duenio), 1, p);
    //     }
}

int Backup::contarRegistrosBkpDuenio()
{

    FILE *p2;

    p2 = fopen("BackupDatosDuenio.bkp", "rb");

    if (p2 == NULL)
    {
        return 0;
    }
    fseek(p2, 0, 2);
    int tam = ftell(p2);
    fclose(p2);
    return tam / sizeof(Duenio);
}

Duenio Backup::leerRegistroBkpDuenio(int pos)
{
    Duenio reg;
    FILE *p;
    p = fopen("BackupDatosDuenio.bkp", "rb");
    if (p == NULL)
    {
        return reg;
    }
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

// Backup Backup::leerRegistroBkp(int pos){
//        Backup reg;
//         FILE *p;
//         p=fopen("BackupDatosDuenio.bkp", "rb");
//         if(p==NULL) return reg;
//         fseek(p, sizeof reg*pos,0);
//         fread(&reg, sizeof reg,1, p);
//         fclose(p);
//         return reg;
//     }

void Backup::MostrarBackupDatosDuenio()
{

    Backup objB;
    Duenio objD;

    int cont = objB.contarRegistrosBkpDuenio();
    cout << "Contador Registro: " << cont << endl;
    for (int i = 0; i < cont; i++)
    {
        objD = objB.leerRegistroBkpDuenio(i);

        objD.MostrarDuenio();
    }

    system("pause");
}

void Backup::ReemplazarDatosDuenioConBackup()
{

    Duenio objD, *aux, objBKP;

    int tam = objBKP.contarRegistros("BackupDatosDuenio.bkp");
    aux = new Duenio[tam];
    if (aux == nullptr)
    {
        cout << "Falla al realizar backup" << endl;
        return;
    }

    cout << "tamanio" << tam << endl;
    system("pause");
    objBKP.leer(aux, tam, "BackupDatosDuenio.bkp");
    objD.vaciar("duenio.dat");

    if (objD.guardar(aux, tam,"duenio.dat"))
    {

        cout << "Backup realizado correctamente" << endl;
    }
    else
    {
        cout << "Falla al realizar backup" << endl;
    }

    delete[] aux;

    // FILE *p = fopen("duenio.dat", "wb");
    // if (p == NULL)
    // {
    //     cout << "ERRRO = void Backup::ReemplazarDatosDuenioConBackup()" << endl;
    // }

    // Backup objB;
    // Duenio objD;

    // int cont = objB.contarRegistrosBkpDuenio();

    // for (int i = 0; i < cont; i++)
    // {
    //     objD = objB.leerRegistroBkpDuenio(i);
    //     objD.reemplazarRegistroDuenio(objD, i);
    // }

    // fclose(p);
}
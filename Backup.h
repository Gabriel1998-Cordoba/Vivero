#pragma once
#include"Duenio.h"
#include"Cliente.h"
#include"RegistroCompra.h"
class Backup
{
private:
    Duenio _duenioBkp;
    Cliente _clienteBkp;
    RegistroCompra _registroCompraBkp;




    
public:
    Backup(/* args */);
    ~Backup();
    void BackupGeneral();
    
    void BackupDatosDuenio();
    void RestauracionGeneralconBackup();
    void RestaurarBackupDatosDuenio();
    void MostrarBackupDatosDuenio();
    void ReemplazarDatosDuenioConBackup();

Duenio leerRegistroBkpDuenio(int);
Backup leerRegistroBkp(int);
    int contarRegistrosBkpDuenio();
};



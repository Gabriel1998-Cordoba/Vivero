#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "menu.h"
#include"FuncionesGlobales.h"
#include"Planta.h"
#include"Herramientas.h"
#include"Agroquimicos.h"

///////////////////////////////////////////////////////////////////////////
void menuPrincipal()
{

    int opcion;

    while (true)
    {

        system("cls");
        cout << "opcion 1 ----> Movimientos Empresa" << endl;
        cout << "opcion 2 ----> Movimientos Persona" << endl;
        cout << "opcion 3 ----> Movimientos Duenio" << endl;
        cout << "opcion 0 ----> Fin del Programa" << endl;
        cin >> opcion;
        system("cls");

        switch (opcion)
        {

            /*******************************************************************/
        case 1:
        {
            //menuEmpresa(opcion);
            system("cls");
        }
        break;
            /*******************************************************************/
        case 2:
        {
            //menuPersona(opcion);
            system("cls");
        }
        break;
            /*******************************************************************/
        case 3:
        {
            menuDuenio(opcion);
            system("cls");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            system("cls");
            cout << "fin del programa" << endl;
            system("pause");
            return;
        }
        break;
            /*******************************************************************/
        default:
        {
            system("cls");
            cout << "valor ingresado no existe dentro del menu" << endl;
            system("pause");
        }
        break;
            /*******************************************************************/
        }
    }
}

// DUEÑO
///////////////////////////////////////////////////////////////////////////
void menuDuenio(int opcion)
{

    char usuario[30];
    int contra;
    int band = 0;
    int i = 1;

    for (int i = 1; i <= 4; i++)
    {

        if (i <= 3)
        {
            cout << "ingrese usuario: " << endl; // el usuario es Vivero
            cargarCadena(usuario, 30);
            cout << "Ingrese Contracenia: " << endl; // la contraceña es 123
            cin >> contra;

            if ((contra == 123) && (strcmp(usuario, "Vivero") == 0))
            {
                band = 1;
                cout << "CORRECTO" << endl;
                system("pause");
                i = 5;
            }
            else
            {
                cout << "el usuario o contracenia son incorrectos" << endl;
            }
        }

        if ((i == 4) && (band == 0))
        {
            system("cls");
            cout << "no ingresaste correctamente el usuario y contracenia" << endl;
            system("pause");
            return;
        }
    }

    if (band == 1)
    {

        while (true)
        {
            system("cls");
            cout << "BIENVENIDO DUENIO" << endl;
            cout << "Opcion 1 ----> Cargar Datos" << endl;                       //'ab' de archivos
            cout << "Opcion 2 ----> Modificar Datos" << endl;                    //'rb' que lo lea y modifique
            cout << "Opcion 3 ----> Borrar o Limpiar Datos" << endl;             //'wb' de archivos == 'baja Fisica'
            cout << "Opcion 4 ----> dar de baja algun Productos" << endl;        // bool para dar de 'basa logica'
            cout << "Opcion 5 ----> Listar Datos" << endl;                       // seleccionar el archivo que quieres que abra y muestre
            cout << "Opcion 6 ----> Contar Registros de algun Producto" << endl; // Cuenta todos los registros dentro del bloc de notas
            cout << "Opcion 7 ----> Comprar"<<endl; //esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 8 ----> Vender"<<endl; //esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 9 ----> Cargar Datos Del Dueño"<<endl;
            cout << "Opcion 10 ----> Cambiar Sueldo Cargado"<<endl;
            cout << "Opcion 0 ----> salir" << endl;                              //--> Salir a Menu Principal
            cin >> opcion;
            system("cls");

            switch (opcion)
            {
                /*******************************************************************/
            case 1:
            {
                system("cls");
                CargarDatos(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 2:
            {
                system("cls");
                //ModificarDatos(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 3:
            {
                system("cls");
                LimpiarDatos(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 4:
            {
                system("cls");

                system("pause");
            }
            break;
                /*******************************************************************/
            case 5:
            {
                system("cls");
                ListarDatos(opcion);
            }
            break;
                /*******************************************************************/
            case 6:
            {

                system("cls");
                //ContarRegistros(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 0:
            {
                system("cls");
                cout << "Saliste" << endl;
                system("pause");
                return;
            }
            break;
                /*******************************************************************/
            default:
            {
                system("cls");
                cout << "valor ingresado no existe dentro del menu" << endl;
                system("pause");
            }
            break;
                /*******************************************************************/
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////
void CargarDatos(int opcion)
{

    Planta obtP;
    Herramientas objH;
    Agroquimicos objA;

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Cargar?" << endl<< endl;
             
        cout << "Opcion 1 ---> Plantas" << endl;       // Crear funcion que carge plantas a un Archivos
        cout << "Opcion 2 ---> Herramientas" << endl;  // Crear funcion que carge Herramientas a un Archivos
        cout << "Opcion 3 ---> Agro Quimicos" << endl; // Crear funcion que carge Agro Quimicos a un Archivos
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {

            system("cls");
            int tam=0,cantidad;

            tam=obtP.contarRegistros();
            cout<<"ingrese Cantidad de Registros"<<endl;
            cin>>cantidad;
            system("cls");
            for(int i=0; i<cantidad;i++){
            obtP.CargarArchivoPlanta(tam,opcion);
            tam=obtP.contarRegistros();
            }
            system("pause");
            // ARMAR UNA FUNCION QUE PERMITA CARGAR EN ARCHIVO Planta
            //  Planta ob1;
            //  ob1.Cargar();
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            int tam=0,cantidad;

            tam=objH.contarRegistros();
            cout<<"ingrese Cantidad de Registros"<<endl;
            cin>>cantidad;
            system("cls");
            for(int i=0; i<cantidad;i++){
            objH.CargarArchivoHerramienta(tam,opcion);
            tam=objH.contarRegistros();
            }
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            int tam=0,cantidad;

            tam=objA.contarRegistros();
            cout<<"ingrese Cantidad de Registros"<<endl;
            cin>>cantidad;
            system("cls");
            for(int i=0; i<cantidad;i++){
            objA.CargarArchivoAgroquimicos(tam,opcion);
            tam=objA.contarRegistros();
            }
            system("pause");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            system("cls");
            cout << "valor ingresado no existe dentro del menu" << endl;
            system("pause");
        }
        break;
            /*******************************************************************/
        }
    }
}
///////////////////////////////////////////////////////////////////////////
void LimpiarDatos(int opcion)
{
    Planta obtP;
    Herramientas obtH;
    Agroquimicos obtA;

    system("cls");
    cout << "Que quieres Limpiar?" << endl
         << endl;
    cout << "Opcion 1 ---> Plantas" << endl;       // Crear funcion que carge plantas a un Archivos
    cout << "Opcion 2 ---> Herramientas" << endl;  // Crear funcion que carge Herramientas a un Archivos
    cout << "Opcion 3 ---> Agro Quimicos" << endl; // Crear funcion que carge Agro Quimicos a un Archivos
    cout << "Opcion 0 ----> salir" << endl;
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    /*******************************************************************/
    case 1:
    {
        system("cls");
        
        if(obtP.borrarRegistroPlanta()==true){
            cout<<"se borro Correctamente"<<endl;
        }else{
            cout<<"NO se pudo borrar"<<endl; 
        }

        system("pause");
        // ARMAR UNA FUNCION QUE PERMITA CARGAR EN ARCHIVO Planta
        //  Planta ob1;
        //  ob1.Cargar();
    }
    break;
    /*******************************************************************/
    case 2:
    {
        system("cls");
        if(obtH.borrarRegistroHerramienta()==true){
            cout<<"se borro Correctamente"<<endl;
        }else{
            cout<<"NO se pudo borrar"<<endl; 
        }
        system("pause");
    }
    break;
    /*******************************************************************/
    case 3:
    {
        system("cls");
        if(obtA.borrarRegistroAgroquimicos()==true){
            cout<<"se borro Correctamente"<<endl;
        }else{
            cout<<"NO se pudo borrar"<<endl; 
        }
        system("pause");
    }
    break;
        /*******************************************************************/
    case 0:
    {
        system("cls");
        cout << "Saliste" << endl;
        system("pause");
        return;
    }
    break;
    /*******************************************************************/
    default:
    {
        system("cls");
        cout << "valor ingresado no existe dentro del menu" << endl;
        system("pause");
    }
    break;
        /*******************************************************************/
    }
}
///////////////////////////////////////////////////////////////////////////
void ListarDatos(int opcion)
{
    Planta obtP;
    Herramientas obtH;
    Agroquimicos obtA;


    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Listar?" << endl
             << endl;
        cout << "Opcion 1 ---> Plantas" << endl;       // Crear funcion que carge plantas a un Archivos
        cout << "Opcion 2 ---> Herramientas" << endl;  // Crear funcion que carge Herramientas a un Archivos
        cout << "Opcion 3 ---> Agro Quimicos" << endl; // Crear funcion que carge Agro Quimicos a un Archivos
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            cout << "Listado de Plantas" << endl << endl;
            obtP.ListarPlanta();
            system("pause");
            // ARMAR UNA FUNCION QUE PERMITA CARGAR EN ARCHIVO Planta
            //  Planta ob1;
            //  ob1.Cargar();
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            cout << "Listado de Herrramientas" << endl << endl;
            obtH.ListarHerramienta();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            cout << "Listado de AgroQuimicos" << endl << endl;
            obtA.ListarAgroquimicos();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            system("cls");
            cout << "valor ingresado no existe dentro del menu" << endl;
            system("pause");
        }
        break;
            /*******************************************************************/
        }
    }
}
///////////////////////////////////////////////////////////////////////////

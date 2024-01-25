
#include "menu.h"

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
            // menuEmpresa(opcion);
            system("cls");
        }
        break;
            /*******************************************************************/
        case 2:
        {
            menuPersona(opcion);
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
            cout << "Opcion 1 ----> Cargar Datos" << endl;                   //'ab' de archivos
            cout << "Opcion 2 ----> Modificar Datos" << endl;                //'rb' que lo lea y modifique
            cout << "Opcion 3 ----> Borrar o Limpiar Datos" << endl;         //'wb' de archivos == 'baja Fisica'
            cout << "Opcion 4 ----> dar de baja algun Productos" << endl;    // bool para dar de 'basa logica'
            cout << "Opcion 5 ----> Listar Datos" << endl;                   // seleccionar el archivo que quieres que abra y muestre
            cout << "Opcion 6 ----> Contar Registros de X Producto" << endl; // Cuenta todos los registros dentro del bloc de notas
            cout << "Opcion 7 ----> Recaudacion Por Anio Ingresado" << endl; // esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 8 ----> Consulta x de factura" << endl;          // esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 9 ----> Cargar Datos Del Duenio" << endl;
            cout << "Opcion 10 ----> CONFIGURACION de backup" << endl; // Crear una solapa de configuracion,que contenga las copias de seguridad
            // cout << "Opcion 11 ----> Restaurar Backup Duenio" << endl;
            // cout << "Opcion 12 ----> Mostrar Contenido del Backup Duenio" << endl;
            // cout << "Opcion 13 ----> borrar datos del duenio y poner los que contiene Backup" << endl;

            cout << "Opcion 0 ----> salir" << endl; //--> Salir a Menu Principal
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
                // ModificarDatos(opcion);
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
                // ContarRegistros(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 7:
            {

                system("cls");
                system("pause");
            }
            break;
                /*******************************************************************/
            case 8:
            {

                system("cls");
                system("pause");
            }
            break;
                /*******************************************************************/
            case 9:
            {

                system("cls");
                CargarDatosDelDuenio(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 10:
            {
                system("cls");
                configuracionBackup();
                system("pause");
            }
            break;
                /*******************************************************************/
            case 11:
            {
                system("cls");
                // Backup objBkp;
                // objBkp.ReemplazarDatosDuenioConBackup();

                system("pause");
            }
            break;
                /*******************************************************************/
            case 12:
            {
                system("cls");
                // Backup objBkp;
                // objBkp.MostrarBackupDatosDuenio();

                system("pause");
            }
            break;
                /*******************************************************************/
            case 13:
            {
                //                  system("cls");
                // Backup objBkp;
                // objBkp.ReemplazarDatosDuenioConBackup();

                //                 system("pause");
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
        cout << "Que quieres Cargar?" << endl
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
            int tam = 0, cantidad;

            tam = obtP.contarRegistros();
            cout << "ingrese Cantidad de Registros" << endl;
            cin >> cantidad;
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                obtP.CargarArchivoPlanta(tam, opcion);
                tam = obtP.contarRegistros();
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
            int tam = 0, cantidad;

            tam = objH.contarRegistros();
            cout << "ingrese Cantidad de Registros" << endl;
            cin >> cantidad;
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objH.CargarArchivoHerramienta(tam, opcion);
                tam = objH.contarRegistros();
            }
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            int tam = 0, cantidad;

            tam = objA.contarRegistros();
            cout << "ingrese Cantidad de Registros" << endl;
            cin >> cantidad;
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objA.CargarArchivoAgroquimicos(tam, opcion);
                tam = objA.contarRegistros();
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

        if (obtP.borrarRegistroPlanta() == true)
        {
            cout << "se borro Correctamente" << endl;
        }
        else
        {
            cout << "NO se pudo borrar" << endl;
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
        if (obtH.borrarRegistroHerramienta() == true)
        {
            cout << "se borro Correctamente" << endl;
        }
        else
        {
            cout << "NO se pudo borrar" << endl;
        }
        system("pause");
    }
    break;
    /*******************************************************************/
    case 3:
    {
        system("cls");
        if (obtA.borrarRegistroAgroquimicos() == true)
        {
            cout << "se borro Correctamente" << endl;
        }
        else
        {
            cout << "NO se pudo borrar" << endl;
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
            cout << "Listado de Plantas" << endl
                 << endl;
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
            cout << "Listado de Herrramientas" << endl
                 << endl;
            obtH.ListarHerramienta();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            cout << "Listado de AgroQuimicos" << endl
                 << endl;
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
void CargarDatosDelDuenio(int opcion)
{

    Duenio objD;

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Listar?" << endl
             << endl;
        cout << "Opcion 1 ----> Cargar Datos Del Duenio" << endl;
        cout << "Opcion 2 ----> Mostrar Datos Del Duenio" << endl;
        cout << "Opcion 3 ----> Cambiar Sueldo Cargado" << endl;
        cout << "Opcion 4 ----> Mostrar Sueldo Cargado" << endl;
        cout << "Opcion 5 ----> Borrar Datos Del Duenio" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");

            int tam = 0, cantidad;
            tam = objD.contarRegistros("duenio.dat");
            cout << "ingrese Cantidad de Registros" << endl;
            cin >> cantidad;
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objD.CargarDatosDeDuenioEnArchivo(tam /*, opcion*/);
                tam = objD.contarRegistros("duenio.dat");
            }
            system("pause");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            objD.MostrarDatosDeDuenioEnArchivo();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            objD.CambiarSueldoCargadoEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 4:
        {
            system("cls");
            objD.MostrarSueldoCargadoEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            system("cls");
            objD.BorrarDatosDelDuenio();
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
void menuPersona(int opcion)
{

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Opcion 1 ----> Comprar" << endl;
        cout << "Opcion 2 ----> Vender" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {

            // hacer una funcion que me cuente cuantos registros hay
            RegistroCompra objR;
            int tam = objR.contarRegistros();
            
            
            
    if(tam==-1){
         int idCompra = tam + 2 ;
            objR.setIdCompra(idCompra);
    }
           

            system("cls");
            menuCompraPersona(opcion, objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            menuVentaPersona(opcion);
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
void menuCompraPersona(int opcion, RegistroCompra objR)
{

    system("cls");

    cout << "Se debe de cargar su Registros de Compra" << endl
         << endl
         << endl;

    // objR.setIdCompra(idCompra);
    // objR.CargarArchivoCompra();

    while (true)
    {
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "Opcion 1 ----> Herramientas" << endl;
        cout << "Opcion 2 ----> Plantas" << endl;
        cout << "Opcion 3 ----> Agroquimicos" << endl;

        cout << "¿Opcion 0 ----> Ya termino de Comprar?" << endl;

        cin >> opcion;

        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            menuCompraHerramientaPersona(opcion, objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            menuCompraPlantaPersona(opcion, objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            menuCompraAgroquimicosPersona(opcion, objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        // case 4:
        // {
        //     system("cls");
        //     system("pause");
        // }
        // break;
        //     /*******************************************************************/
        // case 5:
        // {
        //     system("cls");
        //     system("pause");
        // }
        // break;
        /*******************************************************************/
        case 0:
        {

            // carga del cliente objcliente

            // registro de la compra(getIdcliente,idCompra);

            do
            {
                cout << "¿Seguro? ---> SI == 0" << endl;
                cout << "NO == 1" << endl;
                cin >> opcion;
            } while ((opcion != 0) && (opcion != 1));

            if (opcion == 0)
            {
                cout << "ya que esta seguro, ahora debe de cargar su Registros de Cliente" << endl;
                Cliente cli;
               // cli.Cargar();
               int id;
               cout<<"Ingrese ID"<<endl;
               cin>>id;

             

                if (!ValidarCliente(id))
                {
                    cout<<"Se registra el nuevo cliente"<<endl;

                    cli.Cargar();

                    if (cli.GuardarArchivo() == true)
                    {
                        cout << "se registro correctamente el cliente" << endl;
                        system("pause");
                    }else{

                        cout << "entro por aca" << endl;
                        system("pause");
                    }
                }
                objR.CargarCompra(objR, cli.getIDCliente());
                
                if (objR.GuardarCompra())
                {
                    cout << "se registro correctamente la compra " << endl;
                    // falta una funcion que dentro va a tener otra, esa funcion se llama
                    //  la primera se va a llamar genera factura, lo que va a hacer esta funcion, lo que
                    //  le vamos a pasar es la idCompra

                    GenerarFactura(objR,cli.getIDCliente());
                    system("pause");
                }
            }
            system("cls");
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
void menuVentaPersona(int opcion)
{
    while (true)
    {
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;

        cout << "Opcion 1 ----> Herramientas" << endl;
        cout << "Opcion 2 ----> Plantas" << endl;
        cout << "Opcion 3 ----> Agroquimicos" << endl;

        cout << "¿Opcion 0 ----> Ya termino de Comprar?" << endl;

        cin >> opcion;

        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            menuVentaHerramientaPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            menuVentaPlantaPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            menuVentaAgroquimicosPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {

            //     do
            //         {
            //             cout << "¿Seguro? ---> SI == 0" << endl;
            //             cout << "NO == 1" << endl;
            //             cin >> opcion;
            //         } while ((opcion != 0) && (opcion != 1));

            //         if (opcion == 0)
            //         {
            //             cout << "ya que esta seguro, ahora debe de cargar su Registros de Cliente" << endl;
            //             Cliente cli;
            //             cli.Cargar();
            //             if (!Existe(cli))
            //             {
            //                 if (cli.GuardarArchivo())
            //                 {
            //                     cout << "se registro correctamente el cliente" << endl;
            //                 }
            //                 RegistroCompra objR;
            //                 objR.CargarCompra(idCompra, cli.getIDCliente());
            //                 if (objR.GuardarCompra())
            //                 {
            //                     cout << "se registro correctamente la compra " << endl;
            //                 }
            //             }
            //             else
            //             {

            //                 cout << "El cliente ya existe " << endl;
            //                 RegistroCompra objR;
            //                 objR.CargarCompra(idCompra, cli.getIDCliente());
            //                 if (objR.GuardarCompra())
            //                 {
            //                     cout << "se registro correctamente la compra " << endl;
            //                 }
            //             }
            //         }
            //         system("cls");
            //         return;
        }
        break;
            //     /*******************************************************************/
        default:
        {
            //         system("cls");
            //         cout << "valor ingresado no existe dentro del menu" << endl;
            //         system("pause");
        }
        break;
            /*******************************************************************/
        }
    }
}
///////////////////////////////////////////////////////////////////////////

void menuCompraPlantaPersona(int opcion, RegistroCompra objR)
{

    Planta objP;

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS PLANTAS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Planta quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE PLANTA QUE QUIERE COMPRAR" << endl;
        cout << "Opcion 4 ----> LISTAR TODAS LOS DETALLES DE FACTURA DE SOLO PLANTAS" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            objP.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            objP.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            objP.Opcion3Compra(objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 4:
        {
            system("cls");
            objP.Opcion4Compra(objR);
            system("pause");
        }
        break;
            /*******************************************************************/
        // case 5:
        // {
        //     system("cls");
        //     system("pause");
        // }
        // break;
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
void menuCompraHerramientaPersona(int opcion, RegistroCompra objR)
{

    Herramientas objH;

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS HERRAMIENTAS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Herramientas quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE HERRAMIENTA QUE QUIERE COMPRAR" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            objH.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            objH.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            objH.Opcion3Compra(objR);
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
void menuCompraAgroquimicosPersona(int opcion, RegistroCompra objR)
{

    Agroquimicos objA;

    // hacer una funcion que me cuente cuantos registros hay
    int tam = objR.contarRegistros();
    int idCompra = tam + 1;
    objR.setIdCompra(idCompra);

    system("cls");

    while (true)
    {
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS AGROQUIMICOS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Agroquimico quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE AGROQUIMICO QUE QUIERE COMPRAR" << endl;
        cout << "Opcion 4 ----> LISTAR TODAS LOS DETALLES DE FACTURA DE SOLO PLANTAS" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            objA.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            objA.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
            objA.Opcion3Compra(idCompra);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 4:
        {
            system("cls");
            objA.Opcion4Compra(idCompra);
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            system("cls");
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
void menuVentaPlantaPersona(int opcion)
{
    while (true)
    {
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
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

/*******************************************************************/
void menuVentaHerramientaPersona(int opcion)
{
    while (true)
    {
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
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
/*******************************************************************/
void menuVentaAgroquimicosPersona(int opcion)
{
    while (true)
    {
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            system("cls");
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
/*******************************************************************/
void configuracionBackup()

{


    int opc;
    while (true)
    {
        cout << "           CONFIGURACION BACKUPS            " << endl;

        cout<<"1 ---> RESTAURAR BACKUP"<<endl;
        cout<<"2 ---> CREAR BACKUP"<<endl;
        cout<<"3 ---> MOSTRAR BACKUP"<<endl;
        cout<<"0 ---> SALIR"<<endl;


        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            system("cls");
            CrearBackups();
            system("pause");
        }
        break;
        case 2:
            system("cls");
            RestarurarBackups();
            system("pause");

            break;
        case 3:
            system("cls");
            MostrarBackups();
            system("pause");
            break;

        case 0: // finalizar el while
            return;
            break;

        default:
            break;
        }
    }
}
/*******************************************************************/
void CrearBackups(){
    bkpDuenio objBkpDuenio;
    bkpPlanta objBkpPLanta;
    bkpAgroquimicos objBkpAgroquimico;
    bkpHerramientas objBkpHerramienta;
    bkpDetalleFacturaCompra objBkpDetalleFacturaCompra;
    bkpCliente objBkpCliente;
    bkpRegistroCompra objBkpRegistroCompra;
    bkpRegistroVenta objBkpDetalleFacturaVenta;

int opc;
    while (true)
    {
        cout << "1 - CREAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - CREAR BACKUP DUENIO         " << endl;
        cout << "3 - CREAR BACKUP PLANTA         " << endl;
        cout << "4 - CREAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - CREAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - CREAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - CREAR BACKUP CLIENTE            " << endl;
        cout << "8 - CREAR BACKUP REGISTRO COMPRA" << endl;
        cout<<  "9 - CREAR BACKUP DETALLE DE FACTURA VENTA"<<endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            system("cls");
                objBkpDuenio.CrearBackup();
                objBkpPLanta.CrearBackup();
                objBkpAgroquimico.CrearBackup();
                objBkpHerramienta;
                objBkpDetalleFacturaCompra.CrearBackup();
                objBkpCliente.CrearBackup();
                objBkpRegistroCompra.CrearBackup();
                objBkpDetalleFacturaVenta.CrearBackup();
            system("pause");
        }
        case 2:
        {
            system("cls");
                objBkpDuenio.CrearBackup();
            system("pause");
        }
        case 3:
        {
            system("cls");
                objBkpPLanta.CrearBackup();
            system("pause");
        }
        case 4:
        {
            system("cls");
                objBkpAgroquimico.CrearBackup();
            system("pause");
        }
        case 5:
        {
            system("cls");
                objBkpHerramienta.CrearBackup();
            system("pause");
        }
        case 6:
        {
            system("cls");
                objBkpDetalleFacturaCompra.CrearBackup();
            system("pause");
        }
        case 7:
        {
            system("cls");
                objBkpCliente.CrearBackup();
            system("pause");
        }
        case 8:
        {
            system("cls");
                objBkpRegistroCompra.CrearBackup();
            system("pause");
        }
        case 9:
        {
            system("cls");
            objBkpDetalleFacturaVenta.CrearBackup();
            system("pause");
        }
        break;

        case 0: // finalizar el while
            return;
            break;

        default:
            break;
        }
    }
}
/*******************************************************************/
void RestarurarBackups(){
    bkpDuenio objBkpDuenio;
    bkpPlanta objBkpPLanta;
    bkpAgroquimicos objBkpAgroquimico;
    bkpHerramientas objBkpHerramienta;
    bkpDetalleFacturaCompra objBkpDetalleFacturaCompra;
    bkpCliente objBkpCliente;
    bkpRegistroCompra objBkpRegistroCompra;
    bkpRegistroVenta objBkpDetalleFacturaVenta;

int opc;
    while (true)
    {
        cout << "1 - RESTAURAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - RESTAURAR BACKUP DUENIO         " << endl;
        cout << "3 - RESTAURAR BACKUP PLANTA         " << endl;
        cout << "4 - RESTAURAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - RESTAURAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - RESTAURAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - RESTAURAR BACKUP CLIENTE            " << endl;
        cout << "8 - RESTAURAR BACKUP REGISTRO COMPRA" << endl;
        cout<<  "9 - RESTAURAR BACKUP DETALLE DE FACTURA VENTA"<<endl;




        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            system("cls");
                objBkpDuenio.RestaurarBackup();
                objBkpPLanta.RestaurarBackup();
                objBkpAgroquimico.RestaurarBackup();
                objBkpHerramienta;
                objBkpDetalleFacturaCompra.RestaurarBackup();
                objBkpCliente.RestaurarBackup();
                objBkpRegistroCompra.RestaurarBackup();
                objBkpDetalleFacturaVenta.RestaurarBackup();
            system("pause");
        }
        case 2:
        {
            system("cls");
                objBkpDuenio.RestaurarBackup();
            system("pause");
        }
        case 3:
        {
            system("cls");
                objBkpPLanta.RestaurarBackup();
            system("pause");
        }
        case 4:
        {
            system("cls");
                objBkpAgroquimico.RestaurarBackup();
            system("pause");
        }
        case 5:
        {
            system("cls");
                objBkpHerramienta.RestaurarBackup();
            system("pause");
        }
        case 6:
        {
            system("cls");
                objBkpDetalleFacturaCompra.RestaurarBackup();
            system("pause");
        }
        case 7:
        {
            system("cls");
                objBkpCliente.RestaurarBackup();
            system("pause");
        }
        case 8:
        {
            system("cls");
                objBkpRegistroCompra.RestaurarBackup();
            system("pause");
        }
        case 9:
        {
            system("cls");
            objBkpDetalleFacturaVenta.RestaurarBackup();
            system("pause");
        }
        break;

        case 0: // finalizar el while
            return;
            break;

        default:
            break;
        }
    }
}
/*******************************************************************/
void MostrarBackups(){
    bkpDuenio objBkpDuenio;
    bkpPlanta objBkpPLanta;
    bkpAgroquimicos objBkpAgroquimico;
    bkpHerramientas objBkpHerramienta;
    bkpDetalleFacturaCompra objBkpDetalleFacturaCompra;
    bkpCliente objBkpCliente;
    bkpRegistroCompra objBkpRegistroCompra;
    bkpRegistroVenta objBkpDetalleFacturaVenta;

int opc;
    while (true)
    {
        cout << "1 - MOSTRAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - MOSTRAR BACKUP DUENIO         " << endl;
        cout << "3 - MOSTRAR BACKUP PLANTA         " << endl;
        cout << "4 - MOSTRAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - MOSTRAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - MOSTRAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - MOSTRAR BACKUP CLIENTE            " << endl;
        cout << "8 - MOSTRAR BACKUP REGISTRO COMPRA" << endl;
        cout<<  "9 - MOSTRAR BACKUP DETALLE DE FACTURA VENTA"<<endl;




cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            system("cls");
                objBkpDuenio.MostrarBackup();
                objBkpPLanta.MostrarBackup();
                objBkpAgroquimico.MostrarBackup();
                objBkpHerramienta;
                objBkpDetalleFacturaCompra.MostrarBackup();
                objBkpCliente.MostrarBackup();
                objBkpRegistroCompra.MostrarBackup();
                objBkpDetalleFacturaVenta.MostrarBackup();
            system("pause");
        }
        case 2:
        {
            system("cls");
                objBkpDuenio.MostrarBackup();
            system("pause");
        }
        case 3:
        {
            system("cls");
                objBkpPLanta.MostrarBackup();
            system("pause");
        }
        case 4:
        {
            system("cls");
                objBkpAgroquimico.MostrarBackup();
            system("pause");
        }
        case 5:
        {
            system("cls");
                objBkpHerramienta.MostrarBackup();
            system("pause");
        }
        case 6:
        {
            system("cls");
                objBkpDetalleFacturaCompra.MostrarBackup();
            system("pause");
        }
        case 7:
        {
            system("cls");
                objBkpCliente.MostrarBackup();
            system("pause");
        }
        case 8:
        {
            system("cls");
                objBkpRegistroCompra.MostrarBackup();
            system("pause");
        }
        case 9:
        {
            system("cls");
            objBkpDetalleFacturaVenta.MostrarBackup();
            system("pause");
        }
        break;

        case 0: // finalizar el while
            return;
            break;

        default:
            break;
        }
    }
}
/*******************************************************************/
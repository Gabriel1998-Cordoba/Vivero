
#include "menu.h"

///////////////////////////////////////////////////////////////////////////
void menuPrincipal()
{

    int opcion;

    while (true)
    {

        SaltoDeLinea();
        system("cls");
        cout << "opcion 1 ----> Movimientos Empresa" << endl;
        cout << "opcion 2 ----> Movimientos Persona" << endl;
        cout << "opcion 3 ----> Movimientos Duenio" << endl;
        cout << "opcion 0 ----> Fin del Programa" << endl;
        cin >> opcion;
        SaltoDeLinea();
        system("cls");

        switch (opcion)
        {

            /*******************************************************************/
        case 1:
        {
            // menuEmpresa(opcion);
            cout << "En construccion" << endl;
            SaltoDeLinea();
            system("cls");
        }
        break;
            /*******************************************************************/
        case 2:
        {
            menuPersona(opcion);
            SaltoDeLinea();
            system("cls");
        }
        break;
            /*******************************************************************/
        case 3:
        {
            menuDuenio(opcion);
            SaltoDeLinea();
            system("cls");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Fin del programa" << endl;
            system("pause");
            return;
        }
        break;
            /*******************************************************************/
        default:
        {
            SaltoDeLinea();
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
    char contra[30];
    int band = 0;
    int i = 1;

    for (int i = 1; i <= 4; i++)
    {

        if (i <= 3)
        {
            cout << "Ingrese Usuario: " << endl; // el usuario es Vivero
            cargarCadena(usuario, 30);
            cout << "Ingrese Contracenia: " << endl; // la contraceña es 123
            cargarCadena(contra, 30);

            if ((strcmp(contra, "123") == 0) && (strcmp(usuario, "Vivero") == 0))
            {
                band = 1;
                cout << "CORRECTO" << endl;
                system("pause");
                i = 5;
            }
            else
            {
                cout << "El usuario o contracenia son incorrectos" << endl;
            }
        }

        if ((i == 4) && (band == 0))
        {
            SaltoDeLinea();
            system("cls");
            cout << "No ingresaste correctamente el usuario y contracenia" << endl;
            system("pause");
            return;
        }
    }

    if (band == 1)
    {
        // SaltoDeLinea();
        system("cls");
        while (true)
        {

            SaltoDeLinea();
            cout << "---------------------------------------" << endl;
            cout << "          BIENVENIDO DUENIO            " << endl;
            cout << "Opcion 1 ----> Cargar Datos            " << endl; //'ab' de archivos
            cout << "Opcion 2 ----> Modificar Datos         " << endl; //'rb' que lo lea y modifique
            // cout << "Opcion 3 ----> Mostrar Datos Duenio" << endl;
            // cout << "Opcion 4 ----> Borrar o Limpiar Datos" << endl; //'wb' de archivos == 'baja Fisica'
            cout << "Opcion 3 ----> Listar Datos            " << endl; // seleccionar el archivo que quieres que abra y muestre
            cout << "Opcion 4 ----> Informes                " << endl; // esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 5 ----> Consulta x de factura   " << endl; // esto lo hacemos como prueba, para ver si todo funciona bien
            cout << "Opcion 6----> Cargar Datos Del Duenio  " << endl;
            cout << "Opcion 7----> Configuracion de backup  " << endl; // Crear una solapa de configuracion,que contenga las copias de seguridad
            cout << "Opcion 8---> Limpiar Archivos .dat     " << endl; // los borra con 'wb'
            cout << "---------------------------------------" << endl;
            cout << "Opcion 0 ----> salir" << endl; //--> Salir a Menu Principal
            cin >> opcion;

            SaltoDeLinea();
            system("cls");
            switch (opcion)
            {
                /*******************************************************************/
            case 1:
            {
                SaltoDeLinea();
                system("cls");
                CargarDatos(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 2:
            {
                SaltoDeLinea();
                system("cls");
                cout << "FALTA HACERLO" << endl;
                // ModificarDatos(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/

                // case 3:
                // {
                // SaltoDeLinea();
                //     system("cls");
                //     // Para hacer
                //     system("pause");
                // }
                // break;
                /*******************************************************************/
            case 3:
            {
                // SaltoDeLinea();

                ListarDatos(opcion);
            }
            break;
                /*******************************************************************/
                // case 4:
                // {
                //     SaltoDeLinea();
                //     system("cls");
                //     // ContarRegistros(opcion);
                //     system("pause");
                // }
                // break;
                /*******************************************************************/
            case 4:
            {
                SaltoDeLinea();
                system("cls");
                Informes();
                system("pause");
            }
            break;
                /*******************************************************************/
            case 5:
            {
                SaltoDeLinea();
                system("cls");

                FacturaXNroFactura();

                system("pause");
            }
            break;
                /*******************************************************************/
            case 6:
            {
                SaltoDeLinea();
                system("cls");
                CargarDatosDelDuenio(opcion);
                system("pause");
            }
            break;
                /*******************************************************************/
            case 7:
            {
                SaltoDeLinea();
                system("cls");
                configuracionBackup();
                system("pause");
            }
            break;
                /*******************************************************************/
            case 8:
            {
                SaltoDeLinea();
                system("cls");
                LimpiarDatosDeArchivo();

                system("pause");
            }
            break;
                /*******************************************************************/

            case 0:
            {
                SaltoDeLinea();
                system("cls");
                cout << "Saliste" << endl;
                system("pause");
                return;
            }
            break;
                /*******************************************************************/
            default:
            {
                SaltoDeLinea();
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

    system("cls");

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Cargar?" << endl
             << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion 1 ---> Plantas      " << endl; // Crear funcion que carge plantas a un Archivos
        cout << "Opcion 2 ---> Herramientas " << endl; // Crear funcion que carge Herramientas a un Archivos
        cout << "Opcion 3 ---> Agroquimicos " << endl; // Crear funcion que carge Agro Quimicos a un Archivos
        cout << "-----------------------------" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {

            SaltoDeLinea();
            system("cls");
            int tam = 0, cantidad;
            Planta obtP;
            tam = obtP.contarRegistros();
            cout << "Ingrese Cantidad de Registros a Ingresar" << endl;
            cin >> cantidad;

            SaltoDeLinea();
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                obtP.CargarArchivoPlanta(tam, opcion);
            }
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            Herramientas objH;
            int cantidad;
            cout << "Ingrese Cantidad de Registros a Ingresar" << endl;
            cin >> cantidad;
            SaltoDeLinea();
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objH.CargarArchivoHerramienta(opcion);
            }
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            int cantidad;
            Agroquimicos objA;
            cout << "Ingrese Cantidad de Registros a Ingresar" << endl;
            cin >> cantidad;

            SaltoDeLinea();
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objA.CargarArchivoAgroquimicos(opcion);
            }

            system("pause");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
            system("pause");
        }
        break;
            /*******************************************************************/
        }
    }
}
///////////////////////////////////////////////////////////////////////////
// void LimpiarDatos(int opcion)
// {
//     Planta obtP;
//     Herramientas obtH;
//     Agroquimicos obtA;

//     SaltoDeLinea();
//     system("cls");
//     cout << "Que quieres   ? " << endl
//          << endl;
//     cout << "Opcion 1 ---> Plantas" << endl;       // Crear funcion que carge plantas a un Archivos
//     cout << "Opcion 2 ---> Herramientas" << endl;  // Crear funcion que carge Herramientas a un Archivos
//     cout << "Opcion 3 ---> Agro Quimicos" << endl; // Crear funcion que carge Agro Quimicos a un Archivos
//     cout << "Opcion 0 ----> salir" << endl;
//     cin >> opcion;

//     SaltoDeLinea();
//     system("cls");
//     switch (opcion)
//     {
//     /*******************************************************************/
//     case 1:
//     {
//         SaltoDeLinea();
//         system("cls");

//         if (obtP.borrarRegistroPlanta() == true)
//         {
//             cout << "Se borro Correctamente" << endl;
//         }
//         else
//         {
//             cout << "No se pudo borrar" << endl;
//         }

//         system("pause");
//         // ARMAR UNA FUNCION QUE PERMITA CARGAR EN ARCHIVO Planta
//         //  Planta ob1;
//         //  ob1.Cargar();
//     }
//     break;
//     /*******************************************************************/
//     case 2:
//     {
//         SaltoDeLinea();
//         system("cls");
//         if (obtH.borrarRegistroHerramienta() == true)
//         {
//             cout << "Se borro Correctamente" << endl;
//         }
//         else
//         {
//             cout << "NO se pudo borrar" << endl;
//         }
//         system("pause");
//     }
//     break;
//     /*******************************************************************/
//     case 3:
//     {
//         SaltoDeLinea();
//         system("cls");
//         if (obtA.borrarRegistroAgroquimicos() == true)
//         {
//             cout << "se borro Correctamente" << endl;
//         }
//         else
//         {
//             cout << "No se pudo borrar" << endl;
//         }
//         system("pause");
//     }
//     break;
//         /*******************************************************************/
//     case 0:
//     {
//         SaltoDeLinea();
//         system("cls");
//         cout << "Saliste" << endl;
//         system("pause");
//         return;
//     }
//     break;
//     /*******************************************************************/
//     default:
//     {
//         SaltoDeLinea();
//         system("cls");
//         cout << "valor ingresado no existe dentro del menu" << endl;
//         system("pause");
//     }
//     break;
//         /*******************************************************************/
//     }
// }
///////////////////////////////////////////////////////////////////////////
void ListarDatos(int opcion)
{
    SaltoDeLinea();
    system("cls");
    Planta obtP;
    Herramientas obtH;
    Agroquimicos obtA;

    while (true)
    {
        system("cls");
        SaltoDeLinea();
        cout << "Que quieres Listar?" << endl
             << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion 1 ---> planta.dat" << endl;       // Crear funcion que carge plantas a un Archivos
        cout << "Opcion 2 ---> herramientas.dat" << endl; // Crear funcion que carge Herramientas a un Archivos
        cout << "Opcion 3 ---> agroquimicos.dat" << endl; // Crear funcion que carge Agro Quimicos a un Archivos
        cout << "Opcion 4 ---> Cliente.dat" << endl;
        cout << "Opcion 5 ---> duenio.dat" << endl;
        cout << "Opcion 6 ---> registrocompra.dat" << endl;
        cout << "Opcion 7 ---> DetalleFacturaCompra.dat" << endl;
        cout << "Opcion 8 ---> DetalleFacturaVenta.dat" << endl;
        cout << "Opcion 9 ---> registroVenta" << endl;
        cout << "-----------------------------" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");

            cout << "Listado de Plantas: " << endl
                 << endl;
            obtP.ListarPlanta();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Listado de Herrramientas: " << endl
                 << endl;
            obtH.ListarHerramienta();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Listado de AgroQuimicos: " << endl
                 << endl;
            obtA.ListarAgroquimicos();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            Cliente objCC;
            cout << "Listado de Cliente: " << endl
                 << endl;
            objCC.MostrarDatosClienteEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            Duenio objDD;
            cout << "Listado de Duenio: " << endl
                 << endl;
            objDD.MostrarDatosDeDuenioEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 6:
        {
            SaltoDeLinea();
            system("cls");
            RegistroCompra objDD;
            cout << "Listado de Registro Compra: " << endl
                 << endl;
            objDD.MostrarArchivoCompra();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 7:
        {
            SaltoDeLinea();
            system("cls");
            DetalleFacturaCompra objDD;
            cout << "Listado de Detalle Factura Compra: " << endl
                 << endl;
            objDD.MostrarDatosDetalleFacturaCompraEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 8:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Listado de Detalle Factura Venta: " << endl
                 << endl;
            system("pause");
        }
        break;
            /*******************************************************************/
        case 9:
        {
            SaltoDeLinea();
            system("cls");
            RegistroVenta objDD;
            cout << "Listado de Detalle Factura Venta: " << endl
                 << endl;
            objDD.MostrarArchivoVenta();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Listar?" << endl
             << endl;
        cout << "---------------------------------------" << endl;
        cout << "Opcion 1 ----> Cargar Datos Del Duenio " << endl;
        cout << "Opcion 2 ----> Mostrar Datos Del Duenio" << endl;
        cout << "Opcion 3 ----> Cambiar Sueldo Cargado" << endl;
        cout << "Opcion 4 ----> Mostrar Sueldo Cargado" << endl;
        cout << "Opcion 5 ----> Borrar Datos Del Duenio" << endl;
        cout << "---------------------------------------" << endl;

        cout << "Opcion 0 ----> Salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");

            int tam = 0, cantidad;

            cout << "Ingrese Cantidad de Registros" << endl;
            cin >> cantidad;

            SaltoDeLinea();
            system("cls");
            for (int i = 0; i < cantidad; i++)
            {
                objD.CargarDatosDeDuenioEnArchivo(/*tam , opcion*/);
            }
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objD.MostrarDatosDeDuenioEnArchivo();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objD.CambiarSueldoCargadoEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            objD.MostrarSueldoCargadoEnArchivo();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            objD.BorrarDatosDelDuenio();
            system("pause");
        }
        break;
            /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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

    SaltoDeLinea();
    system("cls");

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Opcion 1 ----> Comprar" << endl;
        cout << "Opcion 2 ----> Vender" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            ///////////////////////////////////
            bool band = true;

            if (band == true)
            {

                bkpRegistroCompra objRegistro;
                objRegistro.CrearBackup();
                band = false;
            }
            ///////////////////////////////////

            // hacer una funcion que me cuente cuantos registros hay
            RegistroCompra objR;
            int tam = objR.contarRegistros();
            // int idcompra;

            if (tam == -1)
            {
                objR.setIdCompra(tam + 2);
            }
            else
            {
                objR.setIdCompra(tam + 1);
            }

            SaltoDeLinea();
            system("cls");
            menuCompraPersona(opcion, objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            menuVentaPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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
    SaltoDeLinea();
    system("cls");

    bkpAgroquimicos objBkpAgroquimico;
    objBkpAgroquimico.CrearBackup();

    bkpHerramientas objBkpHerramienta;
    objBkpHerramienta.CrearBackup();

    bkpPlanta objBkpPlanta;
    objBkpPlanta.CrearBackup();

    bool bandHerramientas = false;
    bool bandPlanta = false;
    bool bandAgroquimicos = false;
    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "---------------------------------------" << endl;
        cout << "Opcion 1 ----> Herramientas" << endl;
        cout << "Opcion 2 ----> Plantas" << endl;
        cout << "Opcion 3 ----> Agroquimicos" << endl;
        cout << "---------------------------------------" << endl;
        cout << "¿Opcion 0 ----> Ya termino de Comprar?" << endl;

        cin >> opcion;
        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");

            bandHerramientas = true;
            menuCompraHerramientaPersona(opcion, objR);

            // system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");

            bandPlanta = true;
            menuCompraPlantaPersona(opcion, objR);

            // system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");

            bandAgroquimicos = true;
            menuCompraAgroquimicosPersona(opcion, objR);

            // system("pause");
        }
        break;

        case 0:
        {
            SaltoDeLinea();
            system("cls");

            do
            {
                cout<<"---------------------------------------------"<<endl;
                cout <<"Quieres Registrar la Compra?   --->  == 0   "<< endl;
                cout <<"NO quiero esta compra          --->  == 1   "<< endl;
                cout <<"Quieres Comprar otra cosa mas? --->  == 2   "<< endl;
                cout<<"---------------------------------------------"<<endl;
                cin >> opcion;

                if ((opcion != 0) && (opcion != 1) && (opcion != 2))
                {
                    cout << "Valores ingresados no existentes, vuelva a ingresar" << endl;
                }
            } while ((opcion != 0) && (opcion != 1) && (opcion != 2));

            if (opcion == 0)
            {

                cout << "Ya que esta seguro, ahora debe de cargar su Registros de Cliente" << endl;
                Cliente cli;
                int id;
                cout << "Ingrese ID del Cliente" << endl;
                cin >> id;

                system("pause");
                // cout<<"cli.getIDCliente(): "<<cli.getIDCliente()<<endl;

                if (/*cli.getIDCliente() == -1 || cli.getIDCliente() == -2*/ ValidarCliente(id) == false)
                {
                    cout << "Se registra el nuevo cliente" << endl;

                    cli.Cargar();

                    if (cli.GuardarArchivo() == true)
                    {
                        cout << "Se registro correctamente el cliente" << endl;
                        system("pause");
                    }
                    else
                    {

                         cout << "No se registro correctamente el cliente" << endl;
                        system("pause");
                    }
                }
                else
                {

                    cout << "EL CLIENTE ESTA REGISTRADO..." << endl;
                    system("pause");
                }
                SaltoDeLinea();
                system("cls");
                objR.CargarCompra(objR, cli.getIDCliente());

                if (objR.GuardarCompra())
                {
                    SaltoDeLinea();
                    system("cls");
                    bkpRegistroCompra objBkpRefistroCompra;
                    objBkpRefistroCompra.CrearBackup();
                    cout << "Se registro correctamente la compra " << endl;
                    GenerarFactura(objR);
                }
                return;
            }
            else if (opcion == 1)
            {
                bkpRegistroCompra objBkpRegistroCompra;
                objBkpRegistroCompra.RestaurarBackup();
                bkpDetalleFacturaCompra ojbBkpDetalleFCompra;
                ojbBkpDetalleFCompra.RestaurarBackup(); // cout<<"<--aqui?"<<endl;
                if (bandHerramientas == true)
                {
                    objBkpHerramienta.RestaurarBackup();
                }
                if (bandAgroquimicos == true)
                {
                    objBkpAgroquimico.RestaurarBackup();
                }
                if (bandPlanta == true)
                {
                    objBkpPlanta.RestaurarBackup();
                }
                return;
                system("pause"); //
            }
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;

        cout << "Opcion 1 ----> Herramientas" << endl;
        cout << "Opcion 2 ----> Plantas" << endl;
        cout << "Opcion 3 ----> Agroquimicos" << endl;

        cout << "¿Opcion 0 ----> Ya termino de Comprar?" << endl;

        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            menuVentaHerramientaPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            menuVentaPlantaPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            menuVentaAgroquimicosPersona(opcion);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            return;
        }
        break;
            //     /*******************************************************************/
        default:
        {
            SaltoDeLinea();
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

void menuCompraPlantaPersona(int opcion, RegistroCompra objR)
{
    SaltoDeLinea();
    system("cls");
    Planta objP;

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Comprar?" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS PLANTAS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Planta quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE PLANTA QUE QUIERE COMPRAR" << endl;
        cout << "----------------------------------------------------------------------" << endl;

        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            objP.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objP.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objP.Opcion3Compra(objR);
            system("pause");
        }
        break;
            /*******************************************************************/

        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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

    SaltoDeLinea();
    system("cls");

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Comprar?" << endl
             << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS HERRAMIENTAS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Herramientas quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE HERRAMIENTA QUE QUIERE COMPRAR" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            objH.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objH.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objH.Opcion3Compra(objR);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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
    SaltoDeLinea();
    system("cls");

    Agroquimicos objA;

    // hacer una funcion que me cuente cuantos registros hay
    int tam = objR.contarRegistros();

    if (tam == -1)
    {
        tam = 0;
    }

    // int idCompra = tam;
    int idCompra = tam + 1;
    objR.setIdCompra(idCompra);

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Comprar?" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Opcion 1 ----> DETALLE TODAS LAS AGROQUIMICOS,PRECIO,STOCK" << endl;
        cout << "Opcion 2 ----> Cual Agroquimico quiere y Mostraremos SU Precio y Stock" << endl;
        cout << "Opcion 3 ----> SELECCIONE AGROQUIMICO QUE QUIERE COMPRAR" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;

        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            objA.Opcion1Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objA.Opcion2Compra();
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objA.Opcion3Compra(idCompra);
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Valor ingresado no existe dentro del menu" << endl;
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
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
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
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
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
        SaltoDeLinea();
        system("cls");
        cout << "Que quieres Vender?" << endl
             << endl;
        cout << "Opcion 1 ----> " << endl;
        cout << "Opcion 2 ----> " << endl;
        cout << "Opcion 3 ----> " << endl;
        cout << "Opcion 0 ----> salir" << endl;
        cin >> opcion;
        SaltoDeLinea();
        system("cls");
        switch (opcion)
        {
        /*******************************************************************/
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
            /*******************************************************************/
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            system("pause");
        }
        break;
        /*******************************************************************/
        case 0:
        {
            SaltoDeLinea();
            system("cls");
            cout << "Saliste" << endl;
            system("pause");
            return;
        }
        break;
        /*******************************************************************/
        default:
        {
            SaltoDeLinea();
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
        SaltoDeLinea();
        system("cls");
        cout << "           CONFIGURACION BACKUPS            " << endl;
        cout << "----------------------------------------------"<<endl;
        cout << "1 ---> RESTAURAR BACKUP" << endl;
        cout << "2 ---> CREAR BACKUP    " << endl;
        cout << "3 ---> MOSTRAR BACKUP  " << endl;
        cout << "----------------------------------------------"<<endl;
        cout << "0 ---> SALIR" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            RestarurarBackups();

            system("pause");
        }
        break;
        case 2:
            SaltoDeLinea();
            system("cls");
            CrearBackups();
            system("pause");

            break;
        case 3:
            SaltoDeLinea();
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
void CrearBackups()
{
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
        SaltoDeLinea();
        system("cls");
        cout << "1 - CREAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - CREAR BACKUP DUENIO         " << endl;
        cout << "3 - CREAR BACKUP PLANTA         " << endl;
        cout << "4 - CREAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - CREAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - CREAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - CREAR BACKUP CLIENTE            " << endl;
        cout << "8 - CREAR BACKUP REGISTRO COMPRA" << endl;
        cout << "9 - CREAR BACKUP DETALLE DE FACTURA VENTA" << endl;

        cout << "0 - VOLVER" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDuenio.CrearBackup();
            objBkpPLanta.CrearBackup();
            objBkpAgroquimico.CrearBackup();
            objBkpHerramienta.CrearBackup();
            objBkpDetalleFacturaCompra.CrearBackup();
            objBkpCliente.CrearBackup();
            objBkpRegistroCompra.CrearBackup();
            objBkpDetalleFacturaVenta.CrearBackup();
            system("pause");
        }
        break;
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDuenio.CrearBackup();
            system("pause");
        }
        break;
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objBkpPLanta.CrearBackup();
            system("pause");
        }
        break;
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            objBkpAgroquimico.CrearBackup();
            system("pause");
        }
        break;
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            objBkpHerramienta.CrearBackup();
            system("pause");
        }
        break;
        case 6:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDetalleFacturaCompra.CrearBackup();
            system("pause");
        }
        break;
        case 7:
        {
            SaltoDeLinea();
            system("cls");
            objBkpCliente.CrearBackup();
            system("pause");
        }
        break;
        case 8:
        {
            SaltoDeLinea();
            system("cls");
            objBkpRegistroCompra.CrearBackup();
            system("pause");
        }
        break;
        case 9:
        {
            SaltoDeLinea();
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
void RestarurarBackups()
{
    SaltoDeLinea();
    system("cls");

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
        SaltoDeLinea();
        system("cls");
        cout << "1 - RESTAURAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - RESTAURAR BACKUP DUENIO         " << endl;
        cout << "3 - RESTAURAR BACKUP PLANTA         " << endl;
        cout << "4 - RESTAURAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - RESTAURAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - RESTAURAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - RESTAURAR BACKUP CLIENTE            " << endl;
        cout << "8 - RESTAURAR BACKUP REGISTRO COMPRA" << endl;
        cout << "9 - RESTAURAR BACKUP DETALLE DE FACTURA VENTA" << endl;

        cout << "0 - VOLVER" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            SaltoDeLinea();
            system("cls");

            int cont = 0;

            if (objBkpDuenio.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpPLanta.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpAgroquimico.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpHerramienta.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpDetalleFacturaCompra.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpCliente.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpRegistroCompra.RestaurarBackup() == false)
            {
                cont++;
            }
            if (objBkpDetalleFacturaVenta.RestaurarBackup() == false)
            {
                cont++;
            }

            if (cont == 0)
            {
                cout << "TODOS LOS BACKUPS RESTAURADOS EXITOSAMENTE" << endl;
            }

            system("pause");
        }
        break;
        case 2:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDuenio.RestaurarBackup();
            system("pause");
        }
        break;
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            objBkpPLanta.RestaurarBackup();
            system("pause");
        }
        break;
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            objBkpAgroquimico.RestaurarBackup();
            system("pause");
        }
        break;
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            objBkpHerramienta.RestaurarBackup();
            system("pause");
        }
        break;
        case 6:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDetalleFacturaCompra.RestaurarBackup();
            system("pause");
        }
        break;
        case 7:
        {
            SaltoDeLinea();
            system("cls");
            objBkpCliente.RestaurarBackup();
            system("pause");
        }
        break;
        case 8:
        {
            SaltoDeLinea();
            system("cls");
            objBkpRegistroCompra.RestaurarBackup();
            system("pause");
        }
        break;
        case 9:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDetalleFacturaVenta.RestaurarBackup();
            system("pause");
            break;
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
void MostrarBackups()
{
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
        SaltoDeLinea();
        system("cls");
        cout << "1 - MOSTRAR TODOS LOS BACKUPS     " << endl;
        cout << "2 - MOSTRAR BACKUP DUENIO         " << endl;
        cout << "3 - MOSTRAR BACKUP PLANTA         " << endl;
        cout << "4 - MOSTRAR BACKUP AGROQUIMICOS   " << endl;
        cout << "5 - MOSTRAR BACKUP HERRAMIENTA               " << endl;
        cout << "6 - MOSTRAR BACKUP DETALLE DE FACTURA COMPRA" << endl;
        cout << "7 - MOSTRAR BACKUP CLIENTE            " << endl;
        cout << "8 - MOSTRAR BACKUP REGISTRO COMPRA" << endl;
        cout << "9 - MOSTRAR BACKUP DETALLE DE FACTURA VENTA" << endl;

        cout << "0 - VOLVER" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            SaltoDeLinea();
            system("cls");
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS DUENIO: " << endl
                 << endl
                 << endl;
            objBkpDuenio.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS PLANTA: " << endl
                 << endl
                 << endl;
            objBkpPLanta.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS AGROQUIMICOS: " << endl
                 << endl
                 << endl;
            objBkpAgroquimico.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS HERRAMIENTAS: " << endl
                 << endl
                 << endl;
            objBkpHerramienta.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS DETALLE DE FACTURA COMPRA: " << endl
                 << endl
                 << endl;
            objBkpDetalleFacturaCompra.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS CLIENTE: " << endl
                 << endl
                 << endl;
            objBkpCliente.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS REGISTRO COMPRA: " << endl
                 << endl
                 << endl;
            objBkpRegistroCompra.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            cout << "DATOS DETALLE DE FACTURA VENTA: " << endl
                 << endl
                 << endl;
            objBkpDetalleFacturaVenta.MostrarBackup();
            cout << "--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--" << endl;
            system("pause");
        }
        break;
        case 2:
        {

            SaltoDeLinea();
            system("cls");
            objBkpDuenio.MostrarBackup();
            system("pause");
        }
        break;
        case 3:
        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS PLANTA: " << endl;
            objBkpPLanta.MostrarBackup();
            system("pause");
        }
        break;
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS AGROQUIMICOS: " << endl
                 << endl
                 << endl;
            objBkpAgroquimico.MostrarBackup();
            system("pause");
        }
        break;
        case 5:
        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS HERRAMIENTAS: " << endl
                 << endl
                 << endl;
            objBkpHerramienta.MostrarBackup();
            system("pause");
        }
        break;
        case 6:
        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS DETALLE DE FACTURA COMPRA: " << endl
                 << endl
                 << endl;
            objBkpDetalleFacturaCompra.MostrarBackup();
            system("pause");
        }
        break;
        case 7:
        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS CLIENTE: " << endl
                 << endl
                 << endl;
            objBkpCliente.MostrarBackup();
            system("pause");
        }
        break;
        case 8:

        {
            SaltoDeLinea();
            system("cls");
            cout << "DATOS REGISTRO COMPRA: " << endl
                 << endl
                 << endl;
            objBkpRegistroCompra.MostrarBackup();
            system("pause");
        }
        break;
        case 9:
        {
            SaltoDeLinea();
            system("cls");
            objBkpDetalleFacturaVenta.MostrarBackup();
            system("pause");
        }
        break;

        case 0: // finalizar el while

            return;
            break;

        default:
            cout << "Valor no valido" << endl;
            break;
        }
    }
}
/*******************************************************************/
void LimpiarDatosDeArchivo()
{
    int opc;

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "1 - Limpiar --> DetalleFacturaCompra.dat" << endl;
        cout << "2 - Limpiar --> Registrocompra.dat" << endl;
        cout << "3 - Limpiar --> Agroquimicos.dat" << endl;
        cout << "4 - Limpiar --> Cliente.dat" << endl;
        cout << "5 - Limpiar --> Duenio.dat" << endl;
        cout << "6 - Limpiar --> Herramientas.dat" << endl;
        cout << "7 - Limpiar --> Planta.dat" << endl;

        cout << endl
             << endl
             << "Limpiar Backups" << endl
             << endl;

        cout << "8 - Limpiar--> bkpDetalleFacturaCompra.dat" << endl;
        cout << "9 - Limpiar--> bkpregistroCompra.dat" << endl;
        cout << "10- Limpiar --> bkpAgroquimicos.dat" << endl;
        cout << "11- Limpiar --> bkpCliente.dat" << endl;
        cout << "12- Limpiar --> bkpduenio.dat" << endl;
        cout << "13- Limpiar --> bkpherramientas.dat" << endl;
        cout << "14- Limpiar --> bkpplanta.dat" << endl;

        cout << "0 - VOLVER" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        case 2:
        {

            int valor;
            cout << "Si se Limpia DetalleFacturaCompra.dat" << endl;
            cout << "Se limpiara tambien registrocompra.dat" << endl;
            cout << "Y Viseversa" << endl;
            cout << "Quiere continuar" << endl;
            cout << "SI == 1 / NO == 0" << endl;
            cin >> valor;

            if (valor == 1)
            {
                SaltoDeLinea();
                system("cls");
                FILE *p1, *p2;
                p1 = fopen("DetalleFacturaCompra.dat", "wb");
                p2 = fopen("registrocompra.dat", "wb");
                if ((p1 == NULL) | (p2 == NULL))
                {
                    cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de DetalleFacturaCompra.dat o registrocompra.dat" << endl;
                }
                else
                {
                    cout << "Se limpiaron los archivos Correctamente" << endl;
                    fclose(p1);
                    fclose(p2);
                }
            }
            else
            {

                cout << "No se limpiaron los datos" << endl;
            }

            system("pause");
        }
        break;

        case 3:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("agroquimicos.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de agroquimicos.dat" << endl;
            }
            else
            {
                cout << "se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 4:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("Cliente.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de Cliente.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 5:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("duenio.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de duenio.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 6:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("herramientas.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de herramientas.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 7:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("planta.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de planta.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;
            ///////////////////////////////////////////////////////////////////////////
        case 8:
        case 9:
        {

            int valor;
            cout << "Si se Limpia DetalleFacturaCompra.dat" << endl;
            cout << "se limpiara tambien registrocompra.dat" << endl;
            cout << "Y Viseversa" << endl;
            cout << "Quiere continuar" << endl;
            cout << "SI == 1 / NO == 0" << endl;
            cin >> valor;

            if (valor == 1)
            {
                SaltoDeLinea();
                system("cls");
                FILE *p1, *p2;
                p1 = fopen("bkpDetalleFacturaCompra.dat", "wb");
                p2 = fopen("bkpregistrocompra.dat", "wb");
                if ((p1 == NULL) | (p2 == NULL))
                {
                    cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpDetalleFacturaCompra.dat o bkpregistrocompra.dat" << endl;
                }
                else
                {
                    cout << "Se limpiaron los archivos Correctamente" << endl;
                    fclose(p1);
                    fclose(p2);
                }
            }
            else
            {

                cout << "No se limpiaron los datos" << endl;
            }

            system("pause");
        }
        break;

        case 10:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("bkpagroquimicos.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpagroquimicos.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 11:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("bkpCliente.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpCliente.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 12:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("bkpduenio.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpduenio.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 13:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("bkpherramientas.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpherramientas.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;

        case 14:
        {
            SaltoDeLinea();
            system("cls");
            FILE *p1;
            p1 = fopen("bkpplanta.dat", "wb");
            if (p1 == NULL)
            {
                cout << "ERROR de ARCHIVO = LimpiarDatosDeArchivo, de bkpplanta.dat" << endl;
            }
            else
            {
                cout << "Se limpiaron los archivos Correctamente" << endl;
                fclose(p1);
            }

            system("pause");
        }
        break;
            /////////////////////////////////////////////////
        case 0: // finalizar el while
            return;
            break;

        default:
            break;
        }
    }
}
/*******************************************************************/

void Informes()
{
    int opc;

    while (true)
    {
        SaltoDeLinea();
        system("cls");
        cout << "1 -Recaudacion por Anio" << endl;
        cout << "2 -Recaudacion Mensual " << endl;
        cout << "3 -Producto mas vendido" << endl;
        cout << "4 -Cantidad de Clientes" << endl;
        cout << "5 -Cliente que mas compro " << endl;
        cout << "6 -Cantidad de compra por cliente" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0 -Salir" << endl;
        cout << "-------------------------------------" << endl;

        cout << "INGRESE UNA OPCION: ";
        cin >> opc;
        switch (opc)
        {

            /*//////////////////////////////////*/
        case 1:
        {
            SaltoDeLinea();
            system("cls");

            Fecha objF;
            int AnioIngresado;

            do
            {
                cout << "Ingresa el Anio que quiera ver su recaudacion: ";
                cin >> AnioIngresado;

                if (AnioIngresado > objF.getAnioActual())
                {
                    cout << "Valor ingresado es mayor al anio actual, ingrese uno menor o igual" << endl;
                }

                if (AnioIngresado < 1900)
                {
                    cout << "Valor ingresado es menor a 1900, ingrese uno mayor o igual" << endl;
                }

            } while ((AnioIngresado > objF.getAnioActual()) && (AnioIngresado < 1900));

            RecaudacionAnual(AnioIngresado);
            cout << endl;
            system("pause");
        }
        break;
            /*//////////////////////////////////*/
        case 2:
        {
            SaltoDeLinea();
            system("cls");

            // nos falta poner que dectecte si el año es bisiesto

            Fecha objF;
            int mesIngresado;
            bool band;

            do
            {
                cout << "Ingresa el Mes que quiera ver su recaudacion: ";
                band = true;
                cin >> mesIngresado;

                if (mesIngresado > 12)
                {
                    cout << "Valor ingresado es mayor a 12" << endl;
                    band = false;
                }
                else if (mesIngresado < 1)
                {
                    cout << "Valor ingresado es menor a 1" << endl;
                    band = false;
                }

                // if(mesIngresado<1900){
                //     cout<<"valor ingresado es menor a 1900, ingrese uno mayor o igual"<<endl;
                // }

            } while ((band != true));

            RecaudacionMensual(mesIngresado);

            cout << endl;

            system("pause");
        }
        break;
            /*//////////////////////////////////*/

        case 3:
        {
            SaltoDeLinea();
            system("cls");

            int indicePlanta = 0;
            int indiceHerramientas = 0;
            int indiceAgroquimicos = 0;

            Planta objP;
            const int tamRegPlanta = objP.contarRegistros();
            int *vPlanta = new int[tamRegPlanta];
            if (vPlanta == NULL)
            {
                cout << "No se pudo asignar memoria" << endl;
                return;
            }
            ponerEnCeroVector(vPlanta, tamRegPlanta);

            Herramientas objH;
            const int tamRegHerramienta = objH.contarRegistros();
            int *vHerramienta = new int[tamRegHerramienta];
            if (vHerramienta == NULL)
            {
                cout << "No se pudo asignar memoria" << endl;
                return;
            }
            ponerEnCeroVector(vHerramienta, tamRegHerramienta);

            Agroquimicos objA;
            const int tamRegAgroquimicos = objA.contarRegistros();
            int *vAgroquimicos = new int[tamRegAgroquimicos];
            if (vAgroquimicos == NULL)
            {
                cout << "No se pudo asignar memoria" << endl;
                return;
            }
            ponerEnCeroVector(vAgroquimicos, tamRegAgroquimicos);

            DetalleFacturaCompra objDetFactura;
            int tam = objDetFactura.contarRegistros();

            for (int i = 0; i < tam; i++)
            {

                objDetFactura = objDetFactura.leerRegistro(i);

                if (objDetFactura.getTipoDeArticulo() == 1)
                {

                    for (int x = 0; x < tamRegPlanta; x++)
                    {

                        objP = objP.leerRegistroPlanta(x);

                        if (objP.getID() == objDetFactura.getIdArticulo())
                        {
                            vPlanta[x] += 1;
                        }
                    }

                    indicePlanta = buscarMaximo(vPlanta, tamRegPlanta);
                }

                else if (objDetFactura.getTipoDeArticulo() == 2)
                {
                    for (int j = 0; j < tamRegHerramienta; j++)
                    {

                        objH = objH.leerRegistroHerramienta(j);

                        if (objH.getID() == objDetFactura.getIdArticulo())
                        {
                            vHerramienta[j] += 1;
                        }
                    }
                    indiceHerramientas = buscarMaximo(vHerramienta, tamRegHerramienta);
                }
                else if (objDetFactura.getTipoDeArticulo() == 99)
                {
                    for (int k = 0; k < tamRegAgroquimicos; k++)
                    {

                        objA = objA.leerRegistroAgroquimicos(k);

                        if (objA.getID() == objDetFactura.getIdArticulo())
                        {
                            vAgroquimicos[k] += 1;
                        }
                    }
                    indiceAgroquimicos = buscarMaximo(vAgroquimicos, tamRegAgroquimicos);
                }
            }

            int max1 = vPlanta[indicePlanta];
            int maxPrime = max1;
            int indicePrime = indicePlanta;
            int max2 = vHerramienta[indiceHerramientas];
            int max3 = vAgroquimicos[indiceAgroquimicos];

            if (max2 > maxPrime)
            {

                maxPrime = max2;
                indicePrime = indiceHerramientas;

                if (max3 > maxPrime)
                {

                    maxPrime = max3;
                    indicePrime = indiceAgroquimicos;

                    objA = BuscarAgroquimicos(indicePrime + 1);
                    cout << "El Producto mas vendido es: " << endl;
                    cout << "----------------------------" << endl;
                    objA.Mostrar();
                    cout << "----------------------------" << endl;
                    cout << "con un maximo de ventas de : " << maxPrime << endl;
                    system("pause");
                }
                else
                {

                    objH = BuscarHerramienta(indicePrime + 1);
                    cout << "El Producto mas vendido es: " << endl;
                    cout << "----------------------------" << endl;
                    objH.Mostrar();
                    cout << "----------------------------" << endl;
                    cout << "con un maximo de ventas de : " << maxPrime << endl;
                    system("pause");
                }
            }
            else if (max3 > maxPrime)
            {

                maxPrime = max3;
                indicePrime = indiceAgroquimicos;
                objA = BuscarAgroquimicos(indicePrime + 1);
                cout << "El Producto mas vendido es: " << endl;
                cout << "----------------------------" << endl;
                objA.Mostrar();
                cout << "----------------------------" << endl;
                cout << "con un maximo de ventas de : " << maxPrime << endl;
                system("pause");
            }
            else
            {

                int maxPrime = max1;
                int indicePrime = indicePlanta;
                objP = BuscarPlanta(indicePrime + 1);
                cout << "El Producto mas vendido es: " << endl;
                cout << "----------------------------" << endl;
                objP.Mostrar();
                cout << "----------------------------" << endl;
                cout << "con un maximo de ventas de : " << maxPrime << endl;
                system("pause");
            }
            system("pause");
            delete[] vPlanta;
            delete[] vHerramienta;
            delete[] vAgroquimicos;
        }
        break;
            /*//////////////////////////////////*/
        case 4:
        {
            SaltoDeLinea();
            system("cls");
            // cout << "4 - cantidad de Clientes" << endl;
            Cliente objCliente;
            int tam = objCliente.CONtarRegistros();
            cout << "la cantidad de clientes es: " << tam << endl;
            system("pause");
        }
        break;
            /*//////////////////////////////////*/
        case 5:

        {
            SaltoDeLinea();
            system("cls");

            // cout << "5 - Cliente que mas compro " << endl;
            Cliente objCliente;
            int max = 0;

            const int tam = objCliente.CONtarRegistros();
            int *vCliente = new int[tam];

            if (vCliente == NULL)
            {
                cout << "No se pudo asignar memoria" << endl;
                return;
            }

            ponerEnCeroVector(vCliente, tam);

            for (int i = 0; i < tam; i++)
            {

                objCliente = objCliente.leerRegistros(i);

                cargarVectordeAcumulacion(vCliente, objCliente);
            }

            int indice = buscarMaximo(vCliente, tam);
            objCliente = buscarCliente(indice + 1);
            max = vCliente[indice];

            cout << "El cliente que mas compras hizo es: " << endl;
            cout << objCliente.getApellido() << "," << objCliente.getNombre() << endl;
            cout << "ID Cliente: " << objCliente.getIDCliente() << endl;
            cout << "Con un maximo de compra de: " << max << endl;

            system("pause");
            delete[] vCliente;
        }

        break;
            /*//////////////////////////////////*/
        case 6:
        {
            // cout << "6 - cantidad de compra por cliente" << endl;
            SaltoDeLinea();
            system("cls");
            Cliente objCliente;
            const int tam = objCliente.CONtarRegistros();
            int cont = 0;

            int idCliente;
            cout << "Ingrese ID de Cliente" << endl;
            cin >> idCliente;

            for (int i = 0; i < tam; i++)
            {
                cont = ContadorDeCliente(idCliente); // Cuenta las compras de un cliente
            }

            cout << "El total de Compras su cliente es: " << cont << endl;
            system("pause");
        }
        break;
            /*//////////////////////////////////*/
        case 0:
        {
            return;
        } // finalizar el while

        break;
            /*//////////////////////////////////*/

        default:
        {
        }
        break;
            /*//////////////////////////////////*/
        }
    }
}

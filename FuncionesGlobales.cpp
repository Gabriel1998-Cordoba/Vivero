#include <iostream>
using namespace std;
#include "FuncionesGlobales.h"

void cargarCadena(char *palabra, int tamano)
{
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tamano; i++)
    {
        palabra[i] = cin.get();
        if (palabra[i] == '\n')
        {
            break;
        }
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void SaltoDeLinea(int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << endl
             << endl
             << endl
             << endl;
    }
}

void GenerarFactura(RegistroCompra objR, int id)
{
    int tam = 0;
    DetalleFacturaCompra objD;
    tam = objD.contarRegistros();

    Cliente objC;
    int tam2 = objC.CONtarRegistros();

    cout << "CLIENTE ----------------" << endl;

    for (int i = 0; i < tam2; i++)
    {
        if (objC.LeerArchivo(i))
        {

            if (objC.getIDCliente() == id)
            {
                cout << "----------------" << endl;
                objC.Mostrar();
                cout << "----------------" << endl;
            }
        }
    }

    cout << "Cabecera factura ----------------" << endl;

    cout << "----------------" << endl;
    objR.Mostrar();
    cout << "----------------" << endl;

    cout << "Detalle Factura Compra ----------------" << endl;

    for (int i = 0; i < tam; i++)
    {
        objD = objD.leerRegistro(i);

        if (objD.getIdCompra() == objR.getIdCompra())
        {

            objD.Mostrar();
        }
    }
}
void FacturaXNroFactura()
{
    Planta objP;
    Herramientas objH;
    Agroquimicos objA;
    int tam, tamDetalleFactura;

    int nroFactura;
    cout << "ingrese numero de factura" << endl;
    cin >> nroFactura;

    system("cls");

    RegistroCompra objRegistroCompra;

    tam = objRegistroCompra.contarRegistros();

    DetalleFacturaCompra objDF;
    tamDetalleFactura = objDF.contarRegistros();

    bool cont = true;

    for (int i = 0; i < tam; i++)

    {

        objRegistroCompra = objRegistroCompra.leerRegistro(i);

        if (nroFactura == objRegistroCompra.getIdCompra())

        {
            for (int j = 0; j < tamDetalleFactura; j++)
            {
                objDF = objDF.leerRegistro(j);
                if (objDF.getIdCompra() == objRegistroCompra.getIdCompra())
                {





cout<<"tipo articulo: "<<objDF.getTipoDeArticulo();
system("pause");



                    switch (objDF.getTipoDeArticulo())
                    {

                    case 1:
                      objP = BuscarPlanta(objDF.getIdArticulo());

                        
                        // objH.Mostrar();
                        break;

                    case 2:
                      objH = BuscarHerramienta(objDF.getIdArticulo());

                        // objP.Mostrar();

                        break;

                    case 3:
                        // objA = BuscarAgroquimicos();
                        break;
                    default:
                        break;
                    }
                      if (cont)
            {
                cout << "Codigo Articulo "<< "Descripcion "<< "Precio " << "Cantidad "<< "SubTotal " << endl;
                cont = false;
            }
            if (objP.getEstado() == 1)
            {
                cout << objP.getID() << " " << objP.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
            }
            if (objH.getEstado() == 1)
            {
                cout << objH.getID() << " " << objH.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
            }
                }
            }

            //  Desarrollo del Mostrar

          
        }
    }
}
Planta BuscarPlanta(int idArticulo)
{

    Planta obj;
    int tam = obj.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        obj = obj.leerRegistroPlanta(i);

        if (obj.getID() == idArticulo)
        {

            return obj;
        }
    }
    obj.setEstado(-2);
    return obj;
}
Herramientas BuscarHerramienta(int idArticulo)
{

    Herramientas obj;
    int tam = obj.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        obj = obj.leerRegistroHerramienta(i);

        if (obj.getID() == idArticulo)
        {

            return obj;
        }
    }
    obj.setEstado(-2);
    return obj;
}

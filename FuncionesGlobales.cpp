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

void ArticulosXFactura(DetalleFacturaCompra objDF)
{
    Planta objP;
    Herramientas objH;
    Agroquimicos objA;
    switch (objDF.getTipoDeArticulo())
    {

    case 1:
        objP = BuscarPlanta(objDF.getIdArticulo());
        if (objP.getEstado() == 1)
        {
            cout << objP.getID() << " " << objP.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
        }
        // objH.Mostrar();
        break;

    case 2:
        objH = BuscarHerramienta(objDF.getIdArticulo());

        if (objH.getEstado() == 1)
        {
            cout << objH.getID() << " " << objH.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
        }
        // objP.Mostrar();

        break;

    case 3:
        // objA = BuscarAgroquimicos();
        break;
    default:
        break;
    }
}

void GenerarFactura(RegistroCompra objR, int id)
{
    int tam = 0;
    bool cont = true;
    DetalleFacturaCompra objD;
    tam = objD.contarRegistros();
    cout << "Numero de Factura: " << objR.getIdCompra() << endl;
    cout << "Fecha: ";
    objR.getFecha().MostrarEnLinea();
    cout << endl;

    cout << "CLIENTE ----------------" << endl;
    Cliente objC;
    int tam2 = objC.CONtarRegistros(); // Arreglar nombre de la funcion

    for (int i = 0; i < tam2; i++)
    {
        if (objC.LeerArchivo(i))
        {

            if (objC.getIDCliente() == id)
            {
                cout << "----------------" << endl;
                cout << "Nombre y Apellido: " << objC.getNombre() << "," << objC.getApellido() << endl;
                cout << "----------------" << endl;
            }
        }
    }
    cout << "----------------" << endl;
    cout << "Cabecera factura: " << endl;
    cout << "----------------" << endl;
    cout << "----------------" << endl;
    cout << "Metodo de Pago: " << objR.getModoDePago();
    cout << "----------------" << endl;

    cout << "Detalle Factura Compra ----------------" << endl;

    for (int i = 0; i < tam; i++)
    {
        objD = objD.leerRegistro(i);

        if (objD.getIdCompra() == objR.getIdCompra())
        {
            if (cont)
            {
                cout << "Codigo Articulo "
                     << "Descripcion "
                     << "Precio "
                     << "Cantidad "
                     << "SubTotal " << endl;
                cont = false;
            }
            ArticulosXFactura(objD);
        }
    }
}
void FacturaXNroFactura()
{

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

                    if (cont)
                    {
                        cout << "Codigo Articulo "
                             << "Descripcion "
                             << "Precio "
                             << "Cantidad "
                             << "SubTotal " << endl;
                        cont = false;
                    }
                    ArticulosXFactura(objDF);
                }

                //  Desarrollo del Mostrar
            }
        }
    }
    system("pause");
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
int BuscarPosicion(Planta obj)
{
    
    Planta aux;

    int tam = aux.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        aux=aux.leerRegistroPlanta(i);

        if (aux.getID() == obj.getID())
        {

            return i;
        }
    }
    return -1;
  
}
int BuscarPosicion(Herramientas obj)
{
    
Herramientas aux;

    int tam = aux.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        aux=aux.leerRegistroHerramienta(i);

        if (aux.getID() == obj.getID())
        {

            return i;
        }
    }
    return -1;
  
}
int BuscarPosicion(Agroquimicos obj)
{
    
    Agroquimicos aux;

    int tam = aux.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        aux=aux.leerRegistroAgroquimicos(i);

        if (aux.getID() == obj.getID())
        {

            return i;
        }
    }
    return -1;
  
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

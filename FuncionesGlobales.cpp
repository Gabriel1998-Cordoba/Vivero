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
            cout << objP.getID() << " " << objP.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() * objDF.getCantidad() << endl;
        }
        // objH.Mostrar();
        break;

    case 2:
        objH = BuscarHerramienta(objDF.getIdArticulo());

        if (objH.getEstado() == 1)
        {
            cout << objH.getID() << " " << objH.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() * objDF.getCantidad() << endl;
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
        aux = aux.leerRegistroPlanta(i);

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
        aux = aux.leerRegistroHerramienta(i);

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
        aux = aux.leerRegistroAgroquimicos(i);

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

void RecaudacionAnual(int AnioIngresado)
{

    int vecAnual[12] = {};

    // se hace toda la acumulacion dentro de vecAnual

    RegistroCompra objRegistroCompra;

    int tam = objRegistroCompra.contarRegistros();

    for (int j = 0; j < tam; j++)
    {
        objRegistroCompra = objRegistroCompra.leerRegistro(j);

        if (AnioIngresado == objRegistroCompra.getFecha().getAnio())
        {
            int mes = objRegistroCompra.getFecha().getMes();

            for (int i = 1; i <= 12; i++)
            {
                if (mes == i)
                {

                    int importe = BuscarPrecioCompra(objRegistroCompra.getIdCompra());

                    if (importe > 0)
                    {
                        vecAnual[i - 1] = vecAnual[i - 1] + importe;
                    }
                }
            }
        }
    }
    // el resto del calculo

    int acum = 0;

    for (int i = 0; i < 12; i++)
    {
        acum = acum + vecAnual[i];
    }

    if (acum == 0)
    {
        cout << "no hubo nada de plata en este anio" << endl;
    }
    else
    {
        cout << "el total de plata anual fue = " << acum << endl;
    }
}

float BuscarPrecioCompra(int idCompra)
{

    DetalleFacturaCompra detalleFacturaCompra;
    int tam = detalleFacturaCompra.contarRegistros();

    for (int i = 0; i < tam; i++)
    {

        detalleFacturaCompra = detalleFacturaCompra.leerRegistro(i);

        if (idCompra == detalleFacturaCompra.getIdCompra())
        {
            return detalleFacturaCompra.getCantidad() * detalleFacturaCompra.getPrecio();
        }
    }

    return -1;
}

void RecaudacionMensual(int mesIngresado)
{

    int AcumMes = 0;

    RegistroCompra objRegistroCompra;

    int tam = objRegistroCompra.contarRegistros();

    for (int j = 0; j < tam; j++)
    {
        objRegistroCompra = objRegistroCompra.leerRegistro(j);

        if (mesIngresado == objRegistroCompra.getFecha().getMes())
        {

            int importe = BuscarPrecioCompra(objRegistroCompra.getIdCompra());

            if (importe > 0)
            {
                AcumMes += importe;
            }
        }
    }

    cout << "El Mes: " << mesIngresado << " ,a recaudado: " << AcumMes << " pesos" << endl;
    return;
}
int buscarMaximo(int *v, int tam)
{

    int max = 0;
    int pos = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
            pos = i;
        }
    }
    return pos;
}
Agroquimicos BuscarAgroquimicos(int idArticulo)
{
    Agroquimicos obj;
    int tam = obj.contarRegistros();

    for (int i = 0; i < tam; i++)
    {
        obj = obj.leerRegistroAgroquimicos(i);

        if (obj.getID() == idArticulo)
        {

            return obj;
        }
    }
    obj.setEstado(-2);
    return obj;
}

Cliente buscarCliente(int idCliente)
{
    Cliente obj;
    int tam = obj.CONtarRegistros();

    for (int i = 0; i < tam; i++)
    {
        obj = obj.leerRegistros(i);

        if (obj.getIDCliente() == idCliente)
        {

            return obj;
        }
    }
    obj.setEstado(-2);
    return obj;
}

void ponerEnCeroVector(int *v, int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        v[i] = 0;
    }
}
void cargarVectordeAcumulacion(int *v, Cliente objCliente)
{
    RegistroCompra objRCompra;

    int tamRegRCompra = objRCompra.contarRegistros();

    for (int i = 0; i < tamRegRCompra; i++)
    {
        objRCompra = objRCompra.leerRegistro(i);

        if (objRCompra.getIdCliente() == objCliente.getIDCliente())
        {
            v[objCliente.getIDCliente() - 1] += 1;
        }
    }
}

int ContadorDeCliente(int idCliente)
{
    RegistroCompra objRCompra;
    int cont = 0;

    int tamRegRCompra = objRCompra.contarRegistros();

    for (int i = 0; i < tamRegRCompra; i++)
    {
        objRCompra = objRCompra.leerRegistro(i);

        if (idCliente == objRCompra.getIdCliente())
        {
            cont++;
        }
    }

    return cont;
}
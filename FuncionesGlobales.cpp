#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
#include "FuncionesGlobales.h"
// #include "Cliente.h"
// #include "Duenio.h"

// int EsUnNumeroYConvierteEnNumero(const char* texto, int hasta){


//     bool band=false;
//     string iComoCadena1;

//     int numeroInt;

//     for(int i=0; i<=hasta; i++){

//         iComoCadena1 = to_string(i);

//         if(strcmp(texto,iComoCadena1.c_str()) == 0){
//             band=true;
//         }

//     }


//     if(band==true){

//         numeroInt = atoi(texto);

//         return numeroInt;
//     }else{
//         return -1;
//     }

// }
float EsUnNumeroYConvierteEnNumero(const char* texto){
    char* end;
    float numeroFloat = std::strtof(texto, &end);

    if (end != texto) { // Si se pudo convertir a float
        return numeroFloat;
    } else { // Si no se pudo convertir a float
        return -1;
    }
}



int EsUnNumero(const char* texto, int hasta){


    bool band=false;
    string iComoCadena1;

    for(int i=0; i<=hasta; i++){

        iComoCadena1 = to_string(i);

        if(strcmp(texto,iComoCadena1.c_str()) == 0){
            band=true;
        }

    }

    // for(int i=-1; i<=-1000; i--){

    //     string iComoCadena2 = to_string(i);

    //     if(strcmp(texto,iComoCadena2.c_str()) == 0){
    //         band=true;
    //     }

    // }



    if(band==true){

        return true;
    }else{
        return false;
    }

}

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
             << endl
             << endl
             << endl
             << endl;
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        cout << endl
             << endl
             << endl
             << endl
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
            printf("%-20d%-15s%-15.1f%-15d%-15.1f\n", objP.getID(), objP.getNombre(), objDF.getPrecio(), objDF.getCantidad(), objDF.getPrecio() * objDF.getCantidad());

            //    cout<< right<<setw(15)<< objP.getID() <<left<<setw(15)<< objP.getNombre() <<setw(20)<< objDF.getPrecio() <<setw(15)<< objDF.getCantidad() <<setw(15)<< objDF.getPrecio() * objDF.getCantidad() << endl;        }
            // objH.Mostrar();
            break;

        case 2:
            objH = BuscarHerramienta(objDF.getIdArticulo());

            if (objH.getEstado() == 1)
            {
                printf("%-20d%-15s%-15.1f%-15d%-15.1f\n", objH.getID(), objH.getNombre(), objDF.getPrecio(), objDF.getCantidad(), objDF.getPrecio() * objDF.getCantidad());
                // cout<< right<<setw(15)<< objH.getID() <<left<<setw(15)<< objH.getNombre() <<setw(20)<< objDF.getPrecio() <<setw(15)<< objDF.getCantidad() <<setw(15)<< objDF.getPrecio() * objDF.getCantidad() << endl;
            }
            // objP.Mostrar();

            break;

        case 3:
            objA = BuscarAgroquimicos(objDF.getIdArticulo());
            if (objA.getEstado() == 1)
            {
                printf("%-20d%-15s%-15.1f%-15d%-15.1f\n", objA.getID(), objA.getNombre(), objDF.getPrecio(), objDF.getCantidad(), objDF.getPrecio() * objDF.getCantidad());
                // cout<< right<<setw(15)<< objH.getID() <<left<<setw(15)<< objH.getNombre() <<setw(20)<< objDF.getPrecio() <<setw(15)<< objDF.getCantidad() <<setw(15)<< objDF.getPrecio() * objDF.getCantidad() << endl;
            }
            break;
        default:

            break;
        }
    }
}

void GenerarFactura(RegistroCompra objR)
{
    SaltoDeLinea();
    system("cls");
    int tam = 0, total = 0;
    bool cont = true;
    DetalleFacturaCompra objD;
    tam = objD.contarRegistros();
    cout << "Numero de Factura: " << objR.getIdCompra() << endl;
    cout << "Fecha: ";
    objR.getFecha().MostrarEnLinea();
    cout << endl;

    cout << "CLIENTE " << endl;
    Cliente objC;
    int tam2 = objC.CONtarRegistros(); // Arreglar nombre de la funcion

    for (int i = 0; i < tam2; i++)
    {
        if (objC.LeerArchivo(i))
        {

            if (objC.getIDCliente() == objR.getIdCliente())
            {
                cout << "----------------" << endl;
                cout << "Nombre y Apellido: " << objC.getNombre() << "," << objC.getApellido() << endl;
                cout << "----------------" << endl;
            }
        }
    }
    cout << "----------------" << endl;
    cout << "Metodo de Pago: " << objR.getModoDePago() << endl;
    cout << "----------------" << endl;

    cout << "Detalle Factura Compra " << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < tam; i++)
    {
        objD = objD.leerRegistro(i);

        if (objD.getIdCompra() == objR.getIdCompra())
        {
            if (cont)
            {
                printf("%-20s%-15s%-15s%-15s%-15s\n", "Codigo Articulo", "Descripcion", "Precio", "Cantidad", "SubTotal");

                cont = false;
            }
            ArticulosXFactura(objD);
            total += objD.getPrecio() * objD.getCantidad();
        }
    }
    cout << "----------------" << endl;
    cout << "TOTAL: " << total << endl;
    cout << "----------------" << endl;
}
void FacturaXNroFactura()
{

    int tam, tamDetalleFactura;

    int nroFactura, total = 0;
    cout << "ingrese numero de factura" << endl;
    cin >> nroFactura;

    SaltoDeLinea();
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
            GenerarFactura(objRegistroCompra);
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
void ponerEnCeroVector(bool *v, int tamanio)
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

bool AnioBisiesto(int anio)
{

    if (anio % 4 == 0 && ((anio % 100 != 0) | (anio % 400 == 0)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool prueba(int _dia, int _mes, int _anio)
{

    // echo por chat gpt

    if (_mes == 2)
    {
        if (AnioBisiesto(_anio))
        {
            if ((_dia < 1) || (_dia > 29))
            {
                cout << "ERROR --> Fuera de rango" << endl;
                cout << "vuelva a ingresar el dia" << endl;
                system("pause");
                return false;
            }
        }
        else
        {
            if ((_dia < 1) || (_dia > 28))
            {
                cout << "ERROR --> Fuera de rango" << endl;
                cout << "vuelva a ingresar el dia" << endl;
                system("pause");
                return false;
            }
        }
    }

    return true;
}

bool existeDNI(int indice, int numero)
{
    Cliente objC;

    int tam = objC.CONtarRegistros();

    for (int i = 0; i < tam; i++)
    {
        objC = objC.leerRegistros(i);

        if ((objC.getTipoDoc().getTipoDocu(indice - 1) == numero) && (indice == objC.getTipoDoc().getIndice()))
        {
            return true;
        }
    }

    return false;
}

void MostrarMaximo(int *vP, int indiceP, int *vH, int indiceH, int *vA, int indiceA)
{
    Planta objP;
    Herramientas objH;
    Agroquimicos objA;
    
    int max1 = vP[indiceP];
    int maxPrime = max1;
    int indicePrime = indiceP;
    int max2 = vH[indiceH];
    int max3 = vA[indiceH];

    if (max2 > maxPrime)
    {

        maxPrime = max2;
        indicePrime = indiceH;

        if (max3 > maxPrime)
        {

            maxPrime = max3;
            indicePrime = indiceA;

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
        indicePrime = indiceA;
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
        int indicePrime = indiceP;
        objP = BuscarPlanta(indicePrime + 1);
        cout << "El Producto mas vendido es: " << endl;
        cout << "----------------------------" << endl;
        objP.Mostrar();
        cout << "----------------------------" << endl;
        cout << "con un maximo de ventas de : " << maxPrime << endl;
        system("pause");
    }
}

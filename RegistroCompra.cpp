#include <iostream>
#include <cstring>
using namespace std;
#include "FuncionesGlobales.h"
#include "RegistroCompra.h"

void RegistroCompra::setIdCompra(int idcompra)
{
    _idCompra = idcompra;
}
void RegistroCompra::setIdCliente(int idcliente)
{

    _idCliente = idcliente;
}
void RegistroCompra::setFecha(Fecha fechita)
{
    _Fecha = fechita;
}
void RegistroCompra::setFecha(int dia, int mes, int anio)
{
    _Fecha.setDia(dia);
    _Fecha.setMes(mes);
    _Fecha.setAnio(anio);
}
void RegistroCompra::setModoDePago(const char *modoDePago)
{
    strcpy(_modoDePago, modoDePago);
}
int RegistroCompra::getIdCompra() { return _idCompra; }
int RegistroCompra::getIdCliente() { return _idCliente; }
Fecha RegistroCompra::getFecha() { return _Fecha; }
const char *RegistroCompra::getModoDePago() { return _modoDePago; }

void RegistroCompra::CargarCompra(RegistroCompra objR ,int idcliente) // Desarrollar int idcompra,int idcliente
{
    // if(Existe()) A DESARROLLAR, NO PODEMOS TENER IDS REPETIDOS AL GUARDAR ARCHIVO
    setIdCompra(objR.getIdCompra());
    
    setIdCliente(idcliente);
    Fecha f;
    char modoDePago[30];
    cout << "Cargar los siguientes datos: " << endl;
    cout << "Fecha: " << endl;
    f.Cargar();
    setFecha(f);

    int band = false;
    do
    {
        cout << "Ingrese los siguentes metodos de pago: efectivo,debido,credito :" << endl;
        cargarCadena(modoDePago, 30);
        strlwr(modoDePago);

        if (strcmp(modoDePago, "efectivo") == 0 || strcmp(modoDePago, "debito") == 0 || strcmp(modoDePago, "credito") == 0)
        {
            band = true;
        }
        else
        {
            cout << "El Modo De Pago: " << modoDePago << endl;
            cout << "Ingresado no existe, vuelva a ingresar" << endl
                 << endl;
        }

    } while (band == false);

    setModoDePago(modoDePago);
    system("pause");
}

void RegistroCompra::Mostrar()
{
    cout << "ID COMPRA: " << getIdCompra() + 1 << endl;
    cout << "ID PROVEEDOR: " << getIdCliente() + 1 << endl;
    _Fecha.MostrarEnLinea();
    cout << "MODO DE PAGO: " << getModoDePago() << endl
         << endl;

    // int indice = getSujeto().getTipoDoc().getIndice();
    // cout<<"Tipo Documento "<<indice<<" : "<<getSujeto().getTipoDoc().getTipoDocu(indice)<<endl;
}

int RegistroCompra::contarRegistros(const char * nombre)
{
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
        return -1; //cambie el 0 por un -1, por si no ahi ningun registro me devuelva -1
                   //Fijate gabi si esto no afecta a otra parte del programa
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(RegistroCompra);
}

bool RegistroCompra::GuardarCompra()
{
    FILE *p;
    // RegistroCompra ClassM;Se activa el guardado del archivo cuando el obj  llama al metodo

    p = fopen("registrocompra.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
        return false;
    }
    // ClassM.CargarCompra();

    bool escribio = fwrite(/*&ClassM*/ this, sizeof(RegistroCompra), 1, p);

    fclose(p);
    return escribio;
}

void RegistroCompra::MostrarArchivoCompra()
{
    RegistroCompra ClassM;
    FILE *p;

    p = fopen("registrocompra.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    while (fread(&ClassM, sizeof(RegistroCompra), 1, p) == 1)
    {
        ClassM.Mostrar();
    }

    fclose(p);
}
void RegistroCompra::CargarDatosRegistroCompraEnArchivo(RegistroCompra objR ,int idcliente){

    FILE *p;
    RegistroCompra obj;
    p = fopen("registrocompra.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    obj.CargarCompra(objR,idcliente);
    fwrite(&obj, sizeof(RegistroCompra), 1, p);

    fclose(p);

}

RegistroCompra RegistroCompra::leerRegistro(int pos,const char * nombre)
{
    RegistroCompra reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
        return reg;
    fseek(p, sizeof(RegistroCompra) * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

// RegistroCompra RegistroCompra::LeerRegistrosPorIdCompra(int IdCompra){
//     RegistroCompra reg;
//     FILE *p;
//     p=fopen("registrocompra.dat", "rb");
//     if(p==NULL){
//         cout<<"NO PUDO LEERLO : RegistroCompra RegistroCompra::LeerRegistrosPorIdCompra(int IdCompra)"<<endl;
//          return reg;
//     }
//     while(fread(&reg, sizeof reg,1, p)){
//         if(reg.getIdCompra() == IdCompra){
//             fclose(p);
//             return reg;
//         }
//     }
//     fclose(p);
//     return reg;
// }
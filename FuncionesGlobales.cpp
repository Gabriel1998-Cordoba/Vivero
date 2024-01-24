#include<iostream>
using namespace std;
#include"FuncionesGlobales.h"


void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

void SaltoDeLinea(int tam){
for(int i=0;i<tam;i++){
    cout<<endl<<endl<<endl<<endl;
}
}

void GenerarFactura(RegistroCompra objR,int id){
    int tam=0;
    DetalleFacturaCompra objD;
    tam = objD.contarRegistros();

    Cliente objC;
    int tam2=0;
    tam2 = objC.CONtarRegistros();

    cout<<"CLIENTE ----------------"<<endl;

    for(int i=0;i<tam2;i++){
        objC = objC.leerRegistros(i);

        if(objC.getIDCliente() == id){
            cout<<"----------------"<<endl;
            objC.Mostrar();
            cout<<"----------------"<<endl;
        }
    }

    
    cout<<"Cabecera factura ----------------"<<endl;

    cout<<"----------------"<<endl;
    objR.Mostrar();
    cout<<"----------------"<<endl;

    cout<<"Detalle Factura Compra ----------------"<<endl;

    for(int i=0;i<tam;i++){
        objD = objD.leerRegistro(i);

        if(objD.getIdCompra() == objR.getIdCompra()){

        objD.Mostrar();

        }
    }

}

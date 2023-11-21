#include<iostream>
#include <cstring>

using namespace std;

#include"Planta.h"
#include"FuncionesGlobales.h"
#include"Articulo.h"
#include"DetalleFacturaCompra.h"

const char * Planta::getEstacion()
{
    return _estacion;
}

void Planta::setEstacion(const char *estacion)
{
    strcpy(_estacion, estacion);
}

void Planta::CargarArchivoPlanta(int totalDeRegistros,int TipoDeArticulo){ //ab
FILE *p;
Planta ClassM;

p=fopen("planta.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarPlanta(totalDeRegistros,TipoDeArticulo);
fwrite(&ClassM,sizeof (Planta),1,p);


fclose(p);
}

void Planta::CargarPlanta(int totalDeRegistros,int TipoDeArticulo){

    Articulo::Cargar(totalDeRegistros,TipoDeArticulo);
    
    char estacion[30];

    cout << "Ingrese Estacion = ";
    cargarCadena(estacion,30);
    setEstacion(estacion);
    cout<<endl;
}

void Planta::MostrarPlanta()
{
 Articulo::Mostrar();
 cout<<"Estacion: "<<getEstacion()<<endl<<endl;

}

int Planta::contarRegistros(){
        FILE *p;
        p=fopen("planta.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Planta);
    }

bool Planta::borrarRegistroPlanta(){
    FILE *p;
    p=fopen("planta.dat", "wb");
    if(p==nullptr){ return false;}
    fclose(p);
    return true;
}

Planta Planta::leerRegistroPlanta(int pos){
   Planta reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen("planta.dat", "rb");
    if(p==NULL){
     cout<<"Error = Planta Planta::leerRegistroPlanta(int pos)"<<endl;
     return reg;
    }
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

void Planta::ListarPlanta(){

// Planta ClassP;
// int tam=ClassP.contarRegistros();

// //cout<<"TAM= "<<tam<<endl;

// for(int i=0; i<tam;i++){
//     ClassP.leerRegistroPlanta(i);
    // ClassP.MostrarPlanta();
// }

Planta ClassM;
FILE *p;

p=fopen("planta.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Planta),1,p)==1){
ClassM.MostrarPlanta();
}

fclose(p);

}

bool Planta::reemplazarRegistroPlanta(Planta reg, int posicionAReemplazar){
    FILE *p = fopen("planta.dat", "rb+");
    if (p == NULL){return false;}
    fseek(p, posicionAReemplazar * sizeof(Planta), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Planta), 1, p);
    fclose(p);
    return pudoEscribir;
}

void Planta::Opcion1Compra(){
    Planta objT;

    int tam=0;
    tam = objT.contarRegistros();

    for(int i=0; i<tam; i++){
        objT = objT.leerRegistroPlanta(i);
        cout<<"Planta: "<<objT.getNombre()<<endl;
        cout<<"Precio: "<<objT.getPrecio()<<endl;
        cout<<"Stock: "<<objT.getStock()<<endl<<endl;
        
        cout<<"//////////////////////////"<<endl<<endl;

    }

}
void Planta::Opcion2Compra(){


    Planta objT;

    int tam=0;
    bool Encontro=false;
    tam = objT.contarRegistros();

    char nombrePlanta[30];
    cout<<"Ingrese Nombre:"<<endl;
    cargarCadena(nombrePlanta,30);

    for(int i=0; i<tam; i++){

        objT = objT.leerRegistroPlanta(i);

        if(strcmp(nombrePlanta,objT.getNombre())==0){
            Encontro=true;
        cout<<"//////////////////////////"<<endl;
            cout<<"Nombre: "<<objT.getNombre()<<endl;
            cout<<"Precio: "<<objT.getPrecio()<<endl;
            cout<<"Stock: "<<objT.getStock()<<endl;
        cout<<"//////////////////////////"<<endl<<endl;
        }
    }

    if(Encontro==false){
    cout<<"PLANTA INGRESADA, no fue encontrada"<<endl;
    }
}
void Planta::Opcion3Compra(){

    Planta objP;
    int tam=0,stock,calc=0;
    bool Encontro=false;
    tam = objP.contarRegistros();

    char nombrePlanta[30];
    cout<<"Ingrese Nombre:"<<endl;
    cargarCadena(nombrePlanta,30);
    cout<<"Ingrese Cuanto Stock quiere Comprar:"<<endl;
    cin>>stock;

    for(int i=0; i<tam; i++){

        objP = objP.leerRegistroPlanta(i);

        if(strcmp(nombrePlanta,objP.getNombre())==0){
            Encontro=true;
        cout<<"//////////////////////////"<<endl;
            cout<<"Nombre: "<<objP.getNombre()<<endl;
            cout<<"Precio por Unidad: "<<objP.getPrecio()<<endl;
            cout<<"TOTAL Stock: "<<objP.getStock()<<endl;
        cout<<"//////////////////////////"<<endl;
            cout<<"COMPRA REALIZADA: "<<endl;
            cout<<"Nombre: "<<objP.getNombre()<<endl;
            cout<<"Precio TOTAL: "<<(objP.getPrecio()*stock)<<endl;
            calc=objP.getStock();
            calc=calc-stock;
            
                if(calc>=0){
                        objP.setStock(calc);
                        cout<<"Disponible Stock: "<<objP.getStock()<<endl;
                        cout<<"//////////////////////////"<<endl<<endl;
                        //REMPLAZAR STOCK
                        objP.reemplazarRegistroPlanta(objP,i);
                        //SE GUARDA EN LA FACTURA
                        DetalleFacturaCompra objD;
                        objD.AutoCargar(objP);
                }else{
                        cout<<"LA COMPRA no se pudo realizar ya que no tenemos el suficiente STOCK"<<endl;
                        cout<<"//////////////////////////"<<endl<<endl;
                }
        }
    }

    if(Encontro==false){
    cout<<"PLANTA INGRESADA, no fue encontrada"<<endl;
    }

}

#include<iostream>
#include <cstring>

using namespace std;

#include"Agroquimicos.h"
#include"FuncionesGlobales.h"
#include"Articulo.h"
#include"DetalleFacturaCompra.h"

/***************************************************************/
void Agroquimicos::setTipoAgroquimico(int tipoAgroquimico){
    _tipoAgroquimico=tipoAgroquimico;
}
/***************************************************************/
int Agroquimicos::getTipoAgroquimico(){
    return _tipoAgroquimico;
}
/***************************************************************/
void Agroquimicos::CargarArchivoAgroquimicos(int totalDeRegistros,int TipoDeArticulo){
FILE *p;
Agroquimicos ClassM;

p=fopen("agroquimicos.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.CargarAgroquimicos(totalDeRegistros,TipoDeArticulo);
fwrite(&ClassM,sizeof (Agroquimicos),1,p);


fclose(p);
}

void Agroquimicos::CargarAgroquimicos(int totalDeRegistros,int TipoDeArticulo){
    Articulo::Cargar(totalDeRegistros,TipoDeArticulo);

int tipoAgroquimico=0;


    do{
        cout<<"Agroquimico 1 == Ecologico"<<endl;
        cout<<"Agroquimico 2 == Quimico"<<endl<<endl;

        cout<<"Ingrese tipo Agroquimico"<<endl;
        cin>>tipoAgroquimico;
        if((tipoAgroquimico!=1)&&(tipoAgroquimico!=2)){
            cout<<"El valor ingresado en tipo Agroquimico no existe"<<endl;
        }else{
            setTipoAgroquimico(tipoAgroquimico);
        }

    }while((tipoAgroquimico!=1)&&(tipoAgroquimico!=2));

}

void Agroquimicos::MostrarAgroquimicos()
{
 Articulo::Mostrar();
 cout<<"Agroquimico: "<<getTipoAgroquimico()<<endl;
 cout<<endl;

}

int Agroquimicos::contarRegistros(){
        FILE *p;
        p=fopen("agroquimicos.dat", "rb");
        if(p==NULL) return 0;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Agroquimicos);
    }

bool Agroquimicos::borrarRegistroAgroquimicos(){
    FILE *p;
    p=fopen("agroquimicos.dat", "wb");
    if(p==nullptr){ return false;}
    fclose(p);
    return true;
}

Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos){
   Agroquimicos reg;
    reg.setEstado(false);
    FILE *p;
    p=fopen("agroquimicos.dat", "rb");
    if(p==NULL){
     cout<<"Error = Agroquimicos Agroquimicos::leerRegistroAgroquimicos(int pos)"<<endl;
     return reg;
    }
    fseek(p, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

void Agroquimicos::ListarAgroquimicos(){



Agroquimicos ClassM;
FILE *p;

p=fopen("agroquimicos.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Agroquimicos),1,p)==1){
ClassM.MostrarAgroquimicos();
}

fclose(p);

}

void Agroquimicos::Opcion1Compra(){
    Agroquimicos objT;

    int tam=0;
    tam = objT.contarRegistros();

    for(int i=0; i<tam; i++){
        objT = objT.leerRegistroAgroquimicos(i);
        cout<<"Agroquimicos: "<<objT.getNombre()<<endl;
        cout<<"Precio: "<<objT.getPrecio()<<endl;
        cout<<"Stock: "<<objT.getStock()<<endl<<endl;
        
        cout<<"//////////////////////////"<<endl<<endl;

    }

}
void Agroquimicos::Opcion2Compra(){


    Agroquimicos objT;

    int tam=0;
    bool Encontro=false;
    tam = objT.contarRegistros();

    char nombreAgroquimicos[30];
    cout<<"Ingrese Nombre:"<<endl;
    cargarCadena(nombreAgroquimicos,30);

    for(int i=0; i<tam; i++){

        objT = objT.leerRegistroAgroquimicos(i);

        if(strcmp(nombreAgroquimicos,objT.getNombre())==0){
            Encontro=true;
        cout<<"//////////////////////////"<<endl;
            cout<<"Nombre: "<<objT.getNombre()<<endl;
            cout<<"Precio: "<<objT.getPrecio()<<endl;
            cout<<"Stock: "<<objT.getStock()<<endl;
        cout<<"//////////////////////////"<<endl<<endl;
        }
    }

    if(Encontro==false){
    cout<<"Agroquimico INGRESADO, no fue encontrada"<<endl;
    }
}
void Agroquimicos::Opcion3Compra(int idCompra){
    
    char nombreP[30];
    int tam = 0;
    DetalleFacturaCompra descripcionFactura;
    Planta reg, aux;
    tam = reg.contarRegistros();

    cout << "Ingrese Nombre de la Planta: ";
    cargarCadena(nombreP, 30);
    for (int i = 0; i < tam; i++)
    {
        aux = reg.leerRegistroPlanta(i);
        if (strcmp(aux.getNombre(), nombreP) == 0)
        {
            if (descripcionFactura.AutoCargar(idCompra, aux.getID(), aux.getPrecio()) == true)
            {
                if (descripcionFactura.GuardarEnArchivo())
                {
                    cout << "Guardado Correctamente ";
                    system("pause");
                    return;
                }
            }
        }
    }


}
void Agroquimicos::Opcion4Compra(int idCompra){
DetalleFacturaCompra objD;

//objD.MostrarAutoCargarAgroquimicos(idCompra);

}
// void Agroquimicos::Opcion4Compra(){
    
// }
// void Agroquimicos::Opcion5Compra(){
    
// }
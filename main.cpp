#include <iostream>

using namespace std;

#include "RegistroCompra.h"
#include "DetalleFacturaCompra.h"
#include "Cliente.h"
#include "menu.h"

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

void FacturaXNroFactura()
{
  Planta objP;
  Herramientas objH;
  Agroquimicos objA;
  
  int nroFactura;
  cout << "ingrese numero de factura" << endl;
  cin >> nroFactura;
  system("cls");
  FILE *p;
  p = fopen("DetalleFacturaCompra.dat", "rb");

  if (p == NULL)
  {
    return ;
  }

  DetalleFacturaCompra objDF;

  int tam;

  tam = objDF.contarRegistros();
 bool cont=true;

  for (int i = 0; i < tam; i++)

  {

    if (objDF.leerRegistroIdCompra(i))
    {

      if (nroFactura == objDF.getIdCompra())

      {
        
cout<<objDF.getTipoDeArticulo();

        switch (objDF.getTipoDeArticulo())
        {
        

        case 1:
         
          // if (objP.getEstado()==-2)
          // {
            
          // }
            break;

        case 2:
         objP = BuscarPlanta(objDF.getIdArticulo());

         //objP.Mostrar();
        //  objH = BuscarHerramienta();
          break;

        case 3:
          //objA = BuscarAgroquimicos();
          break;
        default:
          break;
        }
//Desarrollo del Mostrar
        
        if(cont)
        {
          cout<<"Codigo Articulo "<<"Descripcion "<<"Precio "<<"Cantidad "<<"SubTotal "<<endl;
        cont=false;
        }
        if(objP.getEstado()== 1)
        {
          cout<<objP.getID()<<" "<<objP.getNombre()<<" "<<objDF.getPrecio()<<" "<<objDF.getCantidad()<<" "<<objDF.getPrecio()+objDF.getCantidad()<<endl;
        }
      }







    }
  }
}


int main()
{
  
   menuPrincipal();

  

  return 0;
}
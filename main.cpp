#include <iostream>

using namespace std;

#include "RegistroCompra.h"
#include "DetalleFacturaCompra.h"
#include "Cliente.h"
#include "menu.h"
#include "Duenio.h"
#include "bkpDuenio.h"
#include "Planta.h"
#include "bkpPlanta.h"

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
    return;
  }

  DetalleFacturaCompra objDF;

  int tam;

  tam = objDF.contarRegistros();
  bool cont = true;

  for (int i = 0; i < tam; i++)

  {

    if (objDF.leerRegistroIdCompra(i))
    {

      if (nroFactura == objDF.getIdCompra())

      {

        cout << objDF.getTipoDeArticulo();

        switch (objDF.getTipoDeArticulo())
        {

        case 1:

          objH = BuscarHerramienta(objDF.getIdArticulo());
          break;

        case 2:
          objP = BuscarPlanta(objDF.getIdArticulo());

          // objP.Mostrar();
          //  objH = BuscarHerramienta();
          break;

        case 3:
          // objA = BuscarAgroquimicos();
          break;
        default:
          break;
        }
        // Desarrollo del Mostrar

        if (cont)
        {
          cout << "Codigo Articulo "
               << "Descripcion "
               << "Precio "
               << "Cantidad "
               << "SubTotal " << endl;
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
  }
}

int main()
{

  // menuPrincipal();

  //FacturaXNroFactura();

  Planta objP;
  bkpPlanta objbkpPlanta;


  objbkpPlanta.RestaurarBackup();
  objP.MostrarArchivoPlanta();

  cout << "//////////////////////"<<endl<<"backup creado"<<"//////////////////////"<<endl;

  //objbkpPlanta.MostrarBackup();

  return 0;
}
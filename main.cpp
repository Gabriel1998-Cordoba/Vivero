

#include"menu.h"
#include"RegistroCompra.h"
#include"bkpRegistroCompra.h"
#include"RegistroVenta.h"
#include"bkpRegistroVenta.h"

int main()
{

 menuPrincipal();

  //FacturaXNroFactura();

  //RegistroVenta objP;
  //bkpRegistroVenta objbkpPlanta;
  //
  //objbkpPlanta.RestaurarBackup();
//
  ////objP.CargarArchivoVenta();
  //objP.MostrarArchivoVenta();
//
  //cout << "//////////////////////"<<endl<<"backup creado"<<endl<<"//////////////////////"<<endl;
//
  ////objbkpPlanta.CrearBackup();
  //objbkpPlanta.MostrarBackup(); //o anda mal porque no muestra completo el archivo de respaldo





  return 0;
}





// Planta BuscarPlanta(int idArticulo)
// {

//   Planta obj;
//   int tam = obj.contarRegistros();

//   for (int i = 0; i < tam; i++)
//   {
//     obj = obj.leerRegistroPlanta(i);

//     if (obj.getID() == idArticulo)
//     {

//       return obj;
//     }
//   }
//   obj.setEstado(-2);
//   return obj;
// }
// Herramientas BuscarHerramienta(int idArticulo)
// {

//   Herramientas obj;
//   int tam = obj.contarRegistros();

//   for (int i = 0; i < tam; i++)
//   {
//     obj = obj.leerRegistroHerramienta(i);

//     if (obj.getID() == idArticulo)
//     {

//       return obj;
//     }
//   }
//   obj.setEstado(-2);
//   return obj;
// }

// void FacturaXNroFactura()
// {
//   Planta objP;
//   Herramientas objH;
//   Agroquimicos objA;

//   int nroFactura;
//   cout << "ingrese numero de factura" << endl;
//   cin >> nroFactura;
//   system("cls");
//   FILE *p;
//   p = fopen("DetalleFacturaCompra.dat", "rb");

//   if (p == NULL)
//   {
//     return;
//   }

//   DetalleFacturaCompra objDF;

//   int tam;

//   tam = objDF.contarRegistros();
//   bool cont = true;

//   for (int i = 0; i < tam; i++)

//   {

//     if (objDF.leerRegistroIdCompra(i))
//     {

//       if (nroFactura == objDF.getIdCompra())

//       {

//         cout << objDF.getTipoDeArticulo();

//         switch (objDF.getTipoDeArticulo())
//         {

//         case 1:

//           objH = BuscarHerramienta(objDF.getIdArticulo());
//           break;

//         case 2:
//           objP = BuscarPlanta(objDF.getIdArticulo());

//           objP.Mostrar();
//            objH = BuscarHerramienta();
//           break;

//         case 3:
//           objA = BuscarAgroquimicos();
//           break;
//         default:
//           break;
//         }
//         Desarrollo del Mostrar

//         if (cont)
//         {
//           cout << "Codigo Articulo "
//                << "Descripcion "
//                << "Precio "
//                << "Cantidad "
//                << "SubTotal " << endl;
//           cont = false;
//         }
//         if (objP.getEstado() == 1)
//         {
//           cout << objP.getID() << " " << objP.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
//         }
//         if (objH.getEstado() == 1)
//         {
//           cout << objH.getID() << " " << objH.getNombre() << " " << objDF.getPrecio() << " " << objDF.getCantidad() << " " << objDF.getPrecio() + objDF.getCantidad() << endl;
//         }
//       }
//     }
//   }
// }

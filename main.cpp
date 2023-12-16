#include <iostream>

using namespace std;

#include "RegistroCompra.h"
#include "DetalleFacturaCompra.h"
#include "Cliente.h"
#include "menu.h"

int main()
{
 //menuPrincipal();

  // DetalleFacturaCompra objD;

  // int tam = objD.contarRegistros();

  // for (int i = 0; i < tam; i++)
  // {

  //   objD = objD.leerRegistroIdCompra(i);
  //   objD.Mostrar();
  //   cout<<endl;
  // }
  //////////////////////////////////////////////////////////////////////////

  //     RegistroCompra objR;
  // while(true){

  //     objR.MostrarArchivoCompra();

  // system("pause");

  // system("cls");

  ///////////////////////////////////////////////////////////////////////

  // Cliente cli;
  // int pos=0;
  // while (cli.LeerArchivo(pos++))
  // {
  //    cli.Mostrar(); /* code */
  // }
  // cout<<"------"<<endl;
  // RegistroCompra regCom;
  // regCom.MostrarArchivoCompra();
  /*------------------------------------------------------------*/
  // Planta reg;
  // int tam = reg.contarRegistros();
  // for (int i = 0; i < tam; i++)
  // {
  //   reg = reg.leerRegistroPlanta(i);
  //   reg.MostrarPlanta();
  // }

  DetalleFacturaCompra objDdeFactura;

  int cont = 0, nroFactura;

  // cout<<"que tiene DetalleFacturaCompra"<<endl;
  //  objDdeFactura.leerRegistro(0);
  // objDdeFactura.Mostrar();

  cont = objDdeFactura.contarRegistros();
  // cout << "ingrese numero de factura que desea ver: " << endl;
  // cin >> nroFactura;

  for (int i = 0; i < cont; i++)
  {
    cout << "contador de registro: " << i<< endl;

    objDdeFactura.leerRegistroIdCompra(i);

    // if (nroFactura - 1 == objaux.getIdCompra())
    //{

    objDdeFactura.Mostrar();


    //      }

    cout << endl;
    //}
  }

  return 0;
}
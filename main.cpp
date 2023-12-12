#include <iostream>

using namespace std;

#include "RegistroCompra.h"
#include "DetalleFacturaCompra.h"
#include "Cliente.h"
#include "menu.h"

int main()
{
 //menuPrincipal();

  DetalleFacturaCompra objD;

  int tam = objD.contarRegistros();

  for (int i = 0; i < tam; i++)
  {

    objD = objD.leerRegistroIdCompra(i);
    objD.Mostrar();
    cout<<endl;
  }
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

  return 0;
}
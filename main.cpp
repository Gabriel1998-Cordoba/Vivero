#include <iostream>

using namespace std;


#include"RegistroCompra.h"
#include"DetalleFacturaCompra.h"
#include "Cliente.h"
#include"menu.h"

int main(){

   
  //  menuPrincipal();

//     RegistroCompra objR;
// while(true){

//     objR.MostrarArchivoCompra();


// system("pause");

// system("cls");
// 2
Cliente cli;
int pos=0;
while (cli.LeerArchivo(pos++))
{
   cli.Mostrar(); /* code */
}
cout<<"------"<<endl;
RegistroCompra regCom;
regCom.MostrarArchivoCompra();



//     return 0;
}
#include <iostream>

using namespace std;


#include"Duenio.h"
#include"menu.h"

int main(){

    //menuPrincipal();

    Duenio objT;
while(true){

    objT.CargarDuenio(0,1);

    cout<<"////////////////////////"<<endl;

    objT.MostrarDuenio();
system("pause");

system("cls");
}


    return 0;
}
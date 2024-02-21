#include <iostream>

using namespace std;

#include "Tipo_Docu.h"
#include "FuncionesGlobales.h"

void Tipo_Docu::CargarTipoDocu()
{

    int indice;
    int TipoDoc[3] = {0};
    int numero;
    bool band = true;

    do
    {

        cout << "SU Tipo Documento es: " << endl;
        cout << "1 - DNI, 2 - Cuit, 3 - Cuil" << endl;
        cin >> indice;

        cout << "Ingrese numero: ";
        cin >> numero;

        band = existeDNI(indice, numero);

        if (band == true)
        {
            cout << "el DNI o CUIT o CUIL ya esta ingresado y es de alguna persona," << endl
                 << "debe ingresar el suyo" << endl;
        }
        else
        {

            // cout << "indice: " << indice << endl;
            // cout << "numero: " << numero << endl;

            if (setTipoDocu(indice, numero) == false)
            {
                system("cls");
                cout << "Tipo de Documento No valido" << endl
                     << endl;
            }
        }

    } while ((setTipoDocu(indice, numero) == false) | (band == true));
}
void Tipo_Docu::MostrarTipoDocu()
{

    int valor = -1;

    for (int i = 0; i < 3; i++)
    {

        valor = getTipoDocu(i);

        if (valor > 0)
        {
            cout << "SU Tipo Documento es: " << i + 1;

            if (i == 0)
            {
                cout << " DNI" << endl;
                cout << "Su numero de documento es: " << valor << endl;
                return;
            }
            else if (i == 1)
            {
                cout << " Cuit" << endl;
                cout << "Su numero de documento es: " << valor << endl;
                return;
            }
            else if (i == 2)
            {
                cout << " Cuil" << endl;
                cout << "Su numero de documento es: " << valor << endl;
                return;
            }
        }
    }
}
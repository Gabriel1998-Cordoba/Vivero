#pragma once

class Tipo_Docu{

    private:
        int _TipoDoc[3]={-1}; //(1 DNI, 2 Cuit, 3 Cuil)
        int _indice=-1;
        int _numero;

    public:

bool setTipoDocu(int index, int value) {
if(index >= 0 && index <3) {
_TipoDoc[index] = value;
return true;
    } else {
        // Manejar el error de índice fuera de rango
     return false;
    }
}

    int getTipoDocu(int index) {
        if(index >= 0 && index < 3) {
            return _TipoDoc[index];
        } else {
            // Manejar el error de índice fuera de rango
            return -1;
        }
    }

    void setNumero(int numero) { _numero = numero; }
    int getNumero() const { return _numero; }
    
    void CargarTipoDocu();
    void MostrarTipoDocu();

    int getIndice() const { return _indice; }
    void setIndice(int indice) { _indice = indice;}
};
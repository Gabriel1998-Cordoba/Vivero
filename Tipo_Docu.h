#pragma once

class Tipo_Docu{

    private:
        int _TipoDoc[3]={0}; //(1 DNI, 2 Cuit, 3 Cuil)
        int _numero;

    public:

    bool setTipoDoc(int index, int value) {
        if(index >= 0 && index < 3) {
            _TipoDoc[index] = value;
            return true;
        } else {
            // Manejar el error de índice fuera de rango
            return false;
        }
    }

    int getTipoDoc(int index) {
        if(index >= 0 && index < 3) {
            return _TipoDoc[index];
        } else {
            // Manejar el error de índice fuera de rango
            return -1;
        }
    }

    int getNumero() const { return _numero; }
    void setNumero(int numero) { _numero = numero; }
    
    void CargarTipoDocu();
    void MostrarTipoDocu();
};
#pragma once
class DetalleFacturaCompra
{
private:
    int _idArticulo;
    int _idCompra;
    int _cantidad;
    float _precio;

public:
void setIdArticulo(int);
void setIdCompra(int);
void setCantidad(int );
void setPrecio(float);
int getIdArticulo();
int getIdCompra();
int getCantidad();
float getPrecio();
void Mostrar();

void AutoCargar();
};
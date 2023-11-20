#pragma once

class DetalleFacturaVenta{
    
private:

int _idVenta;
int _idArticulo;
int _cantidad;
float _precioUnitario;
float _subtotal;
float _precioTotal;

public:
int getIdVenta() const ;
void setIdVenta(int idVenta);

int getIdArticulo() const ;
void setIdArticulo(int ) ;

int getCantidad() const ;
void setCantidad(int ) ;

float getPrecioUnitario() const;
void setPrecioUnitario(float ) ;

float getSubtotal() const ;
void setSubtotal(float ) ;

float getPrecioTotal() const ;
void setPrecioTotal(float ) ;



};
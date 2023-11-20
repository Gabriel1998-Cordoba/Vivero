#include "DetalleFacturaVenta.h"

int DetalleFacturaVenta::getIdVenta() const { return _idVenta; }
void DetalleFacturaVenta::setIdVenta(int idVenta) { _idVenta = idVenta; }

int DetalleFacturaVenta::getIdArticulo() const { return _idArticulo; }

void DetalleFacturaVenta::setIdArticulo(int idArticulo) { _idArticulo = idArticulo; }

int DetalleFacturaVenta::getCantidad() const { return _cantidad; }
void DetalleFacturaVenta::setCantidad(int cantidad) { _cantidad = cantidad; }

float DetalleFacturaVenta::getPrecioUnitario() const { return _precioUnitario; }
void DetalleFacturaVenta::setPrecioUnitario(float precioUnitario) { _precioUnitario = precioUnitario; }

float DetalleFacturaVenta::getSubtotal() const { return _subtotal; }
void DetalleFacturaVenta::setSubtotal(float subtotal) { _subtotal = subtotal; }

float DetalleFacturaVenta::getPrecioTotal() const { return _precioTotal; }
void DetalleFacturaVenta::setPrecioTotal(float precioTotal) { _precioTotal = precioTotal; }
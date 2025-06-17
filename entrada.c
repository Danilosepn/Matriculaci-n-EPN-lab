#include <stdio.h>
#include <string.h>
#include "entrada.h"
#include "validaciones.h"

int obtenerDatosVehiculo(Vehiculo* v) {
    printf("Placa del vehiculo (3 letras + 4 digitos): ");
    scanf("%s", v->placa);
    if (!esPlacaValida(v->placa)) return 0;

    printf("Provincia: ");
    scanf("%s", v->provincia);
    if (!esNombreValido(v->provincia)) return 0;

    printf("Edad del propietario: ");
    if (scanf("%d", &v->edad) != 1 || v->edad <= 0) return 0;

    printf("Avaluo del vehiculo (USD): ");
    if (scanf("%f", &v->avaluo) != 1 || v->avaluo <= 0) return 0;

    printf("Cilindraje: ");
    if (scanf("%f", &v->cilindraje) != 1 || v->cilindraje <= 0) return 0;

    printf("Anio de fabricacion: ");
    if (scanf("%d", &v->anioFabricacion) != 1 || v->anioFabricacion < 1900 || v->anioFabricacion > 2025) return 0;

    return 1;
}
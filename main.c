#include <stdio.h>
#include "entrada.h"
#include "estructuras.h"

int main() {
    Vehiculo vehiculo;

    if (!obtenerDatosVehiculo(&vehiculo)) {
        printf("Proceso cancelado por datos invalidos.\n");
        return 1;
    }

    printf("\n--- Datos ingresados correctamente ---\n");
    printf("Placa: %s\n", vehiculo.placa);
    printf("Provincia: %s\n", vehiculo.provincia);
    printf("Edad del propietario: %d\n", vehiculo.edad);
    printf("Avaluo del vehiculo: %.2f\n", vehiculo.avaluo);
    printf("Cilindraje: %.1f\n", vehiculo.cilindraje);
    printf("Anio de fabricacion: %d\n", vehiculo.anioFabricacion);

    return 0;
}
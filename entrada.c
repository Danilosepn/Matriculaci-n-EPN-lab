#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "validaciones.h"

#define INTENTOS_MAX 3

int obtenerDatosVehiculo(Vehiculo* v) {
	int intentosRestantes;
	char buffer[50];
	
	// PLACA
	intentosRestantes = INTENTOS_MAX;
	while (intentosRestantes > 0) {
		system("cls");
		if (strlen(v->placa) > 0) {
		}
		printf("Placa del vehiculo (pba1234) (Intentos restantes: %d): ", intentosRestantes);
		scanf("%s", buffer); while (getchar() != '\n');
		if (esPlacaValida(buffer)) {
			strcpy(v->placa, buffer);
			break;
		}
		printf("Placa invalida.\n");
		intentosRestantes--;
	}
	if (intentosRestantes == 0) return 0;
	
	// EDAD
	intentosRestantes = INTENTOS_MAX;
	while (intentosRestantes > 0) {
		system("cls");
		printf("Placa: %s \n", v->placa);
		printf("Edad del propietario (Intentos restantes: %d): ", intentosRestantes);
		if (scanf("%d", &v->edad) == 1 && v->edad >= 18 && v->edad <= 85 ) {
			while (getchar() != '\n');
			break;
		}
		printf("Edad invalida. Debe ser mayor o igual a 18 anios y menor o igual a 85.\n");
		while (getchar() != '\n');
		intentosRestantes--;
	}
	if (intentosRestantes == 0) return 0;
	
	// AVALUO
	intentosRestantes = INTENTOS_MAX;
	while (intentosRestantes > 0) {
		system("cls");
		printf("Placa: %s | Edad: %d\n", v->placa, v->edad);
		printf("Avaluo del vehiculo (USD) (Intentos restantes: %d): ", intentosRestantes);
		if (scanf("%f", &v->avaluo) == 1 && v->avaluo > 0 && v->avaluo <= 10000000) {
			while (getchar() != '\n');
			break;
		}
		printf("Avaluo invalido. Debe ser un numero mayor a 0 y menor o igual a 10,000,000.\n");
		while (getchar() != '\n');
		intentosRestantes--;
	}
	if (intentosRestantes == 0) return 0;
	
	// CILINDRAJE
	intentosRestantes = INTENTOS_MAX;
	while (intentosRestantes > 0) {
		system("cls");
		printf("Placa: %s | Edad: %d | Avaluo: %.2f\n",
			   v->placa, v->edad, v->avaluo);
		printf("Cilindraje (Intentos restantes: %d): ", intentosRestantes);
		if (scanf("%f", &v->cilindraje) == 1 && v->cilindraje > 0) {
			while (getchar() != '\n');
			break;
		}
		printf("Cilindraje invalido.\n");
		while (getchar() != '\n');
		intentosRestantes--;
	}
	if (intentosRestantes == 0) return 0;
	
	// ANIO DE FABRICACION
	intentosRestantes = INTENTOS_MAX;
	while (intentosRestantes > 0) {
		system("cls");
		printf("Placa: %s | Edad: %d | Avaluo: %.2f | Cilindraje: %.1f\n",
			   v->placa, v->edad, v->avaluo, v->cilindraje);
		printf("Anio de fabricacion (Intentos restantes: %d): ", intentosRestantes);
		if (scanf("%d", &v->anioFabricacion) == 1 &&
			v->anioFabricacion >= 1900 && v->anioFabricacion <= 2025) {
			while (getchar() != '\n');
			break;
		}
		printf("Anio invalido.\n");
		while (getchar() != '\n');
		intentosRestantes--;
	}
	if (intentosRestantes == 0) return 0;
	
	return 1;
}

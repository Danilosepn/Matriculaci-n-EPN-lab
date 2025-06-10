#include <stdio.h>
#include <string.h>
#define HDN 15.0
#define PLACA_NUEVA 30.0
#define DESCUENTO_TERCERA_EDAD 0.5
#define RECARGO_MENSUAL 25.0


char placa[7], provincia[20];
int edad, anio_fabricacion, mes_actual;
int tiene_revision, necesita_placa;
int antiguedad, mes_placa, meses_retraso;

float avaluo, cilindraje;
float impuesto, sppat, hdn, rodaje, tasa_muni, multas;
float recargo, costo_placa, subtotal, total;

void menuEntrada() {
	printf("---------- BIENVENIDO AL SISTEMA DE MATRICULACION VEHICULAR ----------\n");
	printf("Este sistema permite calcular el valor total a pagar por matricula.\n");
	printf("Incluye:\n");
	printf("- Impuestos segun avaluo\n");
	printf("- Recargos por retraso\n");
	printf("- Descuentos por tercera edad\n");
	printf("- Verificacion de revision tecnica y multas\n");
	printf("------------------------------------------------------------------------\n\n");
}

void menuSalida() {
	printf("\n---------------- DETALLE DE MATRICULA ----------------\n");
	printf("Impuesto por avaluo: $%.2f\n", impuesto);
	printf("SPPAT: $%.2f\n", sppat);
	printf("Tasa HDN: $%.2f\n", hdn);
	printf("Rodaje provincial: $%.2f\n", rodaje);
	printf("Tasa municipal (%s): $%.2f\n", provincia, tasa_muni);
	printf("Multas: $%.2f\n", multas);
	printf("Recargo por %d mes(es) de retraso: $%.2f\n", meses_retraso, recargo);
	if (necesita_placa)
		printf("Costo por placas nuevas: $%.2f\n", costo_placa);
	if (edad >= 65)
		printf("Descuento tercera edad aplicado: -%.0f%%\n", DESCUENTO_TERCERA_EDAD * 100);
	printf("TOTAL A PAGAR: $%.2f\n", total);
	printf("------------------------------------------------------------------------------\n");
}

int obtener_mes_digito(char digito) {
	switch (digito) {
	case '1': return 2;
	case '2': return 3;
	case '3': return 4;
	case '4': return 5;
	case '5': return 6;
	case '6': return 7;
	case '7': return 8;
	case '8': return 9;
	case '9': return 10;
	case '0': return 11;
	default: return 1; 
	}
}

int calcular_meses_retraso(int actual, int permitido) {
	return (actual > permitido) ? actual - permitido : 0;
}

float calcular_impuesto_vehiculo(float val) {
	return val * 0.01;
}

float calcular_sppat(int cil, int edad_auto) {
	if (cil < 1500) return 30.0;
	else if (cil < 2500) return 50.0;
	else return 70.0 + (edad_auto * 2);
}

float calcular_rodaje_provincial(int cil) {
	return cil * 0.02;
}

float calcular_tasa_municipal(char prov[]) {
	if (strcmp(prov, "Guayas") == 0)
		return 20.0;
	else
		return 10.0;
}

void calcularTotal() {
	antiguedad = 2025 - anio_fabricacion;
	mes_placa = obtener_mes_digito(placa[strlen(placa) - 1]);
	meses_retraso = calcular_meses_retraso(mes_actual, mes_placa);
	
	impuesto = calcular_impuesto_vehiculo(avaluo);
	sppat = calcular_sppat((int)cilindraje, antiguedad);
	hdn = HDN;
	rodaje = calcular_rodaje_provincial((int)cilindraje);
	tasa_muni = calcular_tasa_municipal(provincia);
	recargo = meses_retraso * RECARGO_MENSUAL;
	costo_placa = necesita_placa ? PLACA_NUEVA : 0;
	
	subtotal = impuesto + sppat + hdn + rodaje + tasa_muni + multas + recargo + costo_placa;
	
	if (edad >= 65)
		total = subtotal * (1 - DESCUENTO_TERCERA_EDAD);
	else
		total = subtotal;
}

void capturarDatos() {
	printf("Ingrese la placa del vehiculo: ");
	scanf("%s", placa);
	
	printf("Ingrese la provincia: ");
	scanf("%s", provincia);
	
	printf("Edad del propietario: ");
	scanf("%d", &edad);
	
	printf("Avaluo del vehiculo (USD): ");
	scanf("%f", &avaluo);
	
	printf("Cilindraje del vehiculo: ");
	scanf("%f", &cilindraje);
	
	printf("Anio de fabricacion del vehiculo: ");
	scanf("%d", &anio_fabricacion);
	
	printf("Mes actual (1-12): ");
	scanf("%d", &mes_actual);
	
	printf("Multas pendientes (USD): ");
	scanf("%f", &multas);
	
	printf("Tiene revision tecnica aprobada? (1 = Si, 0 = No): ");
	scanf("%d", &tiene_revision);
	
	printf("Requiere placas nuevas? (1 = S�, 0 = No): ");
	scanf("%d", &necesita_placa);
	
	if (!tiene_revision) {
		printf("ERROR: No se puede continuar sin revision tecnica.\n");
		return;
	}
}

int main() {
	menuEntrada();
	capturarDatos();
	calcularTotal();
	menuSalida();
	return 0;
}
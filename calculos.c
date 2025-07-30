#include <string.h>
#include <time.h>
#include "calculos.h"

// Función para obtener el mes actual (1-12)
int obtener_mes_actual() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return tm.tm_mon + 1;  // tm_mon es 0-11
}

// Función para calcular recargo basado en mes y último dígito de placa
float calcular_recargo_por_mes(char ultimo_digito_placa) {
	int mes_actual = obtener_mes_actual();
	
	// Diciembre tiene recargo para todos
	if (mes_actual == 12) {
		return RECARGO_DICIEMBRE;
	}
	
	// Noviembre solo para dígito 0
	if (mes_actual == 11 && ultimo_digito_placa == '0') {
		return RECARGO_MENSUAL;
	}
	
	// Enero no tiene recargos
	if (mes_actual == 1) {
		return 0.0f;
	}
	
	// Para los demás meses
	int mes_permitido = obtener_mes_digito(ultimo_digito_placa);
	int meses_retraso = calcular_meses_retraso(mes_actual, mes_permitido);
	
	return calcular_recargo(meses_retraso);
}

float calcular_impuesto_vehiculo(float val) {
	return val * 0.01f;
}

float calcular_sppat(int cil, int edad_auto) {
	if (cil < 1500) return 30.0f;
	else if (cil < 2500) return 50.0f;
	else return 70.0f + (edad_auto * 2);
}

float calcular_rodaje_provincial(int cil) {
	return cil * 0.02f;
}

int obtener_mes_digito(char digito) {
	switch (digito) {
	case '1': return 2;    // Febrero
	case '2': return 3;    // Marzo
	case '3': return 4;    // Abril
	case '4': return 5;    // Mayo
	case '5': return 6;    // Junio
	case '6': return 7;    // Julio
	case '7': return 8;    // Agosto
	case '8': return 9;    // Septiembre
	case '9': return 10;   // Octubre
	case '0': return 11;   // Noviembre
	default: return 1;     // Enero (sin recargo)
	}
}

int calcular_meses_retraso(int actual, int permitido) {
	return (actual > permitido) ? actual - permitido : 0;
}

float calcular_recargo(int meses_retraso) {
	return meses_retraso * RECARGO_MENSUAL;
}

float calcular_costo_placa(int necesita_placa) {
	return necesita_placa ? PLACA_NUEVA : 0;
}

float calcular_total(float impuesto, float sppat, float hdn, float rodaje, float multas, float recargo, float costo_placa, int edad) {
	float subtotal = impuesto + sppat + hdn + rodaje + multas + recargo + costo_placa;
	if (edad >= 65)
		return subtotal * (1 - DESCUENTO_TERCERA_EDAD);
	else
		return subtotal;
}

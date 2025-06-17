#include <string.h>
#include "calculos.h"

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

float calcular_tasa_municipal(const char *provincia) {
    if (strcmp(provincia, "Guayas") == 0)
        return 20.0f;
    else
        return 10.0f;
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

float calcular_recargo(int meses_retraso) {
    return meses_retraso * RECARGO_MENSUAL;
}

float calcular_costo_placa(int necesita_placa) {
    return necesita_placa ? PLACA_NUEVA : 0;
}

float calcular_total(float impuesto, float sppat, float hdn, float rodaje, float tasa_muni, float multas, float recargo, float costo_placa, int edad) {
    float subtotal = impuesto + sppat + hdn + rodaje + tasa_muni + multas + recargo + costo_placa;
    if (edad >= 65)
        return subtotal * (1 - DESCUENTO_TERCERA_EDAD);
    else
        return subtotal;
}
#ifndef CALCULOS_H
#define CALCULOS_H

#include <time.h>

#define HDN 15.0
#define PLACA_NUEVA 30.0
#define DESCUENTO_TERCERA_EDAD 0.5
#define RECARGO_MENSUAL 25.0
#define RECARGO_DICIEMBRE 100.0  // Recargo especial para diciembre

float calcular_impuesto_vehiculo(float val);
float calcular_sppat(int cil, int edad_auto);
float calcular_rodaje_provincial(int cil);
int obtener_mes_digito(char digito);
int calcular_meses_retraso(int actual, int permitido);
float calcular_recargo(int meses_retraso);
float calcular_costo_placa(int necesita_placa);
float calcular_total(float impuesto, float sppat, float hdn, float rodaje, float multas, float recargo, float costo_placa, int edad);
int obtener_mes_actual();
float calcular_recargo_por_mes(char ultimo_digito_placa);

#endif

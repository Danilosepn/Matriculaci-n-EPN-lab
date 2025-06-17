#ifndef CALCULOS_H
#define CALCULOS_H

#define HDN 15.0
#define PLACA_NUEVA 30.0
#define DESCUENTO_TERCERA_EDAD 0.5
#define RECARGO_MENSUAL 25.0

float calcular_impuesto_vehiculo(float val);
float calcular_sppat(int cil, int edad_auto);
float calcular_rodaje_provincial(int cil);
float calcular_tasa_municipal(const char *provincia);
int obtener_mes_digito(char digito);
int calcular_meses_retraso(int actual, int permitido);
float calcular_recargo(int meses_retraso);
float calcular_costo_placa(int necesita_placa);
float calcular_total(float impuesto, float sppat, float hdn, float rodaje, float tasa_muni, float multas, float recargo, float costo_placa, int edad);

#endif
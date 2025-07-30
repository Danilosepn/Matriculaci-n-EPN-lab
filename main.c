#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "entrada.h"
#include "estructuras.h"
#include "calculos.h"

char usuarioActual[100];  // Usuario logueado

void pausar() {
	printf("\nPresione Enter para continuar...");
	getchar();
}

void mostrarMenu() {
	printf("\n===== MENU PRINCIPAL =====\n");
	printf("1. Registrar un vehiculo nuevo\n");
	printf("2. Buscar vehiculo\n");
	printf("3. Calcular valor de matricula\n");
	printf("4. Listar vehiculos matriculados\n");
	printf("5. Salir\n");
	printf("Seleccione una opcion: ");
}

void buscarVehiculo() {
	char placaBuscada[10], linea[200];
	int intentos = 3, encontrado = 0;
	int cont=0;
	
	while (intentos--) {
		cont++;
		printf("\nIngrese la placa del vehiculo (intento %d de 3):  ",cont);
		scanf("%s", placaBuscada);
		while (getchar() != '\n');
		
		char* carpeta = getenv("USERPROFILE");
		if (carpeta != NULL) {
			char ruta[200];
			sprintf(ruta, "%s\\Documents\\vehiculos_matriculados.txt", carpeta);
			FILE* archivo = fopen(ruta, "r");
			if (archivo == NULL) {
				printf("Error al abrir el archivo de vehiculos.\n");
				return;
			}
			
			int leer = 0;
			while (fgets(linea, sizeof(linea), archivo)) {
				if (strstr(linea, "Usuario: ") && strstr(linea, usuarioActual)) {
					leer = 1;
				}
				if (leer && strstr(linea, placaBuscada)) {
					encontrado = 1;
					printf("\n--- Vehiculo encontrado ---\n");
					printf("%s", linea);
					for (int i = 0; i < 5 && fgets(linea, sizeof(linea), archivo); i++) {
						printf("%s", linea);
					}
					break;
				}
			}
			fclose(archivo);
		}
		
		if (encontrado) break;
		printf("Vehiculo no encontrado o no pertenece a su cuenta.\n");
	}
	
	if (!encontrado) {
		printf("No se encontraron coincidencias tras 3 intentos. Regresando al menu.\n");
	}
	pausar();
	system("cls");
}

void calcularMatriculaDesdeRegistro() {
	char* carpeta = getenv("USERPROFILE");
	char ruta[200], linea[200];
	sprintf(ruta, "%s\\Documents\\vehiculos_matriculados.txt", carpeta);
	FILE* archivo = fopen(ruta, "r");
	
	if (archivo == NULL) {
		printf("Error al abrir el archivo de vehiculos.\n");
		pausar();
		system("cls");
		return;
	}
	
	int mostrar = 0, contador = 0;
	Vehiculo v;
	
	printf("\n--- Calculo de matricula para sus vehiculos registrados ---\n");
	
	while (fgets(linea, sizeof(linea), archivo)) {
		if (strstr(linea, "Usuario: ") && strstr(linea, usuarioActual)) {
			mostrar = 1;
		} else if (strstr(linea, "Usuario: ") && !strstr(linea, usuarioActual)) {
			mostrar = 0;
		}
		
		if (mostrar) {
			if (strstr(linea, "Placa: ")) sscanf(linea, "Placa: %s", v.placa);
			if (strstr(linea, "Edad: ")) sscanf(linea, "Edad: %d", &v.edad);
			if (strstr(linea, "Avaluo: ")) sscanf(linea, "Avaluo: %f", &v.avaluo);
			if (strstr(linea, "Cilindraje: ")) sscanf(linea, "Cilindraje: %f", &v.cilindraje);
			if (strstr(linea, "Anio de fabricacion: ")) sscanf(linea, "A%cno de fabricacion: %d", &v.anioFabricacion);
			
			if (strstr(linea, "------------------------------")) {
				contador++;
				
				// Obtener último dígito de la placa (asumiendo que está en v.placa)
				char ultimo_digito = v.placa[strlen(v.placa) - 1];
				
				// Calculo de recargo basado en mes y último dígito
				float recargo = calcular_recargo_por_mes(ultimo_digito);
				
				// Resto de los cálculos
				float impuesto = calcular_impuesto_vehiculo(v.avaluo);
				float sppat = calcular_sppat((int)v.cilindraje, 2025 - v.anioFabricacion);
				float rodaje = calcular_rodaje_provincial((int)v.cilindraje);
				float costo_placa = calcular_costo_placa(0);
				float total = calcular_total(impuesto, sppat, 0.0, rodaje, 0.0, recargo, costo_placa, v.edad);
				// Mostrar
				printf("\nVehiculo #%d\n", contador);
				printf("Placa: %s\n", v.placa);
				printf("Edad del propietario: %d\n", v.edad);
				printf("Avaluo: %.2f\n", v.avaluo);
				printf("Cilindraje: %.1f\n", v.cilindraje);
				printf("A%co de fabricacion: %d\n", 164, v.anioFabricacion);
				
				printf("Impuesto: %.2f | SPPAT: %.2f | Rodaje: %.2f | Recargo: %.2f | Total: %.2f\n",
					   impuesto, sppat, rodaje, recargo, total);
			}
		}
	}
	
	fclose(archivo);
	
	if (contador == 0) {
		printf("\nPrimero registre un vehiculo en la opcion 1.\n");
	}
	
	pausar();
	system("cls");
}

void listarVehiculosUsuario() {
	char* carpeta = getenv("USERPROFILE");
	char ruta[200], linea[200];
	sprintf(ruta, "%s\\Documents\\vehiculos_matriculados.txt", carpeta);
	FILE* archivo = fopen(ruta, "r");
	
	if (archivo == NULL) {
		printf("No hay vehiculos registrados.\n");
		pausar();
		system("cls");
		return;
	}
	
	int contador = 0;
	char placa[20], cedula[20] = "";
	int anioFabricacion;
	float avaluo;
	int imprimir = 0;
	
	printf("\n--- Lista de vehiculos registrados ---\n");
	
	while (fgets(linea, sizeof(linea), archivo)) {
		
		if (strstr(linea, "Usuario: ") && strstr(linea, usuarioActual)) {
			imprimir = 1;
			contador++;
			
			// Extraer la cédula (último elemento de la línea)
			char* ultimoEspacio = strrchr(linea, ' ');
			if (ultimoEspacio != NULL) {
				strcpy(cedula, ultimoEspacio + 1);
				cedula[strcspn(cedula, "\n")] = '\0'; // Eliminar salto de línea
			}
		} 
		else if (strstr(linea, "Usuario: ") && !strstr(linea, usuarioActual)) {
			imprimir = 0;
		}
		
		if (imprimir) {
			if (strstr(linea, "Placa: ")) {
				sscanf(linea, "Placa: %s", placa);
			}
			else if (strstr(linea, "Anioo de fabricacion: ") || strstr(linea, "Ano de fabricacion: ")) {
				sscanf(linea, "Anio de fabricacion: %d", &anioFabricacion);
			}
			else if (strstr(linea, "Avaluo: ")) {
				sscanf(linea, "Avaluo: %f", &avaluo);
			}
			else if (strstr(linea, "------------------------------")) {
				printf("%d.- %s | %s | %d | %.2f\n", 
					   contador, placa, cedula, anioFabricacion, avaluo);
			}
		}
	}
	
	fclose(archivo);
	
	if (contador == 0) {
		printf("No tiene vehiculos registrados.\n");
	}
	
	pausar();
	system("cls");
}
int placaRegistrada(const char* placa) {
	char ruta[200], linea[200], placaArchivo[20];
	char* carpeta = getenv("USERPROFILE");
	sprintf(ruta, "%s\\Documents\\vehiculos_matriculados.txt", carpeta);
	
	FILE* archivo = fopen(ruta, "r");
	if (!archivo) return 0;
	
	while (fgets(linea, sizeof(linea), archivo)) {
		if (strstr(linea, "Placa: ")) {
			sscanf(linea, "Placa: %s", placaArchivo);
			if (strcmp(placaArchivo, placa) == 0) {
				fclose(archivo);
				return 1;
			}
		}
	}
	fclose(archivo);
	return 0;
}

char usuarioActual[100];
int main() {
	int opcionlog;
	int sesionIniciada = 0;
	Vehiculo vehiculo;
	int opcion;
	
	system("cls");
	
	// ==== LOGIN Y REGISTRO ====
	do {
		printf("\n===== Matriculacion Vehicular =====\n");
		printf("1. Iniciar sesion\n2. Registrarse\n3. Salir\nSeleccione: ");
		scanf("%d", &opcionlog); while (getchar()!='\n');
		system("cls");
		switch (opcionlog) {
		case 1:
			sesionIniciada = loginUsuario();
			system("cls");
			break;
		case 2:
			registrarUsuario();
			pausar();
			system("cls");
			break;
		case 3:
			printf("Saliendo del programa...\n");
			return 0;
		default:
			printf("Opcion invalida.\n");
			pausar();
			system("cls");
		}
	} while (!sesionIniciada);
	
	printf("Usuario correcto, bienvenido %s\n", usuarioActual);
	
	do {
		mostrarMenu();
		scanf("%d", &opcion);
		while (getchar() != '\n');
		
		system("cls");
		
		switch (opcion) {
		case 1: {
			// Validar revisiones técnicas con 3 intentos
			int intentos = 3;
			char respuesta;
			int revisiones_aprobadas = 0; // 0 = no, 1 = sí
			
			while (intentos > 0 && !revisiones_aprobadas) {
				system("cls");
				printf("¿El vehiculo tiene las tres revisiones tecnicas aprobadas? (S/N) (Intentos restantes: %d): ", intentos);
				scanf(" %c", &respuesta);
				
				if (tolower(respuesta) == 's') {
					revisiones_aprobadas = 1;
				} 
				else if (tolower(respuesta) == 'n') {
					printf("\nERROR: Para matricular el vehiculo debe tener las tres revisiones aprobadas.\n");
					intentos--;
					
					if (intentos > 0) {
						printf("Por favor intente nuevamente.\n");
						pausar();
					}
				} 
				else {
					printf("\nERROR: Respuesta no valida. Solo se acepta S o N.\n");
					intentos--;
					
					if (intentos > 0) {
						printf("Por favor intente nuevamente.\n");
						pausar();
					}
				}
			}
			
			if (!revisiones_aprobadas) {
				printf("\nHa agotado sus 3 intentos. Volviendo al menu principal.\n");
				pausar();
				system("cls");
				break;
			}
			
			// Capturar los datos del vehículo
			if (!obtenerDatosVehiculo(&vehiculo)) {
				printf("Proceso cancelado por datos invalidos.\n");
				pausar();
				system("cls");
				break;
			}
			
			// Verificar que la placa no esté ya registrada
			if (placaRegistrada(vehiculo.placa)) {
				printf("\nYa existe un vehiculo con esa placa registrado.\n");
				pausar();
				system("cls");
				break;
			}
			
			// Mostrar los datos ingresados
			printf("\n--- Datos ingresados correctamente ---\n");
			printf("Placa: %s\n", vehiculo.placa);
			printf("Edad del propietario: %d\n", vehiculo.edad);
			printf("Avaluo del vehiculo: %.2f\n", vehiculo.avaluo);
			printf("Cilindraje: %.1f\n", vehiculo.cilindraje);
			printf("A%co de fabricacion: %d\n", 164, vehiculo.anioFabricacion);
			
			// Guardar los datos en el archivo
			char* carpeta = getenv("USERPROFILE");
			if (carpeta != NULL) {
				char ruta[200];
				sprintf(ruta, "%s\\Documents\\vehiculos_matriculados.txt", carpeta);
				FILE* archivo = fopen(ruta, "a");
				if (archivo != NULL) {
					fprintf(archivo,
							"Usuario: %s\nPlaca: %s\nEdad: %d\nAvaluo: %.2f\nCilindraje: %.1f\nA%co de fabricacion: %d\n------------------------------\n",
							usuarioActual, vehiculo.placa, vehiculo.edad,
							vehiculo.avaluo, vehiculo.cilindraje, 164, vehiculo.anioFabricacion);
					fclose(archivo);
					
				} else {
					printf("Error al guardar el archivo.\n");
				}
			}
			
			pausar();
			system("cls");
			break;
		}	
		case 2:
			buscarVehiculo();
			break;
			
		case 3:
			calcularMatriculaDesdeRegistro();
			break;
			
		case 4:
			listarVehiculosUsuario();
			break;
			
		case 5:
			printf("Saliendo del programa...\n");
			break;
			
		default:
			printf("Opcion invalida. Intente de nuevo.\n");
			pausar();
			system("cls");
		}
	} while (opcion != 5);
	
	return 0;
}

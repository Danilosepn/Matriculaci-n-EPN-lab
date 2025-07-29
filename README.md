README — Sistema Integral de Matriculación Vehicular (C)

Descripción general:
Este sistema permite la gestión de usuarios y vehículos para fines de matriculación. Incluye funcionalidades como registro, autenticación, almacenamiento de datos en archivos, validaciones, y un menú de operaciones administrativas. Está desarrollado en lenguaje C, siguiendo un enfoque modular y estructurado.

Estructura del código:

main.c → Función principal y control de flujo general.

usuarios.c / usuarios.h =README — Sistema Integral de Matriculación Vehicular (C)

Descripción general:
Este sistema permite la gestión de usuarios y vehículos para fines de matriculación. Incluye funcionalidades como registro, autenticación, almacenamiento de datos en archivos, validaciones, y un menú de operaciones administrativas. Está desarrollado en lenguaje C, siguiendo un enfoque modular y estructurado.

Estructura del código:

main.c → Función principal y control de flujo general.

usuarios.c / usuarios.h → Registro e inicio de sesión de usuarios, y funciones de validación de cédula y contraseña.

entrada.c / entrada.h → Obtención y validación de datos del vehículo.

calculos.c / calculos.h → Funciones para calcular impuestos, recargos y el costo total de la matrícula.

validaciones.c / validaciones.h → Funciones genéricas de validación para nombres, números y placas.

estructuras.h → Definición de la estructura Vehiculo.

Archivos externos utilizados:

vehiculos_matriculados.txt → Contiene datos de usuarios y vehículos matriculados. Este archivo es creado o accedido dentro del directorio Documents del perfil del usuario (e.g., C:\Users\SuUsuario\Documents\vehiculos_matriculados.txt).

Requisitos:

Compilador compatible con C (se recomienda ZinjaI o GCC).

Sistema operativo Windows o Linux.

Acceso a archivos locales (especialmente vehiculos_matriculados.txt en el directorio Documents del usuario).

Compilación y ejecución:

Asegúrese de que todos los archivos .c estén incluidos en el proyecto.

Compile desde ZinjaI (F9) o mediante línea de comandos (ejemplo para GCC):
gcc main.c usuarios.c entrada.c calculos.c validaciones.c -o sistema

Una vez compilado, ejecute el archivo sistema (o el nombre que le haya dado al ejecutable).

Funcionamiento:
Al iniciar, el programa presenta un menú para iniciar sesión o registrarse. Una vez que el usuario ha iniciado sesión correctamente, accede al menú principal desde donde puede registrar nuevos vehículos, buscar vehículos existentes, calcular el valor de la matrícula para sus vehículos registrados o listar todos sus vehículos. Los datos se guardan persistentemente en el archivo vehiculos_matriculados.txt.

Validaciones implementadas:

Formato de placa: Tres letras seguidas de cuatro dígitos (e.g., PBA1234).

Cédula: Diez dígitos numéricos.

Contraseña: Entre 5 y 20 caracteres.

Edad del propietario: Entre 18 y 85 años.

Avalúo del vehículo: Mayor a 0 y menor o igual a 10,000,000 USD.

Cilindraje: Mayor a 0.

Año de fabricación: Entre 1900 y 2025.

Revisiones técnicas: Requiere confirmación de tener las tres revisiones aprobadas para registrar un vehículo.

Placa ya registrada: Impide el registro de vehículos con placas duplicadas para el mismo usuario.

Limitaciones:

Los datos se almacenan en un archivo de texto plano, lo que puede limitar la escalabilidad y la eficiencia para grandes volúmenes de datos.

No hay un límite explícito en el número de usuarios o vehículos más allá de las limitaciones de almacenamiento del sistema de archivos.

No se conecta con bases de datos externas.

Autoría:
Desarrollado por Danilo Unapucha y Henry Luisa. Este proyecto está orientado a la práctica de programación modular, validación de datos y documentación clara en lenguaje C. Registro e inicio de sesión de usuarios, y funciones de validación de cédula y contraseña.

entrada.c / entrada.h → Obtención y validación de datos del vehículo.

calculos.c / calculos.h → Funciones para calcular impuestos, recargos y el costo total de la matrícula.

validaciones.c / validaciones.h → Funciones genéricas de validación para nombres, números y placas.

estructuras.h → Definición de la estructura Vehiculo.

Archivos externos utilizados:

vehiculos_matriculados.txt → Contiene datos de usuarios y vehículos matriculados. Este archivo es creado o accedido dentro del directorio Documents del perfil del usuario (e.g., C:\Users\SuUsuario\Documents\vehiculos_matriculados.txt).

Requisitos:

Compilador compatible con C (se recomienda ZinjaI o GCC).

Sistema operativo Windows o Linux.

Acceso a archivos locales (especialmente vehiculos_matriculados.txt en el directorio Documents del usuario).

Compilación y ejecución:

Asegúrese de que todos los archivos .c estén incluidos en el proyecto.

Compile desde ZinjaI (F9) o mediante línea de comandos (ejemplo para GCC):
gcc main.c usuarios.c entrada.c calculos.c validaciones.c -o sistema

Una vez compilado, ejecute el archivo sistema (o el nombre que le haya dado al ejecutable).

Funcionamiento:
Al iniciar, el programa presenta un menú para iniciar sesión o registrarse. Una vez que el usuario ha iniciado sesión correctamente, accede al menú principal desde donde puede registrar nuevos vehículos, buscar vehículos existentes, calcular el valor de la matrícula para sus vehículos registrados o listar todos sus vehículos. Los datos se guardan persistentemente en el archivo vehiculos_matriculados.txt.

Validaciones implementadas:

Formato de placa: Tres letras seguidas de cuatro dígitos (e.g., PBA1234).

Cédula: Diez dígitos numéricos.

Contraseña: Entre 5 y 20 caracteres.

Edad del propietario: Entre 18 y 85 años.

Avalúo del vehículo: Mayor a 0 y menor o igual a 10,000,000 USD.

Cilindraje: Mayor a 0.

Año de fabricación: Entre 1900 y 2025.

Revisiones técnicas: Requiere confirmación de tener las tres revisiones aprobadas para registrar un vehículo.

Placa ya registrada: Impide el registro de vehículos con placas duplicadas para el mismo usuario.

Limitaciones:

Los datos se almacenan en un archivo de texto plano, lo que puede limitar la escalabilidad y la eficiencia para grandes volúmenes de datos.

No hay un límite explícito en el número de usuarios o vehículos más allá de las limitaciones de almacenamiento del sistema de archivos.

No se conecta con bases de datos externas.

Autoría:
Desarrollado por Danilo Unapucha y Henry Luisa. Este proyecto está orientado a la práctica de programación modular, validación de datos y documentación clara en lenguaje C.

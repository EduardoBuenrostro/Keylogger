# Keylogger

El proyecto es un keylogger básico programado en C que captura las pulsaciones de teclas en el teclado dentro de un sistema Linux. El keylogger obtiene el dispositivo de entrada en el sistema, lo lee y guarda en un fichero txt las teclas presionadas al momento en que son soltadas por el usuario.

## Descripción

  1. **Identifica el Dispositivo del Teclado:** Utiliza comandos de sistema para encontrar el dispositivo del teclado en ```/dev/input/```.
  2. **Lee Eventos de Teclado:** Se suscribe a eventos de teclado y filtra solo los eventos de liberación de tecla ```(ev.value == 0)```.
  3. **Registra las Teclas:** Mediante un mapeo de las claves ubicadas en ```/usr/include/linux/input-event-codes.h``` traduce los códigos de tecla en nombres legibles y los escribe en un archivo de registro (keylogger.txt).

## Instrucciones

  1. **Clona o copia el código en tu sistema**
  2. **Cambia la ruta de generación del archivo txt:** Asegurate de cambiar la ruta por una ruta válida en tu sistema de la linea ```#define LOGFILEPATH "/home/eduardo/Documentos/Seguridad_Informatica/keylogger/keylogger.txt"```.
  3. **Compila el código:** Asegurate de tener instalado un compilador como gcc y usa el siguiente comando: ```gcc keylogger_v2_1.c -o keylogger_v2_1```.
  4. **Ejecuta el keylogger:** Ejecuta el programa con permisos de superusuario para acceder al dispositivo de entrada: ```sudo ./keylogger_v2_1```.
  El keylogger comenzará a registrar las teclas presionadas en el archivo especificado por ```LOGFILEPATH```.
  5. **Revisar el Archivo de Registro:** Las teclas presionadas se almacenarán en el archivo ```/home/eduardo/Documentos/Seguridad_Informatica/keylogger/keylogger.txt``` (Aquí va a variar dependiendo la ruta que coloques). Puedes revisar este archivo para ver el registro de las teclas.

## Supuestos del Programa

* **Sistema Operativo:** Linux
* **Permisos de Superusuario:** Se requiere permisos de superusuario para acceder a los dispositivos de entrada.
* **Dispositivos de Entrada:** El keylogger asume que el teclado está disponible en ```/dev/input/``` y que el archivo ```/proc/bus/input/devices``` contiene la información necesaria para identificar el dispositivo.

## Casos de Uso

* **Monitoreo de Actividad:** Puede ser utilizado para monitorear la actividad del teclado en un entorno controlado para fines de prueba o desarrollo.
* **Desarrollo de Aplicaciones:** Útil para desarrolladores que necesiten capturar y analizar eventos de teclado en sus aplicaciones.
* **Pruebas de Seguridad:** Se puede utilizar para verificar la seguridad de sistemas y aplicaciones.
* **Depuración de Aplicaciones:** Se puede usar el keylogger para verificar el comportamiento de las aplicaciones y asegurarse de que las entradas del teclado se manejan correctamente.
* **Estudio del Comportamiento del Usuario:** Puede ser utilizado para estudiar cómo los usuarios interactúan con un software o sistema específico.
* **Recuperación de Información:** Puede ayudar a restaurar datos importantes que se ingresaron en un sistema.
* **Entendimiento:** Como estudiantes nos sirve para comprender el funcionamiento de los eventos del dispositivo. 

## Autores

* **DANIEL FERNANDO PALMA LOPEZ**
* **EDUARDO ALBERTO BUENROSTRO PARDO**

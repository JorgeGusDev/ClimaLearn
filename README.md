Configuración de ESP32 con PlatformIO y Wokwi

Instalar la extensión PlatformIO IDE desde el marketplace de Visual Studio Code.

Instalar la extensión Wokwi Simulator desde el marketplace de Visual Studio Code.

Crear un nuevo proyecto en PlatformIO.

Asignar un nombre al proyecto: [...].

Seleccionar la placa: DOIT ESP32 DEVKIT V1.

Seleccionar el framework: Arduino.

Hacer clic en Finish para generar el proyecto.

Abrir el archivo platformio.ini.

Configurar el archivo platformio.ini de la siguiente manera:

[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
monitor_speed = 115200

lib_deps =
    knolleary/PubSubClient
    bblanchon/ArduinoJson
    beegee-tokyo/DHT sensor library for ESPx


Abrir el archivo src/main.cpp.

Pegar el código del proyecto correspondiente al simulador Wokwi.

Verificar que el archivo mantenga la directiva:

#include <Arduino.h>


Ejecutar la opción Build del proyecto en PlatformIO.

Verificar que la compilación finalice correctamente con el mensaje [SUCCESS].

Presionar la tecla F1 en Visual Studio Code.

Seleccionar la opción Wokwi: Request a New License.

Abrir el enlace generado en la ventana emergente.

Autorizar la licencia de Wokwi en Visual Studio Code.

Verificar el mensaje License activated.

Crear el archivo diagram.json.

Abrir diagram.json con Text Editor.

Pegar el código del diagrama Wokwi correspondiente al circuito.

Crear el archivo wokwi.toml.

Pegar en wokwi.toml la siguiente configuración:

[wokwi]
version = 1
firmware = '.pio/build/esp32doit-devkit-v1/firmware.bin'
elf = '.pio/build/esp32doit-devkit-v1/firmware.elf'


Guardar el archivo wokwi.toml.

Ejecutar la opción Run sobre el archivo diagram.json.

Verificar la correcta simulación del ESP32 y la interacción con los sensores.

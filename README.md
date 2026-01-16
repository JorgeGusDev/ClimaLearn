# Configuración de ESP32 con PlatformIO y Wokwi

## 1. Instalación de extensiones

1. Instalar la extensión **PlatformIO IDE** desde el marketplace de Visual Studio Code.
2. Instalar la extensión **Wokwi Simulator** desde el marketplace de Visual Studio Code.

## 2. Creación del proyecto en PlatformIO

3. Crear un nuevo proyecto en PlatformIO.
4. Asignar un **nombre al proyecto**: `[...]`.
5. Seleccionar la **placa**: `DOIT ESP32 DEVKIT V1`.
6. Seleccionar el **framework**: `Arduino`.
7. Hacer clic en **Finish** para generar el proyecto.

## 3. Configuración del archivo platformio.ini

8. Abrir el archivo `platformio.ini`.
9. Configurar el archivo de la siguiente manera:

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
monitor_speed = 115200

lib_deps =
    knolleary/PubSubClient
    bblanchon/ArduinoJson
    beegee-tokyo/DHT sensor library for ESPx

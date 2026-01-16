````md
# Configuración de ESP32 con PlatformIO y Wokwi en Visual Studio Code

## 1. Instalación de extensiones
- Abrir **Visual Studio Code**.
- Ir a la sección **Extensions**.
- Instalar la extensión **PlatformIO IDE**.
- Instalar la extensión **Wokwi Simulator**.

## 2. Creación del proyecto en PlatformIO
- Abrir **PlatformIO Home**.
- Seleccionar **New Project**.
- Configurar el proyecto con los siguientes parámetros:
  - **Name**: `[Nombre del proyecto]`
  - **Board**: `DOIT ESP32 DEVKIT V1`
  - **Framework**: `Arduino`
- Hacer clic en **Finish**.
- Esperar a que PlatformIO genere la estructura del proyecto.

## 3. Configuración del archivo `platformio.ini`
- Abrir el archivo `platformio.ini`.
- Reemplazar o verificar que contenga la siguiente configuración:

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
````

## 4. Configuración del código fuente

* Ir a la carpeta `src`.
* Abrir el archivo `main.cpp`.
* Pegar el código correspondiente al simulador Wokwi.
* Verificar que se mantenga la directiva obligatoria:

```cpp
#include <Arduino.h>
```

## 5. Compilación del proyecto

* En la barra inferior de PlatformIO, seleccionar la opción **Build**.
* Esperar a que el proceso de compilación finalice.
* Verificar que el resultado sea **[SUCCESS]**.

## 6. Activación de la licencia de Wokwi

* Presionar la tecla **F1**.
* Escribir y seleccionar **Wokwi: Request a New License**.
* Se abrirá una ventana emergente en el navegador.
* Seleccionar **Get your License**.
* Autorizar la licencia para Visual Studio Code.
* Confirmar que aparezca el mensaje **License activated** en VSC.

## 7. Creación del archivo `diagram.json`

* En la raíz del proyecto, crear un archivo llamado `diagram.json`.
* Hacer clic derecho sobre el archivo y seleccionar **Open With → Text Editor**.
* Pegar el código del diagrama del circuito de Wokwi (sensores, ESP32, conexiones).

## 8. Creación del archivo `wokwi.toml`

* En la raíz del proyecto, crear un archivo llamado `wokwi.toml`.
* Pegar la siguiente configuración:

```toml
[wokwi]
version = 1
firmware = '.pio/build/esp32doit-devkit-v1/firmware.bin'
elf = '.pio/build/esp32doit-devkit-v1/firmware.elf'
```

## 9. Ejecución de la simulación

* Abrir el archivo `diagram.json`.
* Hacer clic en **Run**.
* Verificar que el ESP32 se ejecute correctamente en el simulador Wokwi.

```
```

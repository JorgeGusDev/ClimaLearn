#include <pgmspace.h>
#define SECRET
#define THINGNAME "yourthingname"
const char WIFI_SSID[] = "Wokwi-GUEST";
const char WIFI_PASSWORD[] = ""; 
const char AWS_IOT_ENDPOINT[] = "yourendpointname"; 
//Get by CLI with: "aws iot describe-endpoint --endpoint-type iot:Data-ATS" or Connect/Domain Configuration in AWS IoT Core Console/Domain name


// Amazon Root CA 1  -AmazonRootCA1.pem
//Certificado que permite al dispositivo verificar que realmente se está conectando a AWS.
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
yourcertificate
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate -certificate.pem.crt       
//Identifica al dispositivo ante AWS como un "dispositivo válido y registrado".                                        
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
yourcertificate

-----END CERTIFICATE-----

)KEY";
 
// Device Private Key -private.pem.key
//Clave secreta que usa el dispositivo para autenticarse y demostrar que es quien dice ser.                                            
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
yourcertificate

-----END RSA PRIVATE KEY-----

)KEY";


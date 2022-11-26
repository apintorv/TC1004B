
#include <ArduinoHttpClient.h>
#include <ESP8266WiFi.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tec-IoT";
char pass[] = "spotless.magnetic.bridge";

const int LDR = A0;

float t;
float h;
float f;
int valor;

char serverAddress[] = "35.233.223.53";  // server address
int port = 8080;

WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;


void setup()
{
  Serial.begin(115200);
  pinMode(LDR,INPUT);
  Serial.print("Conectando...");
  while (WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conexión OK!");
  Serial.print("IP Local: ");
  Serial.println(WiFi.localIP());
}


void loop()
{
  char buffer[100] = "";
  delay (1000);

  int a = analogRead(LDR);
  valor = map(a, 0, 150, 0, 100);
  Serial.print(valor); 
  Serial.print("% de luz");

  sprintf_P(buffer, "/luz=%ld", valor);

  Serial.println("making GET request");
  client.get(buffer);
    
}

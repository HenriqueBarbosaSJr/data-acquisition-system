#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte servidor[] = { 192, 168,25, 17 };
//char servidorSQL[] = "";

EthernetClient clientArduino;

float sensor1 =3;
float sensor2 =5;
float sensor3 =7;


void setup() {

  Serial.begin(9600);
  Ethernet.begin(mac);

  if(Ethernet.begin(mac) == 0){
    Serial.println(" Falha de conexão");
    Ethernet.begin(mac);
  }
  Serial.print("Conectado a rede, no ip: ");
  Serial.println(Ethernet.localIP());
  
}
void loop() {
  if(clientArduino.available()){
    char dadosRetornados = clientArduino.read();
    Serial.print(dadosRetornados);
  }

  if(!clientArduino.connected()){
    clientArduino.stop();
  }
  char comando = Serial.read();
  if(comando == '1'){

      sensor1++;
      sensor2++;
      sensor3++;
      
      Serial.println("conectando ao servidor e enviando os dados");
      Serial.print("Sensor1: ");
      Serial.println(sensor1);
      Serial.print("Sensor2: ");
      Serial.println(sensor2);
      Serial.print("Sensor3: ");
      Serial.println(sensor3);
      
      if(clientArduino.connect(servidor, 80)){  // sevidor local xamp

        clientArduino.print("GET /arduino/include.php");
        clientArduino.print("?s1=");
        clientArduino.print(sensor1);
        clientArduino.print("&s2=");
        clientArduino.print(sensor2);
        clientArduino.print("&s3=");
        clientArduino.print(sensor3);
        clientArduino.println(" HTTP/1.0");
        
        clientArduino.println("Host: 192.168.25.17");
        clientArduino.println("Connection: close");
        clientArduino.println();

        
      }else{
        Serial.println("Falha de conexão con servidor PHP local");
      }
    }
  //delay(7000);

}

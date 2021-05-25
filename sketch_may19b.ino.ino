//Der Arduino, der Servo und der DHT 22 Sensor bekommen hier durch einen Code ihre Funktion

//In diesem Abschnitt wurden Sensor und Servo für folgende Abschnitte eingerichtet
#include <Adafruit_Sensor.h>

#include <Servo.h>
Servo myservo;

#include "DHT.h"         // eingebundene Bibliothek für den DHT 22 Sensor

#define DHTPIN 13       //Der digitale Pin(13), an den der Sensor angesteckt ist
#define DHTTYPE DHT22 
  

DHT dht(DHTPIN, DHTTYPE);
float servostellung;  //Variable für die Stellung des Servos(0-180°)

void setup() {
myservo.attach(8);    //Pin(8), an den der Sensor angesteckt ist
Serial.begin(9600);   
dht.begin();
//Code für den seriellen Monitor (Werkzeuge -> Serieller Monitor)
}

void loop() {
float Luftfeuchtigkeit = dht.readHumidity();           //Variablen für Luftfeuchtigkeit und Temperatur
float Temperatur = dht.readTemperature();
servostellung = map(Luftfeuchtigkeit, 0, 100, 0, 180);
//Servo dreht sich parallel zur Luftfeuchtigkeit im Bereich 0-180° und die Werte erscheinen im Seriellen Monitor in Form von % (0-100) 
if( Luftfeuchtigkeit >= 0 ){
  myservo.write(0);
  myservo.write(servostellung);
  delay(1000);
  Serial.print("Luftfeuchtigkeit -> " );
  Serial.print(Luftfeuchtigkeit);
  Serial.println("%");        
                     
}
//Anzeige der Temperatur im Seriellen Monitor     
Serial.print("Temperatur -> " );
Serial.print(Temperatur);
Serial.println("°C");
delay(500);                                     
}

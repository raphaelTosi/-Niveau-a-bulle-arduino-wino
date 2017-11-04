
#define RGB_PIN_RED 23
#define RGB_PIN_GREEN 5
#define RGB_PIN_BLUE 6
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>


/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
int x_test, y_test, z_test;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  pinMode(RGB_PIN_RED, OUTPUT);
  pinMode(RGB_PIN_GREEN, OUTPUT);
  pinMode(RGB_PIN_BLUE, OUTPUT);
  
  x_test = y_test = z_test = 0;
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
}

void loop() {
  sensors_event_t event; 
  accel.getEvent(&event);
  // ca sert pour le debug l'affichage ( si rien ne s'ffiche sur la console, alors le capteur accelero ne fonctionne pas 
  //ou alors le wino n'est pas bien connect ce qui est souvent le cas)
  Serial.print("X: "); Serial.print((int)(event.acceleration.x * 50)); Serial.print("  ");
  Serial.print("Y: "); Serial.print((int)(event.acceleration.y * 50)); Serial.print("  ");
  Serial.print("Z: "); Serial.print((int)(event.acceleration.z * 50)); Serial.println("  ");

  x_test = (int)(event.acceleration.x * 50);
  y_test = (int)(event.acceleration.y * 50);
  z_test = (int)(event.acceleration.z * 50);
  
  if (x_test == 0 && y_test == 0 && z_test == 29)// a l'endroit
  {
    analogWrite(RGB_PIN_RED, 255);
    analogWrite(RGB_PIN_GREEN, 255);
    analogWrite(RGB_PIN_BLUE, 255);
    Serial.print(" a l'endroit");
  }
  else // gauche
    if (x_test == -29 && y_test == 0 && z_test == 0)
  {
    analogWrite(RGB_PIN_RED, 255);
    analogWrite(RGB_PIN_GREEN, 0);
    analogWrite(RGB_PIN_BLUE, 0);
    Serial.print(" gauche");
  }
  else // droite
    if (x_test == 31 && y_test == 0 && z_test == -1)
  {
    analogWrite(RGB_PIN_RED, 0);
    analogWrite(RGB_PIN_GREEN, 255);
    analogWrite(RGB_PIN_BLUE, 0);
    Serial.print(" droite");
  }
    else // haut
    if (x_test == 0 && y_test == 31 && z_test == -2)
  {
    analogWrite(RGB_PIN_RED, 37);
    analogWrite(RGB_PIN_GREEN, 253);
    analogWrite(RGB_PIN_BLUE, 233);
    Serial.print(" haut");
  }
      else // bas
    if (x_test == 0 && y_test == -29 && z_test == 0)
  {
    analogWrite(RGB_PIN_RED, 255);
    analogWrite(RGB_PIN_GREEN, 255);
    analogWrite(RGB_PIN_BLUE, 0);
    Serial.print("bas");
  }
      else // a l'envers
    if (x_test == 0 && y_test == 0 && z_test == -31)
  {
    analogWrite(RGB_PIN_RED, 186);
    analogWrite(RGB_PIN_GREEN, 155);
    analogWrite(RGB_PIN_BLUE, 97);
    Serial.print("a l'envers");
  }
  else
  {
    analogWrite(RGB_PIN_RED, 0);
    analogWrite(RGB_PIN_GREEN, 0);
    analogWrite(RGB_PIN_BLUE, 0);
    Serial.print("attente de position");
    
  }
}

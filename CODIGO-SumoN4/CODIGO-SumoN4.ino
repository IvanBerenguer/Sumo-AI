
#define I1 8   // Control pin motor 
#define I2 9   // Control pin motor 
#define I3 10  // Control pin motor 
#define I4 11  // Control pin motor 
#define pulsador 13  // pin para pulsador
#define boton  12 // pin para boton
#define LEDindicador 5 //led programable
#define servo 4 //pin de control del servo motor
#define echo1 2 //sensor izquierdo ultraizquierdo
#define trig1 3 //sensor izquierdo ultraizquierdo
#define echo2 A5 //sensor frontal ultrafrontal
#define trig2 A4 //sensor frontal ultrafrontal
#define echo3 A3 //sensor derecho ultraderecho
#define trig3 A2 //sensor derecho ultraderecho
#define cny2  A1 //sensor de linea izquierdo
#define cny1  A0 //sensor de linea derecho
bool girar=LOW;
int comando,valcny1,valcny2,estadopulsador,estadoboton;
int valultraderecho,valultraizquierdo,valultrafrontal;
#include <Servo.h>  //libreria para control del servo
#include <Ultrasonic.h>  //libreria para control de sensor ultrasonico
Servo myservo; //nombre de el servo3
Ultrasonic ultraizquierdo(trig1,echo1);   //nombre de sensor ultrasonico
Ultrasonic ultrafrontal(trig2,echo2);     //nombre de sensor ultrasonico
Ultrasonic ultraderecho(trig3,echo3);     //nombre de sensor ultrasonico

void setup() {
Serial.begin(9600);
myservo.attach(servo);
pinMode(LEDindicador,OUTPUT);
pinMode(pulsador,INPUT);
pinMode(boton,INPUT);
pinMode(I1,OUTPUT);
pinMode(I2,OUTPUT);
pinMode(I3,OUTPUT);
pinMode(I4,OUTPUT);
pinMode(cny1,INPUT);
pinMode(cny2,INPUT);
myservo.write(90);

}
void adelante(){
  digitalWrite(I1,HIGH);
  digitalWrite(I2,LOW);
  digitalWrite(I3,HIGH);
  digitalWrite(I4,LOW);
}
void atras(){
  digitalWrite(I1,LOW);
  digitalWrite(I2,HIGH);
  digitalWrite(I3,LOW);
  digitalWrite(I4,HIGH);
}
void rotarderecha(){
  digitalWrite(I1,HIGH);
  digitalWrite(I2,LOW);
  digitalWrite(I3,LOW);
  digitalWrite(I4,HIGH);
}
void rotarizquierda(){
  digitalWrite(I1,LOW);
  digitalWrite(I2,HIGH);
  digitalWrite(I3,HIGH);
  digitalWrite(I4,LOW);
}
void doblarderecha(){
  digitalWrite(I1,HIGH);
  digitalWrite(I2,LOW);
  digitalWrite(I3,LOW);
  digitalWrite(I4,LOW);
}
void doblarizquierda(){
  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(I3,HIGH);
  digitalWrite(I4,LOW);
}
void detener(){
  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(I3,LOW);
  digitalWrite(I4,LOW);
}
void loop() {
estadopulsador=digitalRead(pulsador);
if(estadopulsador==HIGH){
delay(5000);
while(1){
valultraderecho = ultraderecho.read(CM);
valultrafrontal = ultrafrontal.read(CM);
valultraizquierdo = ultraizquierdo.read(CM);
Serial.print(valultraderecho);Serial.println("   ");
Serial.print(valultrafrontal);Serial.println("   ");
Serial.print(valultraizquierdo);Serial.println("   ");
if(valultrafrontal<25) {adelante();}
if(valultraderecho<25) {girar=HIGH;rotarderecha();}
if(valultraizquierdo<25) {girar=HIGH;rotarizquierda();}
if(valultrafrontal>25 && valultraderecho>25 && valultraizquierdo>25){
if(girar==LOW){rotarizquierda();}
else{rotarderecha();}
}
}
}

}

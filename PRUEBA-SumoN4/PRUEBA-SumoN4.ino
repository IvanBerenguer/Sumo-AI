#include <Servo.h>
#include <Ultrasonic.h>
#include <SPI.h>
Servo cerbo;

#define pulsador 13 
#define boton 12
#define I4 11
#define I3 10
#define I2 9
#define I1 8
#define led 5 
#define servo 4 
#define trigger 3 //sensor izq
#define echo 2 //sensor izq
#define echo2 A5 //sensor frontal
#define trigger2 A4 //sensor frontal
#define echo3 A3 //sensor der
#define trigger3 A2 //sensor der

void setup() {
  // put your setup code here, to run once:
cerbo.attach(4);
pinMode(5,INPUT);//led
pinMode(13,OUTPUT);//pulsador
Serial.begin(9600);
Serial.begin("menu de prueba");
Serial.println("presiona 1 para control led");
Serial.println("presiona 2 para control cerbo");
Serial.println("presiona 3 para control ultrasonido");
Serial.println("presiona 4 para control motores");
Serial.println("presiona 5 para  control pulsador");
Serial.println("presiona 6 para control boton");


}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
char j=Serial.read();
  switch(j){
    case '1':("probando led 13");break;
    case '2':("probar cerbo");break;
    case '3':("probar ultrasonido");break;
    case '4':("probar Servo");break;
    case '5':("probar pulsador");break;
    case '6':("probar boton");break;
   default: {if(j!='\n'){Serial.println("intentalo de nuevo, comando desconocido");}}break;
  }
 }
}
 
void controlpulsador(){
  Serial.println("Controlando pulsador");
  if(digitalRead(pulsador)){
    Serial.println("Pulsador Prendido");
  }
  else{
  Serial.println("Pulsador apagado");
  }
  Serial.println("control terminado");
 }

 
 void controlboton(){
  Serial.println("Controlando boton");
  if(digitalRead(boton)){
    Serial.println("boton Prendido");
  }
  else{
  Serial.println("boton apagado");
  }
  Serial.println("control terminado");
 }

void controlservo(){
  Serial.println("Controlando Servo");
  cerbo.write(0);
  delay(500);
  cerbo.write(180);
  Serial.println("Servo funciona");
}
  void controlled(){
  Serial.println("Controlando led");
  digitalWrite(led, HIGH);
  delay(600);
  digitalWrite(led, LOW);
  Serial.println("led funciona");

  }
  
void adelante() {
  digitalWrite (I1,HIGH);
  digitalWrite (I2,LOW);
  digitalWrite (I3,HIGH);
  digitalWrite (I4,LOW);

}
void atras() {
  digitalWrite (I1,LOW);
  digitalWrite (I2,HIGH);
  digitalWrite (I3,LOW);
  digitalWrite (I4,HIGH);

}
void derecha() {
  digitalWrite (I1,HIGH);
  digitalWrite (I2,LOW);
  digitalWrite (I3,HIGH);
  digitalWrite (I4,LOW);
 
}
void izquierda() {
  digitalWrite (I1,HIGH);
  digitalWrite (I2,LOW);
  digitalWrite (I3,HIGH);
  digitalWrite (I4,LOW);

}

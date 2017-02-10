#include <Servo.h>
Servo head;

int pos = 0;
int rgbb= 12;
int rgbr= 11;
int led = 13;

void setup() {
  head.attach(8);
  pinMode(rgbb, OUTPUT);
  pinMode(rgbr, OUTPUT);
  pinMode(led ,OUTPUT);
  Serial.begin(9600);
  randomSeed(3);
}
void leds(){
  int ledrand;
  ledrand = random(1,4);
  switch(ledrand){
    case 1:
      digitalWrite(rgbb,HIGH);
      digitalWrite(rgbr,LOW);
      break;
    case 2:
      digitalWrite(rgbr,HIGH);
      digitalWrite(rgbb, LOW);
      break;
    default:
      digitalWrite(rgbr,HIGH);
      digitalWrite(rgbb,HIGH);
      break;
  }
  delay(3500);
}
void servoHead(){
  int ran;
  ran=random(1,26);
  Serial.print("Numero random --> ");
  Serial.println(ran);
  if(ran >= 1 && ran <=5){   //nada
    for (pos = 90; pos <= 2; pos++) {
      head.write(pos); 
      delay(20);
    }
    for (pos = 2; pos >= 90; pos--) {
      head.write(pos);
      delay(20);
    }
  }
  if(ran >= 6 && ran <=10){  //derecha
    for (pos = 90; pos <= 180; pos++) {
      head.write(pos); 
      delay(10);
    }
    for (pos = 0; pos >= 90; pos--) {
      head.write(pos);
      delay(10);
    }
  }
  if(ran >= 11 && ran <= 15){  //izquierda
  
    for (pos = 90; pos <= 180; pos++) {
      head.write(pos); 
      delay(10);
    }
    for (pos = 180; pos >= 90; pos--) {
      head.write(pos);
      delay(10);
    }
  }
  if(ran >= 16 && ran <= 20){   //lados rapido
    for (pos = 90; pos <= 180; pos++) {
      head.write(pos); 
      delay(5);
    }
    for (pos = 180; pos >= 45; pos--) {
      head.write(pos);
      delay(5);
    }
  }
  if(ran >= 21 && ran <= 25){   //lados lento
    for (pos = 90; pos <= 180; pos++) {
      head.write(pos); 
      delay(20);
    }
    for (pos = 180; pos >= 0; pos--) {
      head.write(pos);
      delay(20);
    }
  }
  delay(1000);
}
void loop() {
  digitalWrite(led,HIGH);
  servoHead(); 
  leds();
 
}


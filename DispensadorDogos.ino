#include <HID.h>
#include <HID.h>
#include <Servo.h>
#include <CountUpDownTimer.h>
#include <LiquidCrystal.h>


CountUpDownTimer T(DOWN);
Servo myservo; 
int LDR1 = A0;
int infrarred = A1;
const int sensorPin = 9;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Pines de la pantalla

int buzzer = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Declaracion de la pantalla
int var= 0;
int delayprev = 500;

void setup() {
  lcd.begin(16, 2);
  myservo.attach(6);  
  Serial.begin(9600);
  pinMode(sensorPin , INPUT);  
  pinMode(LDR1, INPUT);
  myservo.write(160);
  pinMode(buzzer,OUTPUT);


  T.SetTimer(0,1,10);
  T.StartTimer();


}

void loop() {
T.Timer(); // run the timer
int  value1= analogRead(LDR1);    //Lee los valores de las LDR
int  value2= analogRead(infrarred);

if (T.TimeHasChanged() ){ //Mientras el tiempo vaya cambiando se va imprimiendo en la pantalla

  lcd.print(T.ShowMinutes());
  lcd.print(":");
  lcd.print(T.ShowSeconds());
  delay(500);
  lcd.clear();



}

if(value1 <300 && T.TimeCheck(0,1,0)){ // si el sensor de abajo entra luz y es la hora de la comida, se reduce el delay del motor
  delayprev = 10;

}
else
delayprev = 800; //Delay normal




if(T.TimeCheck(0,1,0)){ //Si es la hora de la comida
  delay(delayprev);
  myservo.write(90);
  delay(delayprev);
  myservo.write(160);
  tone(buzzer, 1000); 
  delay(1000);        
  noTone(buzzer);     
  delay(1000);

  T.ResetTimer();
}

if(value2 > 20 && var == 0){ //Si el sensor de arriba le entra luz significa que ya no hay comida y envia mensaje
  delay(100);
  Serial.println("ahi va el mensaje paps");
  delay(100);
  
  var++;
}










}

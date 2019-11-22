
/*
Projeto Arduino Guia Inteligente
João Machado, José Américo e Rafael Barthes
*/

#include<Servo.h>
Servo servo;

int const trigPin = 6;
int const echoPin = 5;
int Buzzer = 8;//buzzer no pino 8 digital
int Vibracall = 9;
void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);   
pinMode(Buzzer, OUTPUT);  
pinMode(Vibracall, OUTPUT);  
servo.attach(3);

}
void loop()
{       
int duration, distance;
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
if (distance >= 30 || distance <= 0) {  //distancia que o sensor usará como retorno de objeto para guia
  
        servo.write(30);    
        delay(300);
        digitalWrite(Buzzer,LOW);
         digitalWrite(Vibracall,LOW);
        
} 
else {   
      servo.write(160);
      tone(Buzzer,400,150); 
      delay(10);
      digitalWrite(Vibracall,HIGH);
      
     
}
}

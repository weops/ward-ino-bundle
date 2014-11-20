/*HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

const int trigPin [] = {13,11};
const int echoPin [] = {12,10};
int x = 0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin[0], OUTPUT);
  pinMode(echoPin[0], INPUT);
  pinMode(trigPin[1], OUTPUT);
  pinMode(echoPin[1], INPUT);

}

void loop() {
  Serial.print(x);
  Serial.print(" :");
  long duration, distance;
  digitalWrite(trigPin[x], LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin[x], HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin[x], LOW);
  duration = pulseIn(echoPin[x], HIGH);
  distance = (duration/2) / 29.1;
//  if (distance < 4) {  // This is where the LED On/Off happens
//    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
//  digitalWrite(led2,LOW);
//}
//  else {
//    digitalWrite(led,LOW);
//    digitalWrite(led2,HIGH);
//  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  if(x<1){
    x++;
  }
  else{
    x=0;
  }
  delay(100);
}


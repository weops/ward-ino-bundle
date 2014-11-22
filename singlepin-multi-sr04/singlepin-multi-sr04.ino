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

const int tarPin [] = {13};
int tarSize = 0;

void setup() {
  Serial.begin (9600);
  Serial.print("Single Pin Multi Sr04 Loaded");
  tarSize = sizeof(tarPin)/sizeof(int);
}

void loop() {
  for(int i=0; i<tarSize; i++){
    pinMode(tarPin[i], OUTPUT);
    Serial.print(i);
    Serial.print(" : ");
    long duration, distance;
    //settle pin
    digitalWrite(tarPin[i], LOW); 
    delayMicroseconds(2); 
    //send high pulse for 10us
    digitalWrite(tarPin[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(tarPin[i], LOW);
    //reverse polarity and read
    pinMode(tarPin[i], INPUT);
    duration = pulseIn(tarPin[i], HIGH);
    //calculate distance
    distance = (duration/2) / 29.1;
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    } else {
      Serial.print(distance);
      Serial.println("cm");
    }
    delay(100);
  }
  delay(1000);
}


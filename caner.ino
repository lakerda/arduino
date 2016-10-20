

#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
 
#define trigPin 13
#define echoPin 12
#define maxRange 100
#define minRange 0

long getCm()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  distance = ( distance > maxRange ) ? maxRange: distance;
  distance = ( distance < minRange ) ? minRange: distance;
  return distance;
}


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  //Serial.println("Goodnight moon!");

 
}

void loop() {
  for (pos = 1; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  
    Serial.print(pos); Serial.print( " "); Serial.println(getCm());// tell servo to go to position in variable 'pos'
    delay(30);      
    // waits 15ms for the servo to reach the position
  
  }
  for (pos = 180; pos > 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.print(pos); Serial.print( " "); Serial.println(getCm());
    delay(30);                       // waits 15ms for the servo to reach the position

  }
  
 
}


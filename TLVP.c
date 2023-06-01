// variables
int redLed = 7;
int yellowLed = 4;
int greenLed = 2;
const int trigPin = 10;
const int echoPin = 11;
int duration;
int distance;

// yellow light function
void checkDistanceYellow(){
  digitalWridefiningte(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

  if(distance < 15){
    tone(13,2000);
  }
  else{
   noTone(13);
  }
}

// green light function
void checkDistanceGreen(){

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

  if(distance < 15){
   tone(13, 3000);
  }
  else{
   noTone(13);
  }

}
//red light function
void checkDistanceRed(){

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;



  if(distance < 15){
    tone(13,1500);
    delay(80);
    noTone(13);
    delay(80);
  }
  else{
   noTone(13);
  }
}

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(7 , OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

  digitalWrite(redLed, HIGH);

  for(int x=0; x< 70; x++){
    checkDistanceRed();
  }
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed,HIGH);  
  
  for(int y=0; y<500; y++){
    checkDistanceYellow();
    delay(1);
}

  digitalWrite(yellowLed, LOW);

  digitalWrite(greenLed, HIGH);

  for(int z= 0; z<900; z++){
    checkDistanceGreen();
    delay(1);
 }
  digitalWrite(greenLed, LOW);
}
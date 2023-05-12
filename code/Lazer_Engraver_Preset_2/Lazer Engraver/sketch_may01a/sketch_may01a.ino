// defines pins
#define inputPin 6
#define laserPin 11
 
void setup() {
  //initilize pins
  pinMode(inputPin,INPUT); 
  pinMode(laserPin,OUTPUT);
  //set up printing for debugging
  Serial.begin(9600);
}
void loop() {
  //see if recieved an input
  if(digitalRead(inputPin) == HIGH){
    //turn on the laser
    Serial.print("laser on\n");
    digitalWrite(laserPin, HIGH);
  }
  else{
    //turn the laser off it no input signal
    Serial.print("laser off\n");
    digitalWrite(laserPin,LOW);
  }
  }

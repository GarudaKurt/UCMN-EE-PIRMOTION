int ledPin = 13; 
int inputPin = 8;     
int inputPin1 = 7;          
int pirState = LOW;    
int pirState1 = LOW;          
int val = 0;      
int val1 = 0;              
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);     
  pinMode(inputPin1, INPUT);
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);
  val1 = digitalRead(inputPin1);
  if (val == HIGH || val1 == HIGH)
  {            
    digitalWrite(ledPin, HIGH); 
	
    if (pirState == LOW || pirState1 == LOW) 
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
      pirState1 = HIGH;
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW);
	
    if (pirState == HIGH || pirState1 == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
      pirState1 = LOW;
    }
  }
}
float temp = 0.0;
int led = 4;
int ledOff = 5;
  bool valveOn = false;

void setup()
{
  Serial.begin(9600);

                            
  pinMode(2, INPUT_PULLUP); 
  pinMode(3, INPUT_PULLUP); 
  pinMode(led, OUTPUT);
  pinMode(ledOff, OUTPUT);
  
}

void loop()
{
  int b1 = digitalRead(2);
  int b2 = digitalRead(3);


  Serial.println(temp);
  
  

  if (b1 == HIGH) temp = temp + 1;
  delay(100);
  if (b2 == HIGH) temp = temp - 1;
  delay(100);
 

    valveHeating(temp);
//    if(temp == 1 && valveOn == true) { 
//      valveOn = false;
//    }
}

void valveHeating(float temp) { 

  if(temp >= 1 && temp <= 4) {
    digitalWrite(led, HIGH);
    digitalWrite(ledOff, LOW);
    valveOn = true;
  } else {
    digitalWrite(led, LOW);
    digitalWrite(ledOff, HIGH);
    
  }



  Serial.println(valveOn);
}

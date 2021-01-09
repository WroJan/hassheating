float temp = 0.0;
int led = 4;

void setup()
{
  Serial.begin(9600);

                            
  pinMode(2, INPUT_PULLUP); 
  pinMode(3, INPUT_PULLUP); 
  pinMode(led, OUTPUT);
}

void loop()
{
  int b1 = digitalRead(2);
  int b2 = digitalRead(3);


  Serial.println(temp);
  

  if (b1 == HIGH) temp = temp + 0.5;
  delay(100);
  if (b2 == HIGH) temp = temp - 0.5;
  delay(100);
 

    valveHeating(temp);
}

void valveHeating(float temp) { 

  if(temp >= 1 && temp <= 3) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

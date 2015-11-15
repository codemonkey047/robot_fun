const char leftFwd=4;
const char leftRev=5;
const char rightFwd=2;
const char rightRev=3;

void setup() {
  Serial.begin(4800);
  
  pinMode(leftFwd,OUTPUT);
  pinMode(leftRev,OUTPUT);
    digitalWrite(leftFwd,HIGH);
    digitalWrite(leftRev,LOW);  
}

void loop() {
  Serial.println("Forward");
  drive(1,0);
  delay(2000);
  
  Serial.println("Reverse");
  drive(-1,0);
  delay(2000);
}


void drive(short dir, short turn)
{
  drive(leftFwd,leftRev,dir+turn);
  drive(rightFwd,rightRev,dir-turn);
}

void drive(char pinFwd, char pinRev, short wheelDir)
{
  if (wheelDir>0)
  {
    digitalWrite(pinFwd,HIGH);
    digitalWrite(pinRev,LOW); 
  }else if (wheelDir<0)
  {
    digitalWrite(pinFwd,LOW);
    digitalWrite(pinRev,HIGH);
  }else
  {
    digitalWrite(pinFwd,LOW);
    digitalWrite(pinRev,LOW);  
  }
}

void dispAnalogRead(int pin)
{
  Serial.println(analogRead(pin)*5.0/1023);
}



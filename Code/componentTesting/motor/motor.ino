const char leftFwd=5;
const char leftRev=4;
const char rightFwd=2;
const char rightRev=3;

void setup() {
  Serial.begin(4800);
  
  pinMode(leftFwd,OUTPUT);
  pinMode(leftRev,OUTPUT);
  digitalWrite(leftFwd,HIGH);
  digitalWrite(leftRev,LOW);  
  
  pinMode(rightFwd,OUTPUT);
  pinMode(rightRev,OUTPUT);
  digitalWrite(rightFwd,HIGH);
  digitalWrite(rightRev,LOW);
}

void loop() {
  Serial.println("Forward");
  drive(1,0);
  delay(5000);
  
  Serial.println("Reverse");
  drive(-1,0);
  delay(5000);

  Serial.println("Right Turn");
  drive(0,1);
  delay(5000);

  Serial.println("Left Turn");
  drive(0,-1);
  delay(5000);
  
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



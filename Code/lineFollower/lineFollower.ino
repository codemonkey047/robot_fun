const char leftFwd=5;
const char leftRev=4;
const char rightFwd=2;
const char rightRev=3;
const double rightThresh=1.0;
const double leftThresh=0.4;
const char leftLight=9;
const char rightLight=10;

void setup() {
  Serial.begin(4800);
  
  pinMode(leftFwd,OUTPUT);
  pinMode(leftRev,OUTPUT);
  digitalWrite(leftFwd,LOW);
  digitalWrite(leftRev,LOW);  
  
  pinMode(rightFwd,OUTPUT);
  pinMode(rightRev,OUTPUT);
  digitalWrite(rightFwd,LOW);
  digitalWrite(rightRev,LOW);

  pinMode(leftLight,OUTPUT);
  pinMode(rightLight,OUTPUT);  
}

void loop() {
  adjust(readAnalogToV(0),readAnalogToV(1));
  delay(5);  
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

double readAnalogToV(int pin)
{
  return analogRead(pin)*5.0/1023;
}

void adjust(double rightV, double leftV)
{
  double rightDiff=rightV-rightThresh;
  double leftDiff=leftV-leftThresh;
  if (rightDiff>0)
  {  
    digitalWrite(rightLight,HIGH);  
    if (leftDiff>0)
    {
      digitalWrite(leftLight,HIGH);
      
      //No line detected!
      if ((rightDiff/rightThresh)<(leftDiff/leftThresh))
      {
         drive(0,1); //Right
      }
      else{
        drive(0,-1); //Left
      }
    }
    else
    {
      drive(0,-1); //Left
      digitalWrite(leftLight,LOW);
    }
  }
  else
  {
    digitalWrite(rightLight,LOW);
    if (leftDiff>0)
    {
      drive(0,1); //Right
      digitalWrite(leftLight,HIGH);
    }
    else
    {
      
      drive(1,0); //Forward
      digitalWrite(leftLight,LOW);
    }
  }
}



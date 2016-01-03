double rightThresh=1.0;
double leftThresh=0.4;

void setup() {
  Serial.begin(4800);
}

void loop() {
  adjust(readAnalogToV(0),readAnalogToV(1));
  delay(100);

}

double readAnalogToV(int pin)
{
  return analogRead(pin)*5.0/1023;
}

void adjust(double rightV, double leftV)
{
  Serial.println(leftV);
  double rightDiff=rightV-rightThresh;
  double leftDiff=leftV-leftThresh;
  if (rightDiff>0)
  {
    if (leftDiff>0)
    {
      Serial.println("forward");
    }
    else
    {
      Serial.println("left");
    }
  }
  else
  {
    if (leftDiff>0)
    {
      Serial.println("right");
    }
    else
    {
      Serial.println("forward");
    }
  }
}



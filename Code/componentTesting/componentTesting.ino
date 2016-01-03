double val=0;
double val1 = 0;

void setup() {
  Serial.begin(4800);
}

void loop() {
  val=analogRead(0)*5.0/1023;
  val1=analogRead(1)*5.0/1023;
  Serial.println(val);
  Serial.println(val1);
  delay(100);
}


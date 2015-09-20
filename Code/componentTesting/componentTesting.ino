double val=0;

void setup() {
  Serial.begin(4800);
}

void loop() {
  val=analogRead(0)*5.0/1023;
  Serial.println(val);

}

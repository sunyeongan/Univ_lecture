void setup() {
  Serial.begin(9600);    // 시리얼포트를 연다
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int incomingByte = Serial.read();
    if(incomingByte == '1')
    {
      digitalWrite(LED_BUILTIN, HIGH);//(HIGH is the voltage level)
      Serial.print("On");
    }
    else if(incomingByte == '0')
    {
      digitalWrite(LED_BUILTIN, LOW); //making the voltage LOW
      Serial.print("Off");
    }
  }
  
}

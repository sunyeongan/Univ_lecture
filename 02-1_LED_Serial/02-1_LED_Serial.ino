#include <SoftwareSerial.h>

 
SoftwareSerial BTSerial(4, 5);

 
void setup() {

  BTSerial.begin(9600);    // 시리얼포트를 연다

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

}

 

void loop() {

  if (BTSerial.available()) {

    int incomingByte = BTSerial.read();

    

    if(incomingByte == '1')

    {

      digitalWrite(LED_BUILTIN, HIGH);//(HIGH is the voltage level)

      Serial.println("ON");

    }

    else if(incomingByte == '0')

    {

      digitalWrite(LED_BUILTIN, LOW); //making the voltage LOW

      Serial.println("OFF");

 

    }

  }

  

}

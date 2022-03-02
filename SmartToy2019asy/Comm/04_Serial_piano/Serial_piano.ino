int melody = 0;    // for incoming serial data
#include "pitches.h"
int speakerpin = 12; //스피커가 연결된 디지털핀 설정

int note[] = {3822,3405,3034,2863,2551,2408,2273,2025,1910,1703,1607,1517,1432,1276,1136,1012,2093,2349,2637,2793,3136,3520,3951,4186}; //도레미

void setup() {

    Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps

}

 

void loop() {

   pinMode(LED_BUILTIN, OUTPUT);

  // send data only when you receive data:

  if (Serial.available() > 0) {

  

    // read the incoming byte:

    melody = Serial.read();

    if(melody == 'k'){ 

      tone(speakerpin,659,500);

      Serial.print("k");//미

       

    }

    else if(melody == 'u'){

      tone(speakerpin,622.37,500);

      Serial.print("u");

    }

     else if(melody == 'g'){

      tone(speakerpin,493,500);

      Serial.print("g");

    }

     else if(melody == 'h'){

      tone(speakerpin,587,500);
      Serial.print("h");
     

    }

     else if(melody == 'j'){

      tone(speakerpin,523,500);
      Serial.print("j");
     

    }

     else if(melody == 'a'){

      tone(speakerpin,440,500);
      Serial.print("a");
     

    }

     else if(melody == 's'){

      tone(speakerpin,261,500);
      Serial.print("s");

     

    }

     else if(melody == 'd'){

      tone(speakerpin,329,500);
      Serial.print("d");
     

    }
    else if(melody == 'f'){

      tone(speakerpin,415,500);
      Serial.print("f");
     

    }
    else if(melody == 'r'){

      tone(speakerpin,329,500);
      Serial.print("r");
     

    }

    

    

    

    //incomingByte =incomingByte+1;

    // say what you got:

    Serial.print((char)melody);

  }

  

}

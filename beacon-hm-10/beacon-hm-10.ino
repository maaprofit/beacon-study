#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);

long bauds[] = {
    // major 
    9600, 57600, 115200,
    
    // others
    19200, 38400, 4800, 2400, 1200, 230400
  };

bool detectBleBaudRate() {
  Serial.println("Detecting BLE baud rate:");
  for (int i=0; i < (sizeof(bauds)/sizeof(long)); i++) {
    Serial.write("Checking ");
    long cur_baud = bauds[i];
    Serial.println(cur_baud, DEC);
    
    mySerial.begin(cur_baud);
    mySerial.write("AT");
    mySerial.flush();
    delay(50);
    String response = mySerial.readString();
    
    if (response == "OK") {
      Serial.println("Detected");
      return true;
    } else {
      mySerial.end();
    }
  }
  
  return false;
}

void setup() {
  Serial.begin(115200);
  detectBleBaudRate();

   // pinMode(5, OUTPUT);
   // digitalWrite(5, HIGH);
   
  // mySerial.begin(19200);
  // Serial.println("Enter AT commands:");
}

void loop() {
  char c;
  if (Serial.available()) {
    c = Serial.read();
    mySerial.write(c);
  }
  
  if (Serial.available()) {
    c = mySerial.read();
    Serial.write(c);
  }
}

#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);

// Serial value
String val;

// Bauds for detectBleBaudRate function
long bauds[] = {
    // major 
    9600, 57600, 115200,
    
    // others
    19200, 38400, 4800, 2400, 1200, 230400
};

// Detect BLE Baud Rate
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
      Serial.print(response);
      return true;
    } else {
      mySerial.end();
    }
  }

  detectBleBaudRate();
}

// Uncomment function to wake up bluetooth or discover BLE Baud Rate
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  // detectBleBaudRate();
}

// Reads strings that are sent to mySerial
void loop() {
  while (Serial.available() > 0) {
     delay(10); // Delay needed to recognize key and value properly
     String val = Serial.readString();
     Serial.print("Serial sent: ");
     Serial.println(val);
     
     mySerial.print(val);
     mySerial.flush();

     delay(50);

     String response = mySerial.readString();
     Serial.print("mySerial received: ");
     Serial.println(response);
  }
}

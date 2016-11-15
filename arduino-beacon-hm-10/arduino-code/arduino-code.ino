#include <SoftwareSerial.h>

// SoftwareSerial (TX / RX)
SoftwareSerial mySerial(7, 8);

// Serial value
String val;

// Receive info 
boolean receiveInfo = false;

// Bauds for detectBleBaudRate function
long bauds[] = {
    // major 
    9600, 57600, 115200,
    
    // others
    19200, 38400, 4800, 2400, 1200, 230400
};

// Detect BLE Baud Rate
bool detectBleBaudRate() {
  Serial.println("-----------------------------");
  Serial.println("Detecting BLE baud rate:");
  
  for (int i=0; i < (sizeof(bauds) / sizeof(long)); i++) {
    Serial.write("Checking baud rate: ");
    // Checking baud rate
    long cur_baud = bauds[i];
    Serial.println(cur_baud, DEC);
    
    mySerial.begin(cur_baud);
    mySerial.write("AT");
    mySerial.flush();

    delay(50);

    String response = mySerial.readString();
    
    if (response == "OK") {
      Serial.println("-----------------------------");
      Serial.print("BLE Baud Detected: ");
      Serial.println(cur_baud);
      Serial.println("-----------------------------");
      
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
}

void wakeUp() {
  Serial.println("-----------------------------");
  for (int i = 0; i < 30; i++) {
     mySerial.write("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
  }
  
  Serial.println("Wake up command has been sent to HM-10");
  Serial.println("-----------------------------");
}

// Reads strings that are sent to mySerial
void loop() {
  while (Serial.available() > 0) {
     delay(10); // Delay needed to recognize key and value properly
     
     String val = Serial.readString();
     Serial.print("Serial sent: ");
     Serial.println(val);
     
     // Receive info from HM-10
     receiveInfo = true;
     
     // If you need to wake up the HM-10 sensor, send wake command
     if (val == "wake") {
        wakeUp();
        receiveInfo = false;
     }
     
     // If you want to detect BLE Baud Rate, send detect command
     if (val == "detect") {
        detectBleBaudRate();
        receiveInfo = false; 
     }
     
     mySerial.print(val);
     mySerial.flush();

     delay(50);

     if (receiveInfo) {
         // Read string from HM-10 (Software Serial)
         String response = mySerial.readString();
         
         Serial.print("mySerial received: ");
         Serial.println(response);
         
         Serial.println("-----------------------------");
     }
  }
}
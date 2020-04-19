#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo myservo[2];
Servo mys;

RF24 radio(10,9); // CE, CSN
char secret='A';

const byte address[6] = "00001";
void setup() {
          Serial.setTimeout(100);

  Serial.begin(2000000);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
  pinMode(LED_BUILTIN,OUTPUT);

       
        for (int p = 8; p < 10; p++)
        {
           // pinMode(p, OUTPUT);
            //myservo[p-8].attach(p);
        }
mys.attach(9);
            Serial.println("Locked and Loaded");

}
  unsigned long time_now = 0;
  //pinId1:val1&pinId2:val2&
  
  char SEP1=':';
  char SEP2='&';
  char END='$';
  char START='A';
  int pins[13];
  int pinValue[13];
  
void loop() {

  //mys.write(0);    
 // delay(600);
 // mys.write(100);
    delay(100);
//  time_now = millis();  
//
  if (radio.available()>0) {
    char data[64];
    radio.read(&data, sizeof(data));
    if (data[0]!=START){
      return;
    }
    
    Serial.println("received msg=");
    Serial.println(data);
    //delay(500);

            int pin=0;
            int val=0;
            String pinS, valS;
            int maxIndex = sizeof(data);
 Serial.print("maxIndex:");
                        Serial.println(maxIndex);
            for (int i = 1; i < maxIndex ; i++) {
                char ch=data[i];
                 if (ch == END) {
                    break;
                 }
                if (ch == SEP1) {
                    pin=pinS.toInt();

                    pinS="";
                    valS="";

                    continue;
                }
                pinS=pinS+ch;

                if (ch == SEP2) {
                    val=valS.toInt();
                    pins[pin]=val;
                     //analogWrite(pin, val);
                    myservo[pin].write(val);
                    mys.write(val);
                    pinS="";
                    valS="";
                        Serial.print("Pin:");
                        Serial.println(pin);
                        Serial.print("Val:");
                        Serial.println(val);                                           
                        Serial.println();
                    continue;
                }
                valS=valS+ch;            }

  } 
}

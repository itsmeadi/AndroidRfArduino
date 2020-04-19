#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(10,9); // CE, CSN
const byte address[6] = "00001";
void(* resetFunc) (void) = 0;
void setup() {

//  radio.setRetries(2, 8);
  //radio.setAutoAck(true);
        Serial.setTimeout(100);

  Serial.begin(2000000);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);

  radio.stopListening();
//radio.printDetails();
}

String secret="A";
char sendData[32];
void loop() {


  if (Serial.available()>0){
    String data=Serial.readString();
    int dataLen=sizeof(sendData);
    int sendDataLen=32>dataLen?dataLen:32;
    for(int i=0;i<32;i++){
      sendData[i]=data.charAt(i);
    }
    Serial.print("Sending ");
    Serial.println(data);
    radio.write(&sendData, dataLen);
  
  }
  
}

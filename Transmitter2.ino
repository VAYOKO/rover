
 #include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
     
int upbt = 4;
int downpbt = 5;
int leftpbt = 3;
int rightpbt = 2;
boolean ubt = 0;
boolean dbt = 0;
boolean rbt = 0;
boolean lbt = 0;
void setup() {
Serial.begin(9600);
pinMode(upbt,INPUT);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();       
}
 
void loop() {
ubt = digitalRead(upbt);
dbt = digitalRead(downpbt);
rbt = digitalRead(rightpbt);
lbt = digitalRead(leftpbt);

if(ubt == HIGH)
{
const char text[] = "up";
radio.write(&text, sizeof(text));                  //Sending the message to receiver

}

if(dbt == HIGH)
{
const char text[] = "down";
radio.write(&text, sizeof(text));                  //Sending the message to receiver

}

if(rbt == HIGH)
{
const char text[] = "right";
radio.write(&text, sizeof(text));                  //Sending the message to receiver

}

if(lbt == HIGH)
{
const char text[] = "left";
radio.write(&text, sizeof(text));                  //Sending the message to receiver

}
else
{
const char text[] = " nan ";
radio.write(&text, sizeof(text));                  //Sending the message to receiver 
}

radio.write(&ubt, sizeof(ubt));  //Sending the message to receiver
radio.write(&dbt, sizeof(dbt));  //Sending the message to receiver
radio.write(&rbt, sizeof(rbt));  //Sending the message to receiver
radio.write(&lbt, sizeof(lbt));  //Sending the message to receiver 

}

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 #include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
unsigned long previousMillis = 0;      
int rightbt = 2;
int leftbt = 3;
int upbt = 4;
int downbt = 5;
boolean rbt = 0;
boolean lbt = 0;
boolean ubt = 0;
boolean dbt = 0;
#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 
 
// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
void setup() {
Serial.begin(9600);


if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
Serial.println("SSD1306 allocation failed");
} else {
Serial.println("ArdinoAll OLED Start Work !!!");
}

OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
OLED.display();
OLED.setTextColor(WHITE, BLACK); //กำหนดข้อความสีขาว ฉากหลังสีดำ
OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
OLED.println("PGTR-1"); // แสดงผลข้อความ ALL\
 
 
OLED.display(); // สั่งให้จอแสดงผล
pinMode(leftbt, INPUT);
pinMode(rightbt, INPUT);
pinMode(upbt, INPUT);
pinMode(downbt, INPUT);
radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();       
}
 
void loop() {
rbt = digitalRead(rightbt);
lbt = digitalRead(leftbt);
dbt = digitalRead(downbt);
ubt = digitalRead(upbt);

if(ubt == HIGH)
{
  Serial.println("up");
const char text[] = "up";
radio.write(&text, sizeof(text));                  //Sending the message to receiver


}
else if(dbt == HIGH)
{
  
  Serial.println("down");
const char text[] = "down";
radio.write(&text, sizeof(text));                  //Sending the message to receiver
}
else if(lbt == HIGH)
{
  
  Serial.println("left");
const char text[] = "left";
radio.write(&text, sizeof(text));                  //Sending the message to receiver
}



else if(rbt == HIGH)
{
  
  Serial.println("right");
const char text[] = "right";
radio.write(&text, sizeof(text));                  //Sending the message to receiver
}
else
{
const char text[] = " nan ";
radio.write(&text, sizeof(text));                  //Sending the message to receiver 
}



radio.write(&ubt, sizeof(ubt));  //Sending the message to receiver 
radio.write(&dbt, sizeof(dbt));  //Sending the message to receiver 
radio.write(&lbt, sizeof(lbt));  //Sending the message to receiver 
radio.write(&rbt, sizeof(rbt));  //Sending the message to receiver 
delay(5);

}

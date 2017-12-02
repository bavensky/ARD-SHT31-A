/*
 SHT31-ARP Analog Humidity & Temperature Sensor Example Code 
 ClosedCube SHT31-A [Analog] Humidity and Temperature Sensor Breakout 

 This is standalone Arduino example (no external library is required)

 Initial Date: 10-Sep-2015

 MIT License

 Hardware connections for Arduino Uno:
   VDD to 3.3V DC
   T to A0
   RH to A1
   GND to common groud

 */

const float VDD = 5;
const int PIN_T  = A0;  
const int PIN_RH = A1;  

float t  = 0.0;
float rh = 0.0;

void setup() {
  Serial.begin(9600);
  Serial.println("SHT31-A"); 
}

void loop() {
  int tValue = analogRead(PIN_T);
  int rhValue = analogRead(PIN_RH);

  t = -66.875+218.75*(tValue*0.0049)/VDD; 
  rh = -12.5+125*(rhValue*0.0049)/VDD;
  
  Serial.print("T=");
  Serial.print(t);
  Serial.print("C, RH=");
  Serial.print(rh);
  Serial.println("%");
  
  delay(200);
}

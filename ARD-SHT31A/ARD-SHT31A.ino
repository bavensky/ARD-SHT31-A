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
float f  = 0.0;
float rh = 0.0;

void setup() {
  Serial.begin(9600);
  Serial.println("SHT31-A"); 
}

void loop() {
  int tValue = analogRead(PIN_T);
  int rhValue = analogRead(PIN_RH);

  t = -66.875+218.75*(tValue*0.0049)/VDD;   // equation : -66.875+218.75*(Vt/Vdd)   | Vt = analogT*0.0049 (1023*0.0049=5V)
  f = -88.375+393.75*(tValue*0.0049)/VDD;   // equation : -88.375+393.75*(Vt/Vdd)   | Vt = analogT*0.0049
  rh = -12.5+125*(rhValue*0.0049)/VDD;      // equation : -12.5+125*(Vrh/Vdd)       | Vrh = analogRH*0.0049 
  
  Serial.print("T=");
  Serial.print(t);
  Serial.print("C, T=");
  Serial.print(f);
  Serial.print("F, RH=");
  Serial.print(rh);
  Serial.println("%");
  
  delay(200);
}

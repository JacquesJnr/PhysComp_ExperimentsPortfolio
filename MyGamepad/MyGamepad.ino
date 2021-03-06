#include <Joystick.h>

Joystick_ Joystick;
int rX = 0;
int rY = 0;
int lX = 0;
int lY = 0;

bool A, B, X, Y;
const bool initAutoSendState = true;

void setup() {
  Serial.begin(9600);
  
  pinMode(7, INPUT_PULLUP); // Left Shoulder button
  pinMode(6, INPUT_PULLUP); // Right Shoulder button
  pinMode(8,OUTPUT); // LED
  pinMode(9,INPUT_PULLUP);// Start Button
  pinMode(10,INPUT_PULLUP);// Left Button 1
  pinMode(11,INPUT_PULLUP); // Left Button 2
  pinMode(12,INPUT_PULLUP); // Right Button 1
  pinMode(13,INPUT_PULLUP); // Right Button 2
 

  Joystick.begin();

}

void loop() {
  
  digitalWrite(8, HIGH);

  rX = analogRead(A2);
  rX = map(rX, 0, 1023, 1023, 0);
  Joystick.setRxAxis(rY);
  
  rY = analogRead(A3); 
  Joystick.setRyAxis(rX);
  
  lX = analogRead(A0); 
  Joystick.setXAxis(lX);

  lY = analogRead(A1);
  lY = map(lY, 0, 1023, 1023, 0);
  Joystick.setYAxis(lY);


if (digitalRead(9) == LOW)
 {
     Joystick.pressButton(4);
 }
 else
 {
    Joystick.releaseButton(4);
 }

 if (digitalRead(10) == LOW)
 {
    Joystick.pressButton(0);
 }else
 {
    Joystick.releaseButton(0);
 }
 
 if (digitalRead(11) == LOW)
 {
    Joystick.pressButton(1);
 }else
 {
    Joystick.releaseButton(1);
 }

 if (digitalRead(12) == LOW)
 {
     Joystick.pressButton(2);
 }else
 {
    Joystick.releaseButton(2);
 }

 if (digitalRead(13) == LOW)
 {
     Joystick.pressButton(3);
 }
 else
 {
    Joystick.releaseButton(3);
 }


 if (digitalRead(7) == LOW)
 {
    Joystick.pressButton(5);
 }else
 {
    Joystick.releaseButton(5);
 }

 if (digitalRead(6) == LOW)
 {
    Joystick.pressButton(6);
 }else
 {
    Joystick.releaseButton(6);
 }


if(rX == 0)
{
  Joystick.pressButton(7);
}else
{
  Joystick.releaseButton(7); 
}

if(lX == 1023)
{
  Joystick.pressButton(8);
}else
{
  Joystick.releaseButton(8); 
}

Serial.print(rX);

 delay (10);
  
}

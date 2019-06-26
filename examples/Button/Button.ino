#include <Button.h>

Button btn0;
Button btn1;

void setup() {

  Serial.begin(9600);
}

void loop() {
  if (btn0.Rising(7)) Serial.println("RISING");         // do when HIGH
  //if (btn0.Falling(7)) Serial.println("FALLING");     // do when LOW
  if (btn1.Hold(8, 1000)) Serial.println("HOLD");       // do after 1000 Miliseconds
  //if (btn1.Holdup(8, 1000)) Serial.println("HOLDUP"); // do after 1000 Miliseconds ( loop )
  

}

#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnDoubleClick();
void btnHold();
OneButton button(BTN_PIN, !BTN_ACT);


void setup() {

  //pinMode(LED_PIN, OUTPUT);
  //digitalWrite(LED_PIN, LOW);
  led.off();
  button.attachClick(btnPush);
  button.attachDoubleClick(btnDoubleClick);
  button.attachLongPressStart(btnHold);
}

void loop() {

  //Blink led 
  // digitalWrite(LED_PIN, HIGH);
  // delay(500);
  // digitalWrite(LED_PIN, LOW);
  // delay(500);

  //start
  led.loop();
  button.tick();

}

void btnDoubleClick(){
  led.blink(200);
}

void btnPush(){
  led.flip();
}


void btnHold()
{
    led.blink(200);
}
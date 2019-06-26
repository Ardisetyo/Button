#include "Button.h"
#include <Arduino.h>

Button::Button():
  _button(false),
  _buttonState(false),
  button_(false),
  buttonState_(false),
  hold_(false),
  _hold(false),
  _lastTime(0),
  lastTime_(0) {

}

bool Button::Rising(uint8_t pin) {

  if (digitalRead(pin)) _button = true;
  else {
    _button = false;
    _buttonState = false;
  }

  if (_button != _buttonState) {
    _buttonState = true;
    return true;
  } else return false;
}

bool Button::Falling(uint8_t pin) {
  if (digitalRead(pin)) button_ = true;
  else if (!digitalRead(pin) && button_) {

    if (buttonState_ != button_) {
      buttonState_ = true;
      return true;
    } else {
      button_ = false;
      buttonState_ = false;
      return false;
    }
  }
}

bool Button::Holdup(uint8_t pin, unsigned long _time) {
  if (digitalRead(pin)) {
    if (micros() - _lastTime >= _time * 1000) return true;
  } else {
    _lastTime = micros();
    return false;
  }
}

bool Button::Hold(uint8_t pin, unsigned long _time) {
  if (digitalRead(pin)) {
    if (micros() - lastTime_ >= _time * 1000) hold_ = true;
  } else {
    lastTime_ = micros();
    hold_ = false;
    _hold = false;
    return false;
  }

  if (hold_ != _hold) {
    _hold = true;
    return true;
  } else return false;
}

uint8_t Button::read(uint8_t pin, uint8_t mode) {
  if (mode == 0) return Rising(pin);
  else if (mode == 1) return Falling(pin);
  else return false;
}

uint8_t Button::read(uint8_t pin, uint8_t mode, int delayMicroseconds) {
  if (mode == 2) return Hold(pin, delayMicroseconds);
  else if (mode == 3) return Holdup(pin, delayMicroseconds);
  else return false;
}
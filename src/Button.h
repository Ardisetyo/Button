#ifndef Button_h
#define Button_h

#include <stddef.h>
#include <stdint.h>

#define RISING 0
#define FALLING 1
#define HOLD 2
#define HOLDUP 3

class Button {
  public:
    Button();
    bool Rising(uint8_t pin);
    bool Falling(uint8_t pin);
    bool Hold(uint8_t pin, unsigned long _time);
    bool Holdup(uint8_t pin, unsigned long _time);
    uint8_t read(uint8_t pin, uint8_t mode);
    uint8_t read(uint8_t pin, uint8_t mode, int delayMicroseconds);

  private:
    bool _button;
    bool _buttonState;
    bool button_;
    bool buttonState_;
    bool hold_;
    bool _hold;
    int time_;
    unsigned long _lastTime;
    unsigned long lastTime_;

};

#endif
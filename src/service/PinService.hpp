#ifndef PIN_SERVICE_HPP
#define PIN_SERVICE_HPP

#include "service/Logger.hpp"

class PinService
{
private:
  int *rows;
  int *cols;
  int buzzer, positive, negative;
  Log logger;

public:
  PinService() {}

  PinService(int *rows, int *cols, int positive, int negative, int buzzer)
  {
    (*this).rows = rows;
    (*this).cols = cols;
    (*this).buzzer = buzzer;
    (*this).positive = positive;
    (*this).negative = negative;
    set_pinmode();
  }

  void turnOnLeds(String *leds)
  {
    write(positive, HIGH);
  }

  void turnOfAllLeds() {}

private:
  void write(int pinNo, int value)
  {
    return digitalWrite(pinNo, value);
  }

  void set_pinmode()
  {
    for (int i = 0; i < 4; i++)
    {
      pinMode(rows[i], OUTPUT);
      pinMode(cols[i], OUTPUT);
    }
    pinMode(buzzer, OUTPUT);
    pinMode(positive, OUTPUT);
    pinMode(negative, OUTPUT);
  }
};

#endif
#ifndef PIN_SERVICE_HPP
#define PIN_SERVICE_HPP

#include <Arduino.h>

class PinService
{
private:
  Log logger;
  int A = D2;
  int B = D3;
  int C = D4;
  int P = D6;
  int Q = D7;
  int R = D8;
  int output = D5;
  int input = D1;

public:
  PinService()
  {
    setPinmode();
  }

  String readBlocks()
  {
    String blocks = "";
    write(output, HIGH);
    for (int row = 0; row < 8; row++)
    {
      selectRow(row);
      for (int col = 0; col < 8; col++)
      {
        selectCol(col);
        delay(10);

        if (read(input))
        {
          blocks += (char)('h' - row) + String(col);
        }
      }
    }
    write(output, LOW);
    return blocks;
  }

private:
  void write(int pinNo, int value)
  {
    return digitalWrite(pinNo, value);
  }

  int read(int pin)
  {
    return digitalRead(pin);
  }

  void turnOnLed(char rowChar, int col)
  {
    int row = rowChar - 'a';
    selectRow(row);
    selectCol(col);
  }

  void selectCol(int num)
  {
    write(A, num >> 0 & 1);
    write(B, num >> 1 & 1);
    write(C, num >> 2 & 1);
  }

  void selectRow(int num)
  {
    write(P, num >> 0 & 1);
    write(Q, num >> 1 & 1);
    write(R, num >> 2 & 1);
  }

  void setPinmode()
  {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(P, OUTPUT);
    pinMode(Q, OUTPUT);
    pinMode(R, OUTPUT);
    pinMode(output, OUTPUT);
    pinMode(input, OUTPUT);
  }
};

#endif
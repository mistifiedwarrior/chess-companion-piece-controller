#ifndef PIN_SERVICE_HPP
#define PIN_SERVICE_HPP

#include <Arduino.h>

class PinService
{
private:
  Log logger;
  int A = D0;
  int B = D1;
  int C = D2;
  int P = D5;
  int Q = D6;
  int R = D7;
  int output = D3;
  int input = D4;

public:
  PinService()
  {
    setPinmode();
  }

  String readBlocks()
  {
    String blocks = "";
    write(output, LOW);
    for (int row = 0; row < 8; row++)
    {
      selectRow(row);
      for (int col = 0; col < 8; col++)
      {
        selectCol(col);
        int value = read(input);
        delay(10);
        if (value == 0)
        {
          blocks += (char)('h' - row) + String(col+1);
        }
      }
    }
    write(output, HIGH);
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
    pinMode(input, INPUT);

  }
};

#endif
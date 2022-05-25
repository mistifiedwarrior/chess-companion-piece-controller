#include "controller/ChessController.hpp"
#include "service/CommunicationService.hpp"
#include "service/PinService.hpp"
#include "service/ChessService.hpp"

int rows[3] = {1, 2, 3};
int cols[3] = {5, 6, 7};
int positive = 13;
int negative = 12;
String leds[4] = {"A1", "H1", "E4", "C8"};
const int buzzer = 9;
const int rx = 1, tx = 2;
const int baudrate = 115200;

void setup()
{
  PinService pinService = PinService(rows, cols, positive, negative, buzzer);
  SoftwareSerial serial = SoftwareSerial(rx, tx, false);
  CommunicationService communicationService = CommunicationService(baudrate, &serial);

  ChessService chessService = ChessService(pinService, communicationService);

  ChessController chessController = ChessController(chessService);

  while (true)
  {
    chessController.loop();
    delay(10);
  }
}

void loop() {}
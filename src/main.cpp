#include "controller/ChessController.hpp"
#include "service/PinService.hpp"
#include "service/ChessService.hpp"

void setup()
{
  PinService pinService = PinService();

  ChessService chessService = ChessService(pinService);

  ChessController chessController = ChessController(chessService);

  while (true)
  {
    chessController.loop();
  }
}

void loop() {}
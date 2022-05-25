#ifndef DUSTBIN_MANAGER_HPP
#define DUSTBIN_MANAGER_HPP

#include "service/Logger.hpp"
#include "service/ChessService.hpp"

class ChessController
{
private:
  Log logger = Log();
  ChessService chessService;

public:
  ChessController(ChessService chessService)
  {
    (*this).chessService = chessService;
  }

  void loop()
  {
    String message = chessService.readMessage();
    if (message != "")
    {
      // logic here to turn on LEDs and buzzer
    }
  }

private:
};

#endif
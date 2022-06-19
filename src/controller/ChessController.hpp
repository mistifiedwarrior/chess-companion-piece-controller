#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "service/Logger.hpp"
#include "service/ChessService.hpp"
#include "service/FenService.hpp"

class ChessController
{
private:
  Log logger = Log();
  ChessService chessService;
  FenService fenService;

public:
  ChessController(ChessService chessService)
  {
    (*this).chessService = chessService;
  }

  void loop()
  {
    fenService.update(logger.readMessage());
    if (fenService.isMyTurn())
    {
      String blocks = chessService.readBlocks();

      String action = fenService.getAction(blocks);
      if (action != "")
      {
        logger.write(action);
      }
    }
  }
};

#endif
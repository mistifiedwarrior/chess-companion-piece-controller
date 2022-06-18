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

    // read fen from master node
    // read value from board
    // check difference. which piece has been disconnected. temp store in picked.
    // if piece is opponent put it into to else from

    // if any opponent piece has been picked up
    // fen check difference between fen and reading value
  }

private:
};

#endif
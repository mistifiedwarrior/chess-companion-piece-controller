#ifndef CHESS_SERVICE_HPP
#define CHESS_SERVICE_HPP

#include "service/Logger.hpp"
#include "service/PinService.hpp"

class ChessService
{
private:
  PinService pinService;
  Log logger;

public:
  ChessService() {}

  ChessService(PinService pinService)
  {
    (*this).pinService = pinService;
  }

  String readBlocks()
  {
    return pinService.readBlocks();
  }
};

#endif
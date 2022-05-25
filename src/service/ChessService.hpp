#ifndef CHESS_SERVICE_HPP
#define CHESS_SERVICE_HPP

#include "service/Logger.hpp"
#include "service/CommunicationService.hpp"
#include "service/PinService.hpp"

class ChessService
{
private:
  PinService pinService;
  CommunicationService communicatinService;
  Log logger;

public:
  ChessService() {}

  ChessService(PinService pinService, CommunicationService communicatinService)
  {
    (*this).pinService = pinService;
    (*this).communicatinService = communicatinService;
  }

  String readMessage()
  {
    return communicatinService.readMessage();
  }
};

#endif
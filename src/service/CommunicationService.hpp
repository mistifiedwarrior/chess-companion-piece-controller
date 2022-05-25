#ifndef COMMUNICATION_SERVICE_HPP
#define COMMUNICATION_SERVICE_HPP

#include <SoftwareSerial.h>
#include "service/Logger.hpp"

class CommunicationService
{
private:
  Log logger;
  int baudrate;
  SoftwareSerial *serial;

public:
  CommunicationService() {}

  CommunicationService(int baudrate, SoftwareSerial *serial)
  {
    (*this).baudrate = baudrate;
    (*this).serial = serial;
    (*serial).begin(baudrate);
  }

  String readMessage()
  {
    String msg = "";
    if ((*serial).available() > 0)
    {
      msg += (char)((*serial).read());
    }
    return msg;
  }
};

#endif
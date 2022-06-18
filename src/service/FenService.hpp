#ifndef FEN_SERVICE_HPP
#define FEN_SERVICE_HPP

#include <Arduino.h>

class FenService
{
private:
  String fen = "";
  String from = "";
  String to = "";

public:
  FenService() {}

  void update(String fen)
  {
    if (fen != "")
      (*this).fen = fen;
  }

  bool isMyTurn()
  {
    int startIndex = fen.indexOf(" ");
    char turn = fen.charAt(startIndex + 1);
    return turn == 'w';
  }

  String getAction(String blocks)
  {
    // logic here to get actions
    return "";
  }
};

#endif
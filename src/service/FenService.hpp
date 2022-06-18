#ifndef FEN_SERVICE_HPP
#define FEN_SERVICE_HPP

#include <Arduino.h>

class FenService
{
private:
  String fen = "";
  String from = "";
  String to = "";
  String prevBlocks = "";
  bool asksForSuggestion = false;

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
    if (prevBlocks == "" || prevBlocks.length() == blocks.length())
    {
      prevBlocks = blocks;
      return "";
    }

    updateFromAndTo(blocks);
    return getFinalAction();
  }

private:
  void updateFromAndTo(String blocks)
  {
    if (prevBlocks.length() > blocks.length() && from == "")
    {
      from = getDiffFromPrevBlocks(blocks, true);
    }
    else
    {
      to = getDiffFromPrevBlocks(blocks, false);
    }
  }

  String getDiffFromPrevBlocks(String blocks, bool isMax)
  {
    String max = isMax ? prevBlocks : blocks;
    String min = !isMax ? prevBlocks : blocks;
    String diff = "";
    for (int index = 0; index < max.length(); index += 2)
    {
      String subString = max.substring(index, index + 1);
      if (min.indexOf(subString) == -1)
      {
        diff += subString;
      }
    }
    return diff;
  }

  String getFinalAction()
  {
    if (to != "")
    {
      from = "";
      to = "";
      asksForSuggestion = false;
      return "move " + from + "-" + to;
    }

    if (to == "" || !asksForSuggestion)
    {
      asksForSuggestion = true;
      return "suggestion " + from;
    }

    return "";
  }
};

#endif
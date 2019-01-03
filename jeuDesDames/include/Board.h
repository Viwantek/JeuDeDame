#ifndef BOARD_H
#define BOARD_H

#include "Case.h"

#define TAILLE_PLATEAU 3

class Board
{
  public:
    Board();
    Board(int width, int length);
    Board(int width, int length, int nbTokens, string playOneName, string playTwoName);
    virtual ~Board();
    void displayBoard();
    int getWidth() const;
    Case& getCase(int i, int j);
    void updateTokens(Case* token, int prevX, int prevY);

  protected:
    int _length;
    int _width;
    int _nbTokens;
    Case _board[TAILLE_PLATEAU][TAILLE_PLATEAU];

  private:
};

#endif // BOARD_H

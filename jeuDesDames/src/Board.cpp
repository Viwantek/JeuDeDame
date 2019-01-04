#include "Board.h"
#include "Case.h"

Board::Board(): _length(3), _width(3), _nbTokens(3)
{
  for (int i = 0; i < _length; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (i == 0)
        _board[i][j] = Case(i, j, 1);
      else if (i == _width-1)
        _board[i][j] = Case(i, j, 2);
      else
        _board[i][j] = Case(i, j, 0);
    }
  }
}

Board::~Board()
{

}

int Board::getWidth() const
{
  return _width;
}

Case& Board::getCase(int i, int j)
{
  return this->_board[i][j];
}

void Board::updateTokens(Case* token, int prevX, int prevY)
{
  _board[prevX][prevY].clearToken();
  _board[token->getPosX()][token->getPosY()].setStatus(token->getStatus());
}

ostream &operator<<(ostream &flux, Board const* board)
{
    board->displayBoard(flux) ;
    return flux;
}

void Board::displayBoard(ostream &flux) const
{
  for (int i = 0; i < _width*3-1; i++)
  {
    if (i == 3 || i == 5 || i == 7)
      flux << (i-2)/2;
    else
      flux << " ";
  }
  flux << endl << "  ";
  for (int i = 1; i < _width*3-1; i++)
  {
    flux << "-";
  }
  flux << endl;

  for (int i = 0; i < _length; i++)
  {
    flux << i << "|";
    for (int j = 0; j < _width; j++)
    {
      flux << " " << (_board[i][j]).getStatus();
    }
    flux << " |" <<  endl;
  }
  flux << "  ";
  for (int i = 1; i < _width*3-1; i++)
  {
    flux << "-";
  }
  flux << endl << endl;
}

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

void Board::displayBoard()
{
  for (int i = 0; i < _width*3-1; i++)
  {
    if (i == 3 || i == 5 || i == 7)
      cout << (i-2)/2;
    else
      cout << " ";
  }
  cout << endl << "  ";
  for (int i = 1; i < _width*3-1; i++)
  {
    cout << "-";
  }
  cout << endl;

  for (int i = 0; i < _length; i++)
  {
    cout << i << "|";
    for (int j = 0; j < _width; j++)
    {
      cout << " " << (_board[i][j]).getStatus();
    }
    cout << " |" <<  endl;
  }
  cout << "  ";
  for (int i = 1; i < _width*3-1; i++)
  {
    cout << "-";
  }
  cout << endl << endl;
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

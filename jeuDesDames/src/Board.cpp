#include "Board.h"
#include "Case.h"

Board::Board(): _length(3), _width(3), _nbTokens(3)
{
  for (int i = 0; i < _length; i++)
  {
    for (int j = 0; j < _width; j++)
    {
      if (i == 0)
        _board[i][j] = Case(i, j, '1');
      else if (i == _width-1)
        _board[i][j] = Case(i, j, '2');
      else
        _board[i][j] = Case(i, j, '0');
    }
  }
}

Board::~Board()
{
  delete this;
}

void Board::displayBoard()
{
  std::cout << std::endl << " ";
  for (int i = 1; i < _width*3-1; i++)
  {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i = 0; i < _length; i++)
  {
    std::cout << "|";
    for (int j = 0; j < _width; j++)
    {
      std::cout << " " << _board[i][j].getStatus();
    }
    std::cout << " |" <<  std::endl;
  }
  std::cout << " ";
  for (int i = 1; i < _width*3-1; i++)
  {
    std::cout << "-";
  }
  std::cout << std::endl << std::endl;
}

int Board::getWidth() const
{
  return _width;
}

Case& Board::getCase(int i, int j)
{
  return this->_board[i][j];
}

void updateTokens()
{

}

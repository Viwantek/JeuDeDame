#include "Case.h"

Case::Case(): _posX(0), _posY(0), _status('0')
{

}

Case::Case(int posX, int posY, char status): _posX(posX), _posY(posY), _status(status)
{
//  _top = new Case(0,0,'0');
//  _bottom(0,0,'0');
//  _right(0,0,'0');
//  _left(0,0,'0');
}

Case::~Case()
{

}

const Case& Case::operator=(const Case& other)
{
  if (this == &other)
  {

  } else
  {
    _posX = other._posX;
    _posY = other._posY;
    _status = other._status;
//    _top = other._top;
//    _left = other._left;
//    _right = other._right;
//    _bottom = other._bottom;
  }
  return *this;
}

char Case::getStatus() const
{
  if (this)
    return _status;
  else
    return 'X';
}

int Case::getPosX() const
{
  if (this)
    return _posX;
  else
    return -1;
}

int Case::getPosY() const
{
  if (this)
    return _posY;
  else
    return -1;
}

void Case::setPos(int posX, int posY)
{
  _posX = posX;
  _posY = posY;
}

void Case::setStatus(char status)
{
  _status = status;
}

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
  return _status;
}

int Case::getPosX() const
{
  return _posX;
}

int Case::getPosY() const
{
  return _posY;
}

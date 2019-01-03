#include "Case.h"

Case::Case(): _posX(0), _posY(0), _status(0)
{

}

Case::Case(int posX, int posY, int status): _posX(posX), _posY(posY), _status(status)
{

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

int Case::getStatus() const
{
  if (this)
    return _status;
  else
    return 0;
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

void Case::setStatus(int status)
{
  _status = status;
}

void Case::clearToken()
{
  _status = 0;
}

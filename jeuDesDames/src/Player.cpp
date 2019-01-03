#include "Player.h"

Player::Player()
{
  //ctor
}

Player::Player(std::string name, Board* board, char status): _name(name), _status(status)
{
  _nbToken = board->getWidth();
  int numToken = 0;
  for (int i = 0; i < board->getWidth(); i++)
  {
    for (int j = 0; j < board->getWidth(); j++)
    {
      if (board->getCase(i, j).getStatus() == status)
      {
        _tokens[numToken] = board->getCase(i, j);
        numToken++;
      }
    }
  }
}

Player::~Player()
{
  delete this;
}

void Player::displayAllTokens()
{
  std::cout << "Position of " << this->getName() << "'s tokens :" << std::endl;
  for (int i = 0; i < _nbToken; i++)
  {
    std::cout << "X : " << _tokens[i].getPosX() <<  ", Y : " << _tokens[i].getPosY() << std::endl;
  }
  std::cout << std::endl;
}

std::string Player::getName() const
{
  return _name;
}

int Player::getNbToken() const
{
  return _nbToken;
}

void Player::setNbToken(int nbTokens)
{
  _nbToken = nbTokens;
}

Case* Player::getToken(int posX, int posY)
{
  for (int i = 0; i < getNbToken(); i++)
  {
    if (_tokens[i].getPosX() == posX && _tokens[i].getPosY() == posY)
      return &_tokens[i];
  }
  return 0;
}

void Player::moveToken(Case* token, int posX, int posY)
{
  std::cout << "X : " << token->getPosX() << ", Y : " << token->getPosY() << endl;
  std::cout << "Veut bouger en " << posX << ", " << posY << endl;
}

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
  std::cout << "Position of '" << this->getName() << "''s tokens :" << std::endl;
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
  try
  {
    for (int i = 0; i < getNbToken(); i++)
    {
      if (_tokens[i].getPosX() == posX && _tokens[i].getPosY() == posY)
      {
        return &_tokens[i];
      }
    }
    throw string("Le joueur '" + this->getName() + "' n'a pas de pion a cette position");
  }
  catch (string const& e)
  {
    cerr << endl << e << endl << endl;
  }
  return 0;
}

void Player::moveToken(Board* board, Case* token, int posX, int posY)
{
  int tokenPosX = (token && posX >= 0 && posY >= 0) ? token->getPosX() : posX;
  int tokenPosY = (token && posX >= 0 && posY >= 0) ? token->getPosY() : posY;
  std::cout << "X : " << tokenPosX << ", Y : " << tokenPosY << endl;
  std::cout << "Veut bouger en " << posX << ", " << posY << endl;
  try
  {
    if (posX - token->getPosX() <= 1 && posX - token->getPosX() >= 1 && posY - token->getPosY() <= 1 && posY - token->getPosY() >= 0) // Only 1 case per move
    {
      if (posX >= 0 && posX < board->getWidth() && posY >= 0 && posY < board->getWidth()) // Move inside bounds
      {
        token->setPos(posX, posY);
        board->updateTokens(token, tokenPosX, tokenPosY);
      } else
        throw string("Position impossible a atteindre pour le pion !");
    } else
        throw string("Position impossible a atteindre pour le pion !");
  }
  catch (string const& e)
  {
    cerr << endl << e << endl << endl;
  }
}

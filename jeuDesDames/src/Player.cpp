#include "Player.h"

Player::Player()
{
  //ctor
}

Player::Player(string name, Board* board, int status): _name(name), _status(status)
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
  cout << "Position of '" << this->getName() << "''s tokens :" << endl;
  for (int i = 0; i < _nbToken; i++)
  {
    cout << "X : " << _tokens[i].getPosX() <<  ", Y : " << _tokens[i].getPosY() << endl;
  }
  cout << endl;
}

string Player::getName() const
{
  return _name;
}

int Player::getNbToken() const
{
  return _nbToken;
}

void Player::removeNbToken(int nbTokensToRemove)
{
  _nbToken -= nbTokensToRemove;
  if (_nbToken < 0)
    _nbToken = 0;
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

void Player::moveToken(Board* board, Player* otherPlayer, Case* token, int posX, int posY)
{
  int tokenPosX = (token && posX >= 0 && posY >= 0) ? token->getPosX() : posX;
  int tokenPosY = (token && posX >= 0 && posY >= 0) ? token->getPosY() : posY;
  cout << "(" << tokenPosX << "," << tokenPosY << ") ";
  cout << "veut bouger en (" << posX << "," << posY << ")" << endl << endl;
  try
  {
    // Only 1 case per move and the move depends on the player
    if ((this->_status == 1 && (posX - tokenPosX > 0) && abs(posY - token->getPosY()) <= 1)
        || (this->_status == 2 && (tokenPosX - posX > 0) && abs(posY - token->getPosY()) <= 1))
    {
      if (posX >= 0 && posX < board->getWidth() && posY >= 0 && posY < board->getWidth()) // Move inside bounds
      {
        if (board->getCase(posX, posY).getStatus() == otherPlayer->_status)
        {
          otherPlayer->removeNbToken(1);
          otherPlayer->getToken(posX, posY)->setPos(-1, -1);
        } else if (board->getCase(posX, posY).getStatus() == this->_status)
        {
          throw string("Un pion de son equipe est deja a cette position !");
        }
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

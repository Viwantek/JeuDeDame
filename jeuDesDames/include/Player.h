#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Case.h"

class Player
{
  public:
    Player();
    Player(std::string name, Board* board, char status);
    virtual ~Player();
    void displayAllTokens();
    std::string getName() const;
    void moveToken(Board* board, Case* token, int posX, int posY);
    Case* getToken(int posX, int posY);
    int getNbToken() const;
    void setNbToken(int nbTokens);
    void updateTokens(Case* token);

  protected:
    std::string _name;
    char _status;
    int _nbToken;
    Case _tokens[3];

  private:
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Case.h"

class Player
{
  public:
    Player();
    Player(string name, Board* board, int status);
    virtual ~Player();
    void displayAllTokens();
    string getName() const;
    void moveToken(Board* board, Player* otherPlayer, Case* token, int posX, int posY, int playChoice);
    Case* getToken(int posX, int posY);
    int getNbToken() const;
    void removeNbToken(int nbTokensToRemove);
    void updateTokens(Case* token);
    const Player& operator=(const Player& other);

  protected:
    string _name;
    int _status; // 1, 2
    int _nbToken;
    Case _tokens[3];

  private:
};

void initGame(Board*, Player*, Player*, int&, string&, string&);
void loopGame(Board*, Player*, Player*, int&, string&, string&);

#endif // PLAYER_H

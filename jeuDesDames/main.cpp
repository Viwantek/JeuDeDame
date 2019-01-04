#include "Board.h"
#include "Player.h"

#define TURNS_NUMBER 10

using namespace std;

// Amélioration de l'IA
// Case _tokens du Player à transformer en vector pour éviter de choisir un token qui n'existe pas
// Améliorer le code pour prendre en compte un plateau plus grand, plus de pions, etc.

// Présentation du jeu + choix
// Boucle de jeu

int main()
{
    Board *plateauDeJeu = new Board;
    Player *computer = NULL, *player = NULL;
    int playChoice = 1;
    string playerName, ennemyName;

    // Initialize the game with the order the player wants
    initGame(plateauDeJeu, player, computer, playChoice, playerName, ennemyName);

    // Loop game

    loopGame(plateauDeJeu, player, computer, playChoice, playerName, ennemyName);

    // Destructors
    delete plateauDeJeu;
    delete player;
    delete computer;

    return 0;
}









void initGame(Board* board, Player* player, Player* computer, int& playChoice, string& playerName, string& ennemyName)
{
    cout << endl << "------------------ LE JEU DE DAMES ------------------" << endl << endl;
    cout << "Comment vous appelez-vous ? ";
    cin >>  playerName;
    cout << "Comment voulez-vous que votre adversaire s'appelle ? ";
    cin >> ennemyName;
    cout << "Voulez-vous jouer en premier (haut du plateau) ou en deuxieme ? (1/2) ";
    cin >> playChoice;
    cout << endl << endl << endl;
}

void loopGame(Board* plateauDeJeu, Player* player, Player* computer, int &playChoice, string &playerName, string &ennemyName)
{
    int turnsNb = TURNS_NUMBER;
    int tokenPosX, tokenPosY, posToMoveX, posToMoveY;
    Player *playerWhoPlays = NULL, *playerWhoDont = NULL;
    if (playChoice == 1)
      computer = new Player(ennemyName, plateauDeJeu, 2);
    else
      computer = new Player(ennemyName, plateauDeJeu, 1);
    player = new Player(playerName, plateauDeJeu, playChoice);
    while (turnsNb && player->getNbToken() && computer->getNbToken())
    {
      tokenPosX = -1, tokenPosY = -1, posToMoveX = -1, posToMoveY = -1;
      cout << plateauDeJeu;

      /* JOUEUR 1 */
      cout << "C'est a ";
      if (playChoice == 1)
        cout << playerName;
      else
        cout << ennemyName;
      cout << " de jouer..." << endl;
      if (playChoice == 1)
      {
        playerWhoPlays = player;
        playerWhoDont = computer;
        cout << "Choisissez un pion a deplacer : (x y) ";
        cin >> tokenPosX >> tokenPosY;
        cout << "Choisissez une case sur laquelle vous souhaitez deplacer ce pion : (x y) ";
        cin >> posToMoveX >> posToMoveY;
      } else
      {
          playerWhoPlays = computer;
          playerWhoDont = player;
      }
      playerWhoPlays->moveToken(plateauDeJeu, playerWhoDont, playerWhoPlays->getToken(tokenPosX, tokenPosY), posToMoveX, posToMoveY, playChoice);
      cout << plateauDeJeu;

      tokenPosX = -1, tokenPosY = -1, posToMoveX = -1, posToMoveY = -1;

      /* JOUEUR 2 */
      cout << "C'est a ";
      if (playChoice != 1)
        cout << playerName;
      else
        cout << ennemyName;
      cout << " de jouer..." << endl;
      if (playChoice != 1)
      {
        playerWhoPlays = player;
        playerWhoDont = computer;
        cout << "Choisissez un pion a deplacer : (x y) ";
        cin >> tokenPosX >> tokenPosY;
        cout << "Choisissez une case sur laquelle vous souhaitez deplacer ce pion : (x y) ";
        cin >> posToMoveX >> posToMoveY;
      } else
      {
          playerWhoPlays = computer;
          playerWhoDont = player;
      }
      playerWhoPlays->moveToken(plateauDeJeu, playerWhoDont, playerWhoPlays->getToken(tokenPosX, tokenPosY), posToMoveX, posToMoveY, playChoice);

      turnsNb--;
    }
}

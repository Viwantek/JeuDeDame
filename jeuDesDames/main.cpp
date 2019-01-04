#include "Board.h"
#include "Player.h"

using namespace std;

// IA hasard
// Amélioration de l'IA
// Case _tokens du Player à transformer en vector pour éviter de choisir un token qui n'existe pas
// Améliorer le code pour prendre en compte un plateau plus grand, plus de pions, etc.
// Enlever fonction "displayBoard" > surcharger l'opérateur << à la place

int main()
{
    Board* plateauDeJeu = new Board;
    string playerName, ennemyName;
    int playChoice = 1;
    cout << endl << "------------------ LE JEU DE DAMES ------------------" << endl << endl;
    cout << "Comment vous appelez-vous ? ";
    cin >>  playerName;
    cout << "Comment voulez-vous que votre adversaire s'appelle ? ";
    cin >> ennemyName;
    cout << "Voulez-vous jouer en premier (haut du plateau) ou en deuxieme ? (1/2) ";
    cin >> playChoice;
    Player* computer(0);
    bool first = (playChoice == 1) ? true : false;
    if (first)
      computer = new Player(ennemyName, plateauDeJeu, 2);
    else
      computer = new Player(ennemyName, plateauDeJeu, 1);
    Player* player = new Player(playerName, plateauDeJeu, playChoice);
    Player* playerWhoPlays, *playerWhoDont;
    cout << endl << endl << endl;

    /* COMMENCEMENT DU JEU */

    int nbTours = 1;
    int tokenPosX, tokenPosY, posToMoveX, posToMoveY;
    while (nbTours && player->getNbToken() & computer->getNbToken())
    {
      tokenPosX = -1, tokenPosY = -1, posToMoveX = -1, posToMoveY = -1;
      cout << "------------------Plateau de jeu------------------" << endl << endl;
      plateauDeJeu->displayBoard();

      /* JOUEUR 1 */
      cout << "C'est a ";
      if (first)
        cout << playerName;
      else
        cout << ennemyName;
      cout << " de jouer..." << endl;
      if (first)
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
      playerWhoPlays->moveToken(plateauDeJeu, playerWhoDont, playerWhoPlays->getToken(tokenPosX, tokenPosY), posToMoveX, posToMoveY, first);
      plateauDeJeu->displayBoard();

      tokenPosX = -1, tokenPosY = -1, posToMoveX = -1, posToMoveY = -1;

      /* JOUEUR 2 */
      cout << "C'est a ";
      if (!first)
        cout << playerName;
      else
        cout << ennemyName;
      cout << " de jouer..." << endl;
      if (!first)
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
      playerWhoPlays->moveToken(plateauDeJeu, playerWhoDont, playerWhoPlays->getToken(tokenPosX, tokenPosY), posToMoveX, posToMoveY, first);
      plateauDeJeu->displayBoard();

      nbTours--;
    }

    // Destructors
    delete plateauDeJeu;
    delete player;
    delete computer;

    return 0;
}

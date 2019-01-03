#include "Board.h"
#include "Player.h"

using namespace std;

// IA hasard
// Amélioration de l'IA
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

    cout << endl << endl << endl;

    /* COMMENCEMENT DU JEU */

    int nbTours = 3;
    int tokenPosX = 0, tokenPosY = 0;
    while (nbTours && player->getNbToken() & computer->getNbToken())
    {
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
        cout << "Choisissez un pion a deplacer : (x y) ";
        cin >> tokenPosX >> tokenPosY;
      }

      //Déplacement

      /* JOUEUR 2 */
      cout << "C'est a ";
      if (!first)
        cout << playerName;
      else
        cout << ennemyName;
      cout << " de jouer..." << endl;
      if (!first)
      {
        cout << "Choisissez un pion a deplacer : (x y) ";
        cin >> tokenPosX >> tokenPosY;
      }
      nbTours--;
    }

//    player->moveToken(PlateauDeJeu, computer, computer->getToken(0,0), 1, 1);
//    PlateauDeJeu->displayBoard();
//    cout << "Nb pions : " << player->getNbToken() << endl;
//    cout << "Nb pions : " << computer->getNbToken() << endl;
//    player->moveToken(PlateauDeJeu, computer, player->getToken(2,1), 2, 1);
//    PlateauDeJeu->displayBoard();


    return 0;
}

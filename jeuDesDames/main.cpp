#include "Board.h"
#include "Player.h"

using namespace std;

// Mouvement des jetons (tours de jeu)
// IA hasard
// Amélioration de l'IA

int main()
{
    Board* PlateauDeJeu = new Board;
    PlateauDeJeu->displayBoard();
    Player* playerOne = new Player("Joueur 1", PlateauDeJeu, '1');
    Player* playerTwo = new Player("Joueur 2", PlateauDeJeu, '2');
    playerOne->moveToken(PlateauDeJeu, playerOne->getToken(0,1), 1, 1);
    PlateauDeJeu->displayBoard();
    playerOne->moveToken(PlateauDeJeu, playerOne->getToken(1,1), 0, 1);
    PlateauDeJeu->displayBoard();
    return 0;
}

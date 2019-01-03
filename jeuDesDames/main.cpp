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
    playerOne->displayAllTokens();
//    playerTwo->displayAllTokens();
    Case* test = playerOne->getToken(0,2); // Régler le cas où le jeton n'y est pas !
    std::cout << test->getPosX() << " " << test->getPosY() << std::endl;


    return 0;
}

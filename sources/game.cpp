#include "game.hpp"
#include "player.hpp"
using namespace std;
// using namespace ariel{};
namespace ariel{
    Game::Game(Player p1, Player p2){
        this->player1 = p1;
        this->player2 = p2;
    }
    
    bool Game::isGameOver() const
    {
        return (this->player1.stacksize() == 0 || this->player2.stacksize() == 0 || turn >= 26);
    }

    //playes the game untill the end
    void Game::playAll(){
        while (!isGameOver())
        {
            playTurn();
        }
        
    }

    void Game::playTurn(){

    }

    void Game::printLastTurn(){

    }

    void Game::printLog(){

    }

    void Game::printStats(){

    }

    void Game::printWiner(){

    }

    // Game::to_string
}

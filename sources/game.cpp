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
        //can play only if there is cards in thr packet
        if (isGameOver())
        {
            throw runtime_error("the Game is over");
        }

        Card c1 = this->player1.putCard();
        Card c2 = this->player2.putCard();

        //check who will won in this turn
        if (c1.getNum()>c2.getNum()) //player1 won
        {
            //player1 take the cards to his cardstaken packet
            this->player1.won(c1,c2);
        }else if (c1.getNum()>c2.getNum()) //player2 won
        {
            //player2 take the cards to his cardstaken packet
            this->player2.won(c1,c2);
        }else //if there is a draw
        {
            Card wins[26];
            int numWins =0;
            while ((!isGameOver())&& (c1.getNum()== c2.getNum()))
            {
                wins[numWins++] = c1;
                wins[numWins++] = c2;

                //put the closed cards
                wins[numWins++] = this->player1.putCard();
                wins[numWins++] = this->player2.putCard();

                //need to do from the opend cards

            }
            
        }
        
        
    }

    void Game::printLastTurn(){ // print the last turn stats
        
    }

    void Game::printLog(){

    }

    void Game::printStats(){
    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

    }

    void Game::printWiner(){ // prints the name of the winning player
        if (player1.cardesTaken() > player2.cardesTaken()) {
            cout << this->player1.getName() << " wins with" << this->player1.cardesTaken() <<"cards!" << endl;
        } else if (player1.cardesTaken() < player2.cardesTaken()) {
            cout << this->player2.getName() << " wins with" << this->player2.cardesTaken() << "cards!" << endl;
        } else {
            cout << "The game ended in a draw. Both players obtained" << this->player1.cardesTaken() << "cards!" << endl;
        }
    }

    // Game::to_string
}

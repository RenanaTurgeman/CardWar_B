#include "game.hpp"
#include "card.hpp"

using namespace std;
// using namespace ariel{};
namespace ariel{

    void Game::initializePacket()
    {
        //create 52 cards and insert them into the packet
        for (int i = 2; i <= 14; i++) //begin with 2 beacuse 14 is ace
        {
            packet.emplace_back(Card(i, ariel::Card::Shape::HEARTS));
            packet.emplace_back(Card(i, ariel::Card::Shape::DIAMONDS));
            packet.emplace_back(Card(i, ariel::Card::Shape::CLUBS));
            packet.emplace_back(Card(i, ariel::Card::Shape::SPADES));
        }
    }

    void Game::shufflePacket() {
        int n = packet.size();
        for (int i = n - 1; i > 0; i--) { //go over the packet from the to the beigenning
            // j is a random number between 0-i
            int j = rand() % (i + 1);

            // swap the cards at index i and index j
            Card temp = packet[i];
            packet[i] = packet[j];
            packet[j] = temp;
        }
    }

    void Game::dealCards()
    {
        //each player get 26 cards
        for (int i = 0; i < 26; i++)
        {
            this->player1.addCardToStack(packet.back());
            packet.pop_back();
            this->player2.addCardToStack(packet.back());
            packet.pop_back();
        }
    }

    Game::Game(Player p1, Player p2){
        this->player1 = p1;
        this->player2 = p2;

        gameOver = false;

        initializePacket();
        shufflePacket();
        dealCards();
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

        }else //if there is a draw - WAR
        {
            Card wins[26];
            int numWins =0;
            while ((!isGameOver())&& (c1.getNum()== c2.getNum()))
            {
                wins[numWins++] = c1;
                wins[numWins++] = c2;

                //put the closed cards for each player
                wins[numWins++] = this->player1.putCard();
                wins[numWins++] = this->player2.putCard();

                //put opend cards for each player
                c1 = this->player1.putCard();
                c2 = this->player2.putCard();

            }
            //end the war. now check the possibole cases
            //case 1: the game over while the war, this is stiil draw- Dividing cards.
            if((c1.getNum()==c2.getNum())&&(this->player1.stacksize()==0)){
                for (int i = 1; i <= numWins/2 ; i+2)
                {
                    this->player1.won(wins[i]);
                    this->player2.won(wins[i+1]);
                }
            }else(c1.getNum()>c2.getNum()){ //player1 won in the war
                //player 1 won all the cardes of the war
                for (int i = 0; i < numWins; i++)
                {
                    this->player1.won(wins[i])
                }
            }else(c1.getNum()<c2.getNum()){ //player2 won in the war
                //player 2 won all the cardes of the war
                for (int i = 0; i < numWins; i++)
                {
                    this->player2.won(wins[i]);
                }
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

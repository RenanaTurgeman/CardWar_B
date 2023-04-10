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
            packet.emplace_back(Card(i, std::to_string(i) , Shape::HEARTS));
            packet.emplace_back(Card(i, std::to_string(i) , Shape::DIAMONDS));
            packet.emplace_back(Card(i, std::to_string(i) , Shape::CLUBS));
            packet.emplace_back(Card(i, std::to_string(i) , Shape::SPADES));
        }
    }

    // void Game::shufflePacket() {
    //     int n = packet.size();
    //     for (int  i = n - 1; i > 0; i--) { //go over the packet from the to the beigenning
    //         // j is a random number between 0-i
    //         unsigned int j = rand() % (i + 1);

    //         // swap the cards at index i and index j
    //         Card temp = packet[i];
    //         packet[i] = packet[j];
    //         packet[j] = temp;
    //     }
    // }
    void Game::shufflePacket() {
    auto n = packet.size();
    for (unsigned int i = n - 1; i > 0; --i) {
        // j is a random number between 0-i
        unsigned int j = static_cast<unsigned int>(rand()) % (i + 1);

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
            this->player1->addCardToStack(packet.back());
            packet.pop_back();
            this->player2->addCardToStack(packet.back());
            packet.pop_back();
        }
    }

    Game::Game(Player& player1, Player& player2){
        this->player1 = &player1;
        this->player2 = &player2;

        if(this->player1->getPlaying()==true || this->player2->getPlaying() == true){
            throw logic_error("player can get into a game once");
        }

        this->player1->setPlaying(true);
        this->player2->setPlaying(true);
        this->gameOver = false;
        this->history = "";
        this->lastTurn = "";
        this->turn=0;
        this->draw =0;
        this->wp1 =0;
        this->wp2 =0;

        initializePacket();
        shufflePacket();
        dealCards();
    }
    
    bool Game::isGameOver() 
    {
        return (this->player1->stacksize() == 0 || this->player2->stacksize() == 0 || this->turn >= 26);
    }

    //playes the game untill the end
    void Game::playAll(){
        
        while (!isGameOver())
        {
            playTurn();
        }  

         this->player1->setPlaying(false);
            this->player2->setPlaying(false);
    }

    void Game::playTurn(){
        if(++this->turn > 26){
            throw logic_error("cant play more than 26 rounds");
        }
        if(player1 == player2){
            throw logic_error("same player");
        }
         if ((this->player1->stacksize() == 0 || this->player2->stacksize() == 0 ))
        {
            throw logic_error("the Game is over");
            return;
        }
         if(this->player1->getPlaying()==false || this->player2->getPlaying() == false){
            throw logic_error("player can get into a game once");
        }
        // if(&player1 == &player2){
        //     throw invalid_argument("there is a one player in the game");
        // }

        this->lastTurn = "";
        Card c1 = this->player1->putCard();
        Card c2 = this->player2->putCard();

        //check who will won in this turn
        if (c1.getNum()>c2.getNum()) //player1 won
        {
            //player1 take the cards to his cardstaken packet
            this->player1->won(c1,c2);
            //insert to history
            this->lastTurn = this->player1->getName()+" played "+ c1.getValue()+ " of "+ c1.getShape()+" "+ 
                                this->player2->getName()+" played "+ c2.getValue()+ " of "+ c2.getShape()+". "+
                                this->player1->getName() + " wins";
            this->wp1++;

        }else if (c1.getNum()>c2.getNum()) //player2 won
        {
            //player2 take the cards to his cardstaken packet
            this->player2->won(c1,c2);
            //insert to history
            this->lastTurn = this->player1->getName()+" played "+ c1.getValue()+ " of "+ c1.getShape()+" "+ 
                                this->player2->getName()+" played "+ c2.getValue()+ " of "+ c2.getShape()+". "+
                                this->player2->getName() + " wins\n";
            this->wp2++;
        }else //if there is a draw - WAR
        {
            
            Card wins[26];
            int numWins =0;
            while ((!isGameOver())&& (c1.getNum()== c2.getNum()))
            {
                this->turn++;
                this->draw++ ;
                //insert to history
                this->lastTurn += this->player1->getName()+" played "+ c1.getValue()+ " of "+ c1.getShape()+" "+ 
                                this->player2->getName()+" played "+ c2.getValue()+ " of "+ c2.getShape()+". "+ 
                                " DRAW!\n";
                wins[numWins++] = c1;
                wins[numWins++] = c2;

                //put the closed cards for each player
                wins[numWins++] = this->player1->putCard();
                wins[numWins++] = this->player2->putCard();

                //put opend cards for each player
                c1 = this->player1->putCard();
                c2 = this->player2->putCard();

            }
            //end the war. now check the possibole cases
            //case 1: the game over while the war, this is stiil draw- Dividing cards.
            if((c1.getNum()==c2.getNum())&&(this->player1->stacksize()==0)){
                for (int i = 1; i <= numWins/2 ; i+=2)
                {
                    this->player1->won(wins[i]);
                    this->player2->won(wins[i+1]);
                }
                //these cards not in the wins arr
                this->player1->won(c1);
                this->player2->won(c2);

                this->lastTurn += "the game over in a middle of a WAR in draw. \n";
            }
            else if(c1.getNum()>c2.getNum()){ //player1 won in the war
                //player 1 won all the cardes of the war
                for (int i = 0; i < numWins; i++)
                {
                    this->player1->won(wins[i]);
                }
                this->player1->won(c1,c2);

                this->lastTurn += this->player1->getName()+" played"+ c1.getValue()+ " of "+ c1.getShape()+" "+ 
                                this->player2->getName()+" played"+ c2.getValue()+ " of "+ c2.getShape()+"."+
                                this->player1->getName() + "wins\n";
                this->wp1++;
            }
            else if(c1.getNum()<c2.getNum()){ //player2 won in the war
                //player 2 won all the cardes of the war
                for (int i = 0; i < numWins; i++)
                {
                    this->player2->won(wins[i]);
                }
                this->player2->won(c1,c2);
                this->lastTurn += this->player1->getName()+" played"+ c1.getValue()+ " of "+ c1.getShape()+" "+ 
                                this->player2->getName()+" played"+ c2.getValue()+ " of "+ c2.getShape()+"."+
                                this->player2->getName() + "wins\n";
                this->wp2++;
            }

            this-> history += this->lastTurn; 
            if(this->player1->stacksize()==0){
                this->player1->setPlaying(false);
                this->player2->setPlaying(false);
            }
        }
        
        
    }

    void Game::printLastTurn(){ // print the last turn stats
        cout << this->lastTurn << endl;
    }

    void Game::printLog(){
        cout << this->history << endl;
    }

    void Game::printStats(){
    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        cout << "Game statistics:" << endl;
        cout << "Number of turns:" << this->turn << endl;
        cout << "Number of draws:" << this->draw <<endl;
        cout << "Draw rate:" << (((double)this->draw/this->turn) *100) << endl;  
        cout << "Cardes left:" << this->player1->stacksize() << endl;   

        //statistics for each player:
        cout << player1->getName() << " statistics:" << endl;
        cout << "Cards won:" << this->player1->cardesTaken() << endl;
        cout << "Win rate:" << (((double)this->wp1 / this->turn) *100 ) << endl;

        cout << player2->getName() << " statistics:" << endl;
        cout << "Cards won:" << this->player2->cardesTaken() << endl;
        cout << "Win rate:" << (((double)this->wp2 / this->turn) *100 ) << endl;
    }

    void Game::printWiner(){ // prints the name of the winning player
        if (player1->cardesTaken() > player2->cardesTaken()) {
            cout << this->player1->getName() << " wins with" << this->player1->cardesTaken() <<"cards!" << endl;
        } else if (player1->cardesTaken() < player2->cardesTaken()) {
            cout << this->player2->getName() << " wins with" << this->player2->cardesTaken() << "cards!" << endl;
        } else {
            cout << "The game ended in a draw. Both players obtained" << this->player1->cardesTaken() << "cards!" << endl;
        }
    }

    // Game::to_string
}

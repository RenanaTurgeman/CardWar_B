#pragma once
#include <iostream>
#include "stdio.h"
#include <vector>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel{
    class Game
    {
    private:
        Player *player1; //by reference
        Player *player2;
        int turn; //for count the turns in the game
        int draw; //for count the draws in the game
        int wp1; //fot count the wins for player1
        int wp2;
        vector<Card> packet;
        bool gameOver;
        void initializePacket(); //initialize packet with 52 cards
        void shufflePacket(); //shufle the cards in the packet
        void dealCards(); //deals for each player 26 cards
        string history; //the history of the game for printing
        string lastTurn; //save the history of the last turn for printing
    public:
        std::string to_string();

        // Constructors:
        // Game(){}
        Game(Player& player1,Player& player2);
        void playTurn();
        void printLastTurn(); // print the last turn stats
        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn
        void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        bool isGameOver();
        
    };
}

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
        Player& player1; //by reference
        Player& player2;
        int turn;
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
        Game(){}
        Game(Player p1,Player p2);
        void playTurn();
        void printLastTurn(); // print the last turn stats
        void playAll(); //playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog(); // prints all the turns played one line per turn
        void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
        bool Game::isGameOver() const;
    };
}

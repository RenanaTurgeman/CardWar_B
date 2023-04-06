#pragma once
#include <iostream>
#include <string>
#include "card.hpp"
#include <vector>

namespace ariel
{


class Player
{
private:
    std::string name;
    std::vector<Card> stack;
    std::vector<Card> pcardsTaken;

public:
    Player(){
    }
    Player(std::string name);
    // std::string to_string();
    int stacksize() const; //prints the amount of cards left.
    int cardesTaken(); //prints the amount of cards this player has won.
    void takeCard(const Card& card);
    Card playCard();
    void addToStack(const std::vector<Card>& cards);
    Card putCard();
    void won(Card c1, Card c2);
    // void shuffle();
};

}//namescap
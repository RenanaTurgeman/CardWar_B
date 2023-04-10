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
    bool playing; //for decleare the player are playing once
public:
    Player();
    Player(std::string name);
    // std::string to_string();
    int stacksize() const; //prints the amount of cards left.
    int cardesTaken(); //prints the amount of cards this player has won.
    void takeCard(const Card& card);
    Card playCard();
    void addToStack(const std::vector<Card>& cards);
    Card putCard(); //put card while play
    void won(Card card1, Card card2);
    void won(Card card1);
    std::string getName();
    void addCardToStack(Card mycard);
    bool getPlaying();
    void setPlaying(bool chose);
};

}//namescap
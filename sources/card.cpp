#include "card.hpp"
#include <iostream>
#include "stdio.h"
using namespace std;


namespace ariel{
    Card::Card(Name number , Shape shape){
        this->number = number;
        this->shape = shape;
    }

    int Card::getNum() const{
        return this->number;
    }
    
    string Card::getShape() const{
        switch (this->shape)
        {
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        }
    }

    string Card::cardName() const{
        switch (this->number)
        {
        case ACE:
            return "Ace";
        case JACK:
            return "Jack"
        case QUEEN:
            return "Queen"
        case KING:
            return "King"
        default:
            return to_string((int)(this->number))
            break;
        }
    }
}

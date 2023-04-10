#include "card.hpp"
#include <iostream>
#include "stdio.h"
using namespace std;


namespace ariel{
    Card::Card(int number , string value , Shape shape){
        this->number = number;
        this->value = value;
        this->shape = shape;
    }

    Card::Card(){
        this->number = 1;
        this->value = "ACE";
        this->shape = HEARTS;
    }
    int Card::getNum() const{
        return this->number;
    }

    string Card::getValue() const{
        return this->value;
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
        case DIAMONDS:
            return "Diamonds";
        }
    }

    // string Card::cardName() const{
    //     switch (this->number)
    //     {
    //     case ACE:
    //         return "Ace";
    //     case JACK:
    //         return "Jack";
    //     case QUEEN:
    //         return "Queen";
    //     case KING:
    //         return "King";
    //     default:
    //         return to_string((int)(this->number));
    //         break;
    //     }
    // }
}

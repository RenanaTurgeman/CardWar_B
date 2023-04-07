#include "card.hpp"
#include <iostream>
#include "stdio.h"


namespace ariel{
    Card::Card(int number , Shape shape){
        this->number = number;
        this->shape = shape;
    }

    int Card::getNum() const{
        return this->number;
    }
    
    std::string Card::getShape(){
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

}

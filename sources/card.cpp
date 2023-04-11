#include "card.hpp"
#include <iostream>
#include "stdio.h"
using namespace std;


namespace ariel{
    Card::Card(int number , Shape shape){
        this->number = number;
        this->value = cardName(number);
        this->shape = shape;
    }

    Card::Card(){
        this->number = 1;
        this->value = cardName(1);
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
    #include <string>

    string Card::cardName(int num) const{
        string names[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        if (num == 1) {
          return names[0];  // Ace
        } else if (num >= 2 && num <= 10) {
           return names[num-1];  // 2 to 10
        } else if (num == 11) {
            return names[10];  // Jack
        } else if (num == 12) {
            return names[11];  // Queen
        } else if (num == 13) {
            return names[12];  // King
        } else {
            return "Invalid Rank";  // the num of the card not in range [1, 13]
        }
    }

    // int Card::getRank() const{
    //     int check = this->getNum();

    // }


}

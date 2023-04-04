#include "card.hpp"
#include <iostream>
#include "stdio.h"


namespace ariel{
    Card::Card(int number){
        this->number = number;
    }

    int Card::getNum() const{
        return this->number;
    }
}

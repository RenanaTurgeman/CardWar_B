#pragma once
using namespace std;
#include <iostream>

namespace ariel{
    class Card{
        
        public:
            enum Shape { HEARTS, SPADES, CLUBS, DIAMONDS };
            // Constructors:
            Card(){};
            Card(int number , Shape shape);
            int getNum() const;
            std::string getShape();
        private:
            int number;
            Shape shape;
    };
}

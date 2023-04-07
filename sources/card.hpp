#pragma once
using namespace std;
#include <iostream>

namespace ariel{
    class Card{
        private:
            int number;
            enum Shape { HEARTS, SPADES, CLUBS, DIAMONDS };
            Shape shape;
        public:
            // Constructors:
            Card(){};
            Card(int number , Shape shape);
            int getNum() const;
            std::string getShape();
    };
}

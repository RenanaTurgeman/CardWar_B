#pragma once
using namespace std;
#include <iostream>


enum Shape { HEARTS, SPADES, CLUBS, DIAMONDS };
enum Name{ ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

namespace ariel{
    class Card{
        private:
            Name number;
            Shape shape;
        public:
            // Constructors:
            Card(){};
            Card(Name number , Shape shape);
            int getNum() const;
            string getShape() const;
            string cardName() const;
        
    };
}

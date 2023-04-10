#pragma once
#include <iostream>


enum Shape { HEARTS, SPADES, CLUBS, DIAMONDS };

using namespace std;

namespace ariel{
    class Card{
        private:
            int number;
            string value;
            Shape shape;
        public:
            // Constructors:
            Card();
            Card(int number , string value , Shape shape);
            int getNum() const;
            string getShape() const;
            string cardName() const;
            string getValue() const;
            string toString() const;
    };
}

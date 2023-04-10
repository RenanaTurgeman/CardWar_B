#pragma once
#include <iostream>


enum Shape { HEARTS, SPADES, CLUBS, DIAMONDS };
// enum Name{  2, 3, 4, 5, 6, 7, 8, 9, 10, JACK, QUEEN, KING ,ACE};

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
    };
}

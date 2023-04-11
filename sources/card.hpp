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
            Card(int number , Shape shape);

            int getNum() const;
            string getShape() const;
            string cardName(int num) const;
            string getValue() const;
            // int getRank() const; 
    };
}

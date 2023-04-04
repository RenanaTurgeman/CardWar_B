#pragma once
using namespace std;
#include <iostream>

namespace ariel{
    class Card{
        private:
            int number;
            //  shape;
        public:
            // Constructors:
            Card(){};
            Card(int number);
            int getNum() const;

    };
}

#include "player.hpp"
using namespace std;

namespace ariel{
Player::Player(std::string name){
    this->name = name;
}

int Player::stacksize() const{ //prints the amount of cards left.
    return stack.size();
}

int Player::cardesTaken(){ //prints the amount of cards this player has won.
    return pcardsTaken.size();
}
void Player::takeCard(const Card& card) {
        pcardsTaken.push_back(card);
}

Card Player::playCard() {
    if (stack.empty()) {
        throw std::out_of_range("Player stack is empty");
    }
    Card card = stack.back();
    stack.pop_back();
    return card;
}

    void Player::addToStack(const std::vector<Card>& cards) {
        stack.insert(stack.begin(), cards.begin(), cards.end());
    }

    Card Player::putCard(){
       Card mycard  = this->stack.front(); // return the next card
       stack.erase(stack.begin()); //delete this card from the vector
       return mycard;
    }

    void Player::won(Card c1, Card c2){
        this->pcardsTaken.push_back(c1);
        this->pcardsTaken.push_back(c2);
    }
    
    std::string Player::getName(){
       return name;
    }

    void Player::addCardToStack(Card mycard){
        this->stack.push_back(mycard);
    }

}//namescap
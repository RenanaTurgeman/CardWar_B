#include "player.hpp"
using namespace std;

namespace ariel{
Player::Player(std::string name){
    this->name = name;
    this->playing = false;
}
Player::Player(){
    this->playing = false;

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

    void Player::won(Card card1, Card card2){
        this->pcardsTaken.push_back(card1);
        this->pcardsTaken.push_back(card2);
    }

    void Player::won(Card card1){
        this->pcardsTaken.push_back(card1);
    }
    
    std::string Player::getName(){
       return name;
    }

    void Player::addCardToStack(Card mycard){
        this->stack.push_back(mycard);
    }

    bool Player::getPlaying(){
        return this->playing;
    }

    void Player::setPlaying(bool chose){
        this->playing = chose;
    }

}//namescap
#include "gameRun.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool checkCard(std::vector<int> dealt, int num){
    if(std::count(dealt.begin(), dealt.end(), num)==1)
        return false;
    else
        return true;
}
Card::Card(){
    value = 0;
    suit = 'n';
}
Card::Card(int val, char suit){
    value = val;
    this -> suit = suit;
}
int Card::getValue() const{
    return value;
}
char Card::getSuit() const{
    return suit;
}
void Card::setValue(int val){
    value = val;
}
void Card::setSuit(char suit){
    this -> suit = suit;
}
Deck::Deck(){
    for(int i=1; i<=13; i++){
        deck.at(i-1).setValue(i); 
        deck.at(i-1).setSuit('D'); 
        deck.at(i+12).setValue(i);
        deck.at(i+12).setSuit('H');
        deck.at(i+25).setValue(i);
        deck.at(i+25).setSuit('S');
        deck.at(i+38).setValue(i);
        deck.at(i+38).setSuit('C');
    }
}
Card Deck::pullCard(int a) const{
    return deck.at(a);
} 
Player::Player(){
    setFunds(500.00);
}
Card Player::getCard(int i){
    return hand.at(i);
}
double Player::getFunds(){
    return funds;
}
void Player::setFunds(double amt){
    funds = getFunds() + amt;
}
void Player::setHand(int handSize, Deck deck, std::vector<int>::iterator dealtPtr){
    int cardNum;

    hand.resize(handSize);
    
    for(int i = 0; i<handSize; i++){
    do{
        cardNum = rand()%52;
    }while(!checkCard(&dealtPtr, cardNum));
        hand.vector::push_back(deck.pullCard(cardNum));
        dealtPtr.vector::push_back(cardNum);
    }
}
double Player::bet(){
    double amt;
    do{
    std::cout << "Enter bet amount: ";
    std::cin >> amt;
    if(amt<funds)
        std::cout << "You don't have the facilities for that" << std::endl; 
    }while (amt<funds);
    setFunds(-amt);
    return amt;
}
double Player::bet(double min){
    double amt;
    do{
    std::cout << "Enter bet amount: ";
    std::cin >> amt;
    if(amt>funds)
        std::cout << "You don't have the facilities for that" << std::endl; 
    if(funds<min)
        std::cout << "This bet was less thn the minimum required" << std::endl;
    }while (amt>funds && amt<min);

    setFunds(-amt);
    return amt;
}
void Player::rakeIn(double amt){
    setFunds(amt);
}
Dealer::Dealer(){
    setFunds(9999.00);
}
void Dealer::resetFunds(){
    setFunds(10000.00);
}

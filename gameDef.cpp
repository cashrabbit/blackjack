#include "gameRun.h"
#include <iostream>
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
        deck[i-1].setValue(i); 
        deck[i-1].setSuit('D'); 
        deck[i+12].setValue(i);
        deck[i+12].setSuit('H');
        deck[i+25].setValue(i);
        deck[i+25].setSuit('S');
        deck[i+38].setValue(i);
        deck[i+38].setSuit('C');
    }
}
Card Deck::pullCard(int a) const{
    return deck[a];
} 
Player::Player(){
    setFunds(500.00);
}
Card Player::getCard(int i){
    return hand[i];
}
double Player::getFunds(){
    return funds;
}
void Player::setFunds(double amt){
    funds = getFunds() + amt;
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
void Dealer::resetFunds(){
    setFunds(10000.00);
}

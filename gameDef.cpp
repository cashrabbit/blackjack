#include "gameRun.h"
#include <iostream>
#include <vector>
#include <algorithm>

//checks to see if card has already been dealt
bool checkCard(std::vector<int> dealt, int num){
    if(std::count(dealt.begin(), dealt.end(), num)==1)
        return false;
    else
        return true;
}
//default constructor
Card::Card(){
    value = 0;
    suit = 'n';
}
//paramaterized constructor
Card::Card(int val, char suit){
    value = val;
    this -> suit = suit;
}
//get card value
int Card::getValue() const{
    return value;
}
//get card suit
char Card::getSuit() const{
    return suit;
}
//set card value
void Card::setValue(int val){
    value = val;
}
//set card suit
void Card::setSuit(char suit){
    this -> suit = suit;
}
//construct deck and assign each card value
Deck::Deck(){
    Card c;
    for(int i=1; i<=13; i++){
        c.setValue(i);
        c.setSuit('D');
        deck.push_back(c);
        c.setValue(i);
        c.setSuit('H');
        deck.push_back(c);
        c.setValue(i);
        c.setSuit('S');
        deck.push_back(c);
        c.setValue(i);
        c.setSuit('C');
        deck.push_back(c);
    }
}
//deck destructor
Deck::~Deck(){
}
//getCard from deck
Card Deck::pullCard(int a) const{
    return deck[a];
}
void Deck::removeCard(int cardNum){
    std::vector<Card>::iterator it;
    it = deck.begin() + cardNum;
    deck.erase(it);
}
//construct player 
Player::Player(){
    setFunds(500.00);
}
//destruct player
Player::~Player(){
}
//get card from players hand
std::vector<Card> Player::getHand(){
    return hand;
}
//return current player funds
double Player::getFunds(){
    return funds;
}
//change player funds
void Player::setFunds(double amt){
    funds = getFunds() + amt;
}
//put one card into player hand
void Player::setHand(Card c){
    hand.push_back(c);
}
//bets for player with no minimum
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
//bets for player with a minimum
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
//adds pot to player funds
void Player::rakeIn(double amt){
    setFunds(amt);
}
//gives dealer essentially unlimited dollars 
Dealer::Dealer(){
    setFunds(100000.00);
}
//reset dealer funds after hand
void Dealer::resetFunds(){
    setFunds(100000.00);
}

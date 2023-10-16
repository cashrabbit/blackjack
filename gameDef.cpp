#include "gameRun.h"
#include <iostream>
#include <vector>
#include <algorithm>

//insertion operator overload
std::ostream& operator<<(std::ostream& o, Card c){
    char val;

        switch(c.getValue()){
             case 1:
                val = 'A';
                break;
            case 11: 
                val = 'J';
                break;
            case 12:
                val = 'Q';
                break;
            case 13:
                val = 'K';
                break;
       }
    if(c.getValue() >= 2 && c.getValue() <11)
        return std::cout << c.getValue()<< "-" << c.getSuit();
    else
        return std::cout << val << "-" << c.getSuit();

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
std::vector<Card> Deck::getDeck(){
    return deck;
}
void Deck::removeCard(int cardNum){
    this -> deck.erase(deck.begin()+cardNum);
}
//construct player 
Player::Player(){
    setFunds(500.00);
}
//destruct player
Player::~Player(){
}
//get card from players hand
Card Player::getCard(int i){
    return hand[i];
}
std::vector<Card> Player::getHand(){
    return hand;
}
//return current player funds
double Player::getFunds(){
    return funds;
}
void Player::printFunds(){
    std::cout << funds << std::endl;
}
//change player funds
void Player::setFunds(double amt){
    funds = amt;
}
//put one card into player hand
void Player::setHand(Card c){
    hand.push_back(c);
}
void Player::removeCard(int i){
    std::vector<Card>::iterator it;
    it = hand.begin() + i;
    this -> hand.erase(it);
}

//bets for player with no minimum
double Player::bet(){
    double amt;
    do{
    std::cout << "Enter bet amount: ";
    std::cin >> amt;
    if(amt>funds)
        std::cout << "You don't have the facilities for that" << std::endl; 
    }while (amt>funds);
    rakeIn(-amt);
    return amt;
}
//prints hand and score
void Player::printHand(int score){
    for(int i=0; i< hand.size(); i++)
        std::cout << hand[i] << " ";
    std::cout<< "Score: " << score << std::endl <<std::endl;
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

    rakeIn(-amt);
    return amt;
}
//adds pot to player funds
void Player::rakeIn(double amt){
    setFunds(getFunds() + amt);
}
//gives dealer essentially unlimited dollars 
Dealer::Dealer(){
    setFunds(100000.00);
}
//reset dealer funds after hand
void Dealer::resetFunds(){
    setFunds(100000.00);
}

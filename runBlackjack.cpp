#include "gameRun.h"

#include <iostream>
#include <vector>

//int HAND_SIZE = 2;

void runBlackjack(){
    //creates player,dealer, and deck
    Player p1;
    Player *point1;
    Dealer dealer;
    Deck deck;
    //initializes player, dealer, and deck
    p1 = Player();
    dealer = Dealer();
    deck = Deck();
    //create dealt vector & pointer
    int cardNum, deckSize;
    point1 = &p1;

    deckSize = 52;
    p1.setHand(deck.pullCard(cardNum));

    for(int i=0; i<2; i++){
        deckSize = deal(point1, deck, deckSize);
        deckSize = deal(dealer, deck, deckSize);
    }
    std::cout << p1.getHand(); //<< dealer.getHand();
}
std::ostream& operator<<(std::ostream& o, std::vector<Card> hand){
    char val;

    for(int i=0; i<hand.size(); ){
    if(hand[i].getValue() >= 2 && hand[i].getValue() <= 9 )
        val = static_cast<char> (hand[i].getValue()); 
    else{
        switch(hand[i].getValue()){
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
            default:
            val = 'X';
            break;
        }
    }
    }
    return std::cout << val << hand[1].getSuit();;
}
int deal(Player& p, Deck deck, int deckSize){
    int cardNum;
    cardNum = rand()%deckSize;
    p.setHand(deck.pullCard(cardNum));
    deck.removeCard(cardNum);
    deckSize-- ;

    return deckSize;
}
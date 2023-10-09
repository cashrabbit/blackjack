#include "gameRun.h"

#include <iostream>

int HAND_SIZE = 2;

void runBlackjack(){
    Player p1;
    Dealer dealer;
    Deck deck;

    p1 = Player();
    dealer = Dealer();
    deck = Deck();

    //create dealt vector & pointer
    std::vector<int> dealt;
    

    p1.setHand(HAND_SIZE, deck, dealt.begin());

    std::cout << p1.getCard(0); 
}

std::ostream& operator<<(std::ostream& o, Card c){
    return std::cout << c.getValue() << " " << c.getSuit();
}

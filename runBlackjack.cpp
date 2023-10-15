#include "blackjack.h"

#include <iostream>
#include <vector>

//int HAND_SIZE = 2;

void runBlackjack(){
    //creates player,dealer, and deck
    Player p1;
    Dealer dealer;
    Deck deck;
    //initializes player, dealer, and deck
    p1 = Player();
    dealer = Dealer();
    deck = Deck();
    //initialize necessary variables
    int deckSize, dScore, pScore;
    bool win, bust, stand, validChoice;
    char choice; 
    
    deckSize = 52;
    bust = false;
    stand = false;
    validChoice = false;

    //set random seed credits to my 
    //beautiful girlfriend: Laura Saravia
    srand(time(0));

    //deal cards
    for(int i=0; i<2; i++){
        deal(p1, deck, deckSize);
        deal(dealer, deck, deckSize);
    }
    //display dealt cards
    p1.printHand(addHand(p1.getHand()));
    std::cout << "Dealer's Up Card: " << dealer.getCard(0) << std:: endl;
    //check blackjack and ask for split option
    if(checkBlackjack(p1.getHand()))
        win = true;
    if(checkSplit(p1.getHand())){
        Card splitCard = p1.getCard(0);
        //p1.removeCard(1);
     //finish split part!!!!!!!!!!!!!!!1   
    }

    std::cout << "Hit, Stand, or Surrender\n(H,S, or L):";
    while(!stand && !win){
            std::cin >> choice;
            choice = toupper(choice);
            if(choice == 'H'){
                deal(p1, deck, deckSize);
                bust = (addHand(p1.getHand()) > 21);
            }
            else if(choice == 'S'){
                stand = true;
            }
            else if(choice == 'L'){
                bust = true;
                stand = true;
            }
            else
                std::cout << "Invalid Input. Choose H,S, or L.\n";
        pScore = addHand(p1.getHand());
    }
    p1.printHand(pScore);
    if(bust){
        std::cout << "You Bust! You lose this hand\n";
        win = false;
    }
    else{
        std::cout << "Dealer's Hand: ";
        dealer.printHand(addHand(dealer.getHand()));
        dScore = addHand(dealer.getHand());
        while(dScore< 17){
            deal(dealer, deck, deckSize);
            dScore = addHand(dealer.getHand());
            dealer.printHand(dScore);
        }
    }
    //checks win conditions
    if(dScore > 21){
        win = true;
        std::cout << "Dealer Busted!\n";
    }
    else if(dScore < pScore && !bust)
        win = true;
    else
        win = false;
    //displays victory
    if(win)
        std::cout << "You Win this hand!!\n";
    else    
        std::cout << "You lose this hand :(\n";
    }   

//deals one card and removes it from deck
void deal(Player& p, Deck& deck, int& deckSize){
    int cardNum;

    cardNum = rand()%deckSize;
    p.setHand(deck.pullCard(cardNum));
    deck.removeCard(cardNum);
    deckSize--;
}
//adds up value of all cards in hand
int addHand(std::vector<Card> hand){
    int score;

    score = 0;
    for(int i = 0; i< hand.size(); i++){
        if(hand[i].getValue()>=10)
            score += 10;
        else if(hand[i].getValue()>=2)
            score += hand[i].getValue();
        else if(hand[i].getValue() == 1){//deals woth ace=1/11 case
            if(score > 10)
                score +=1;
            else
                score += 11;
        }
    }

    return score;
}
bool checkBlackjack(std::vector<Card> hand){
    return (addHand(hand)==21);
}
bool checkSplit(std::vector<Card> hand){
    char ans;
    bool split, valid;

    split = false;
    valid = false;
    if(hand[0].getValue() == hand[1].getValue()){
        std::cout << "Do you want to split your " << hand[0].getValue() << "'s?\n(Y/N):";
        while(!valid){      
        std::cin >> ans;
        ans = toupper(ans);
        if(ans == 'Y')
            split = true;
        else if(ans == 'N')
            split = false;
        else
            std::cout << "Invalid input try again\n(Y/N):";
        }
    }
    return split;

}
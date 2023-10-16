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
    bool win, tie, playAgain;
    int deckSize;
    char choice; 
    double bet;
    
    deckSize = 52;
    playAgain = true;

    //set random seed credits to my 
    //beautiful girlfriend: Laura Saravia
    srand(time(0));
    
    //print funds and get bet
    p1.printFunds();
    bet = p1.bet();

    while(playAgain){

    //deal cards
    for(int i=0; i<2; i++){
        deal(p1, deck, deckSize);
        deal(dealer, deck, deckSize);
    }
        //display dealt cards
        p1.printHand(addHand(p1.getHand()));
        std::cout << "Dealer's Up Card: " << dealer.getCard(0) << std:: endl;
        //check blackjack and ask for split option
        if(checkBlackjack(p1.getHand())&&!checkBlackjack(dealer.getHand())){
            win = true;
            std::cout<< "BlackJack!! You win";
        }
        else if(checkSplit(p1.getHand())){
            Card temp;

            temp.setValue(p1.getCard(0).getValue());
            temp.setSuit(p1.getCard(0).getSuit());
            Card splitCard = p1.getCard(0);
            p1.removeCard(1);
            playHand(p1, dealer, deck, win, tie);
        for(int i = 0; i<p1.getHand().size(); i++)
            p1.removeCard(i);
            p1.setHand(temp);
            playHand(p1, dealer, deck, win, tie);   
        }
        else{
            playHand(p1, dealer, deck, win, tie);
        }
        if(win)
            p1.rakeIn(3.0*bet/2.0);
        else if(tie)
            p1.rakeIn(bet);
        else if (!win)
            p1.rakeIn(-bet);
        p1.printFunds();

        playAgain = checkPlayAgain();
    }
}   

//deals one card and removes it from deck
void deal(Player& p, Deck& deck, int& deckSize){
    int cardNum;

    cardNum = rand() % deck.getDeck().size();
    p.setHand(deck.pullCard(cardNum));
    deck.removeCard(cardNum);
    //deckSize--;
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
        if(ans == 'Y'){
            valid = true;
            split = true;
        }
        else if(ans == 'N'){
            split = false;
            valid = true;
        }
        else
            std::cout << "Invalid input try again\n(Y/N):";
        }
    }
    return split;

}

void playHand(Player& p1, Player& dealer, Deck& deck, bool& win, bool& tie){
    bool stand, bust;
    int pScore, dScore, deckSize;
    char choice;

    deckSize = 52;
    bust = false;
    stand = false;

    while(!stand && !win){
        std::cout << "Hit, Stand, or Surrender\n(H,S, or L):";
        std::cin >> choice;
        choice = toupper(choice);
        if(choice == 'H'){
            deal(p1, deck, deckSize);
            pScore= addHand(p1.getHand());
            std::cout<<std::endl;
            p1.printHand(pScore);
        }
        else if(choice == 'S'){
            stand = true;
        }
        else if(choice == 'L'){
            stand = true;
        }
        else
            std::cout << "Invalid Input. Choose H,S, or L.\n";
        pScore = addHand(p1.getHand());
        if(pScore > 21){
            stand = true;
            bust = true;
        }
        if(pScore == 21)
            win = true;
    }
    if(bust){
        std::cout << "You Bust!\n";
        win = false;
    }
    else{
        std::cout << "Dealer's Hand: ";
        dealer.printHand(addHand(dealer.getHand()));
        dScore = addHand(dealer.getHand());
        while(dScore < 17){
            deal(dealer, deck, deckSize);
            dScore = addHand(dealer.getHand());
            dealer.printHand(dScore);
        }
    if(dScore == pScore && pScore <=21)
        tie = true;
    //displays scores
    std::cout << "Your score: " << pScore << "\nDealer's Score: " << dScore << std::endl << std::endl;
    //checks win conditions and displays status
    if(dScore > 21){
        win = true;
        std::cout << "Dealer Busted!\nYou win!\n";
    }
    else if(tie){
        std::cout << "You tied. Here's your bet back\n";
    }
    else if(dScore < pScore && !bust){
        win = true;
        std::cout << "You Win this hand!!\n";
    }
    else{
        win = false;
        std::cout << "You lose this hand :(\n";
    }       
    }   
}

bool checkPlayAgain(){
    char playAgainChoice;
    bool playAgain;
    
    do{
        std::cout << "Do you want to play again? (Y/N)";
        std:: cin >> playAgainChoice;
        playAgainChoice = toupper(playAgainChoice);

        switch(playAgainChoice){
            case 'Y':
                playAgain = true;
                break;
            case 'N':
                playAgain = false;
                break;
           default: 
                playAgainChoice = 'Z';
                std::cout << "Invalid Choice. Try again";
                break;
        }
    }while(playAgainChoice != 'Z');

    return playAgain;
}
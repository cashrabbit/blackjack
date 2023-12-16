#include "blackjack.h"

#include <iostream>
#include <vector>


//3 known issues: ace counter add hand, split function dont work, needs insurance
void runBlackjack(){
    //creates player & dealer
    Player p1, dealer;
    //initializes player, dealer, and deck
    p1 = Player();
    dealer = Player();
    //initialize necessary variables
    bool playAgain, blackjack, split;
    int deckSize;
    char choice; 
    double bet;
    
    deckSize = 52;
    playAgain = true;

    //set random seed credits to my 
    //beautiful girlfriend: Laura Saravia
    srand(time(0));

    //outputs welcome and rules
    std::cout << "You chose Blackjack!\nRules:\n3:2"; 
    std::cout << " Bet Return\nDealer Stands on 17\n\n";
    
    //creates repeating game
    while(playAgain){
        if(!checkBroke(p1.getFunds())){
            Deck deck;
            p1.printFunds();

            //gets bet
            bet = p1.bet();
            
            //beginds round
            dealAndCheck(p1, dealer, deck, split, blackjack);

            //ask to double down
            doubleDown(p1, bet);
            
            if(blackjack && checkBlackjack(dealer.getHand()) == false ){
                    std::cout<< "BlackJack!! You win\n";
                    p1.rakeIn(3.0*bet/2.0+bet);
                    p1.printFunds();
                    p1.clearHand();
                    dealer.clearHand();            
            }
            else if(split){
                //create temp vector and copy cards into it
                std::vector<Card> splitCards;
                splitCards.push_back(p1.getCard(0));
                splitCards.push_back(p1.getCard(1));
                
                //clear/refil player hand
                p1.clearHand();
                p1.setHand(splitCards[0]);

                //play first hand
                p1.printHand();
                playHand(p1, dealer, deck, bet);
                
                //reset after hand
                p1.clearHand();
                dealer.clearHand();
                
                //reset cards and bet
                p1.setHand(splitCards[1]);
                deal(dealer, deck);
                deal(dealer, deck);
                p1.rakeIn(-bet);
                p1.printHand();
                playHand(p1, dealer, deck, bet);
            }
            else
                playHand(p1, dealer, deck, bet);

            split = false;
            blackjack = false;
            //checks to see if user wants to continue
            playAgain = checkPlayAgain();
        }
        else
            playAgain = false;
    }
}   

//adds up value of all cards in hand
int const addHand(std::vector<Card> hand){
    int score;

    score = 0;
    //turns face cards into 10 pts
    for(int i = 0; i< hand.size(); i++){
        if(hand[i].getValue()>=10)
            score += 10;
        else if(hand[i].getValue()>=2)
            score += hand[i].getValue();
        //deals with ace=1/11 case
        else if(hand[i].getValue() == 1){
            if(score + 11  > 21)
                score +=1;
            else
                score += 11;
        }
    }
    for(int i = 0; i< hand.size(); i++){
        if(hand[i].getValue()==1 && score > 21)
            score -= 10;
    }
    
    return score;
}
//checks to see if player has blackjack
bool const checkBlackjack(std::vector<Card> hand){
    return (addHand(hand)==21);
}

//checks to see if player was dealt doubles
bool const checkSplit(std::vector<Card> hand){
    char ans;
    bool split, valid;
    int val;

    split = false;
    valid = false;
    val = hand[0].getValue();
    if(val == hand[1].getValue()){
        //asks players if they want to split
        std::cout << "Do you want to split your ";
        switch(val){
            case 11:
                std::cout << "J";
                break;
            case 12:
                std::cout << "Q";
                break;
            case 13:
                std::cout << "K";
                break;
            case 1:
                std::cout << "A";
                break;
            default:
                std::cout<<val;
                break;
        }
        std::cout << "'s?\n(Y/N):";        
        while(!valid){      
        std::cin >> ans;
        ans = toupper(ans);
        //checks input validity
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

void dealAndCheck(Player& p1, Player& dealer, Deck& deck, bool& split, bool& blackjack){
    //deal 2 cards to each player
   for(int i=0; i<2; i++){
        deal(p1, deck);
        deal(dealer, deck);
    }
        //display dealt cards
    p1.printHand(addHand(p1.getHand()));
    std::cout << "Dealer's Up Card: " << dealer.getCard(0) << std:: endl;
    //check blackjack and ask for split option
    if(checkBlackjack(p1.getHand())&&!checkBlackjack(dealer.getHand()))
        blackjack = true;
    else if(checkSplit(p1.getHand())){
        //creates temporary card and replaces hand after split round
        split = true;
    }
}

//actually runs hand, most relevant part of code
void playHand(Player& p1, Player& dealer, Deck& deck, double bet){
    bool stand, bust, win, tie, surrender;
    int pScore, dScore, deckSize;
    char choice;

    deckSize = 52;
    stand = false;
    bust = false;
    win = false;
    tie = false;
    surrender = false;

    //asks for player moves and checks validity until stand or surreder
    while(!stand && !win && !surrender){
        std::cout << "Hit, Stand, or Surrender\n(H,S, or L):";
        std::cin >> choice;
        choice = toupper(choice);
        //deals another card if they chose to hit
        if(choice == 'H'){
            deal(p1, deck);
            pScore= addHand(p1.getHand());
            std::cout<<std::endl;
            p1.printHand(pScore);
        }
        else if(choice == 'S')
            stand = true;
        else if(choice == 'L')
            surrender = true;
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
            deal(dealer, deck);
            dScore = addHand(dealer.getHand());
            dealer.printHand(dScore);
        }
    if(dScore == pScore && pScore <=21)
        tie = true;
    //displays scores
    std::cout << "Your score: " << pScore << "\nDealer's Score: " << dScore << std::endl << std::endl;
    //checks win conditions and displays status
    if(surrender){
        win = false;
        std::cout << "You surrendered here is half of your bet back\n";
        p1.rakeIn(bet/2.0);
    }
    else if(dScore > 21){
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
    if(win)
            p1.rakeIn(3.0*bet/2.0 + bet);
        else if(tie)
            p1.rakeIn(bet); 
    p1.printFunds(); 

    //clears deck and players hands to  restart
        p1.clearHand();
        dealer.clearHand();

}

bool const checkPlayAgain(){
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
    }while(playAgainChoice == 'Z');
    
    return playAgain;
}

bool const checkBroke(double funds){
    if(funds == 0){
        std::cout << "Too Bad. You broke.\nHope you had fun.\n";
        return true;
    }
    else
        return false;
}

double doubleDown(Player p, double& bet){
    int total;
    char ans;
    bool valid;
    total = p.getCard(0).getValue() + p.getCard(1).getValue();
    if(total>=9 && total <=11){
        while(valid != true){
            std::cout << "Do you want to double down on your bet?(Y/N)";
            std::cin >> ans;
            ans = toupper(ans);
            switch(ans){
                case 'Y':
                    bet = 2.0 * bet;
                    valid = true;
                    break;
                case 'N':
                    valid = true;
                    break;
                default:
                    std::cout << "Your input was invalid.\n";
                    break;
            } 
    }
    return bet;
}
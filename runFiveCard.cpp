#include "poker.h"

void runFiveCard(){
    //creates necessary variables
    int pNum;

    //initalizes necessary variables
    pNum = fiveCardWelcome();

    //create objects for every player amt
    Player pList[pNum];

    //creates new deck
    Deck deck;

    //creates list of handRanks
    Rank handRanks[pNum], temp;

    //sets randomness for deck
    srand(time(0));

    //deals five cards to each player
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < pNum; i++)
            deal(pList[i], deck);
    }

    pList[0].printHand();
    handRanks[0].equals(judgeHand(pList[0].getHand()).getRank(), judgeHand(pList[0].getHand()).getHighVal(), judgeHand(pList[0].getHand()).getLowVal());
    handRanks[0].printRank();
    pList[0].printHand();

}

int fiveCardWelcome(){
    int playerNum;
    bool valid;
    
    std::cout << "Welcome to Five-Card Draw\n1 Round no-limit game\n";
    
    while(!valid){
        std::cout << "Please input number of players(2-5)";
        std::cin >> playerNum;

        if(playerNum >= 2 && playerNum <= 5)
            valid = true;
    }

    return playerNum;
}
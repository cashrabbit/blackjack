#include "gameRun.h"
#include <iostream>

int main(){
    
    switch(welcome()){
        case 'A':
            std::cout << "You chose Blackjack!\nRules:\n3:2"; 
            std::cout << " Bet Return\nDealer Stands on 17\n\n";
            runBlackjack();
            break;
        case 'B':
            break;
    }

    return 0;
}

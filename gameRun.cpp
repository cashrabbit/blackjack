#include "gameRun.h"
#include <iostream>

int main(){
    
    switch(welcome()){
        case 'A':
            std::cout << "You chose Blackjack!\n Dealing...\n\n";
            runBlackjack();
            break;
        case 'B':
            break;
    }

    return 0;
}

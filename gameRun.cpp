#include "gameRun.h"
#include <iostream>

int main(){
    char menuSel;

    menuSel = welcome();
    switch(menuSel){ //add for every game
        case 'b':
            runBlackjack();
            break;
        case 't':
            break;
    }

    return 0;
}
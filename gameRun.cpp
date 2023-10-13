#include "gameRun.h"
#include <iostream>

int main(){
    char menuSel;

    menuSel = welcome();

    switch(menuSel){
        case 'A':
            runBlackjack();
            break;
        case 'B':
            break;
    }

    return 0;
}

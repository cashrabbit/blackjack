#include "gameRun.h"

#include <iostream>

char welcome(){
    char input;
    bool valid;
    std::cout << "\nWelcome to our casino!\n\nPlease select a menu option:";
    std::cout << "\n(b) Blackjack\n(t) Texas Hold 'em\n"; //add for every game
    do{
    std::cin >> input;
    input = tolower(input);
    switch(input){//add to every game
        case 'b': 
        case 't':
            valid = true;
            break;
        default:
            valid = false;
            std::cout << input << " is not a valid menu option. Try again\n";
            break;
    }
    }while(!valid);

    return input;
}
#include "gameRun.h"

Card::Card(int val, char suit){
    value = val;
    this -> suit = suit;
}

int Card::getValue(Card get){
    return get.value;
}

char Card::getSuit(Card get){
    return get.suit;
}

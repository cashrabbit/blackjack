#include "gameRun.h"

Card::Card(int val, char suit){
    value = val;
    this -> suit = suit;
}

int Card::getValue(Card get)
{
    return value;
}

char Card::getSuit(Card get){
    return suit;
}
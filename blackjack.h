#include "gameRun.h"
#include <vector>
//Extra function declarations for blackjack game

void deal(Player& p, Deck& deck, int& deckSize);
int addHand(std::vector<Card> hand);
bool checkBlackjack(std::vector<Card> hand);
bool checkSplit(std::vector<Card> hand);

#include "gameRun.h"
#include <vector>

//Extra function declarations for blackjack game
int const addHand(std::vector<Card> hand);
bool checkBlackjack(std::vector<Card> hand);
bool checkSplit(std::vector<Card> hand);
void dealAndCheck(Player& p1, Player& dealer, Deck& deck, bool& split, bool& blackjack);
void playHand(Player& p1, Player& dealer, Deck& deck, double bet, bool& split, bool& blackjack);
bool checkPlayAgain();
bool checkBroke(double funds);

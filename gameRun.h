#include <vector>

char welcome();
void runBlackjack();

class Card
{
    public:
    //constructors
    Card();
    Card(int val, char suit);
    
    //getters
    int getValue() const;
    char getSuit()const ;

    //setters
    void setValue(int val);
    void setSuit(char suit);

    private: 
    int value;
    char suit;
};

class Deck
{
    public:
    Deck();
    Card pullCard(int a)const;
    
    private:
    std::vector<Card> deck;
 
};

class Player{
    public:
    Player();
    //getters
    Card getCard(int i);
    double getFunds();
    //setters
    void setFunds(double amt);
    void setHand(int handSize, Deck deck, std::vector<int>::iterator dealt);
    double bet();
    double bet(double min);
    // void fold();
    // void check(); 
    void rakeIn(double amt);

    private:
    std::vector<Card> hand;
    double funds;
};
class Dealer:public Player{
    public:
    Dealer();
    void resetFunds();
};
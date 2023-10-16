#include <iostream>
#include <vector>

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
    //constructors
    Deck();
    // destrcutor
    ~Deck();
    //getters
    Card pullCard(int a)const;
    //remove from deck
    void removeCard(int cardNum);
    
    private:
    std::vector<Card> deck;
 
};

class Player{
    public:
    //constructors
    Player();
    //destructor
    ~Player();
    //getters
    Card getCard(int i);
    std::vector<Card> getHand();
    void printHand(int score);
    double getFunds();
    //setters
    void setFunds(double amt);
    void setHand(Card c);
    void removeCard(int i);
    //player "move" functions
    double bet();
    double bet(double min);
    //void fold();
    //void check(); 
    void rakeIn(double amt);

    private:
    std::vector<Card> hand;
    double funds;
};
class Dealer:public Player{
    public:
    //constructor
    Dealer();
    //guarantee house never goes broke
    void resetFunds();
};

//extra function declarations
char welcome();
std::ostream& operator<<(std::ostream& o, Card c);
void runBlackjack();
void burnCard(Deck& deck);
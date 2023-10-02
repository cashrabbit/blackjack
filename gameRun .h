int const HAND_SIZE = 2;

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
    Card deck[52];
 
};

class Player{
    public:
    Player();
    Card getCard(int i);
    double getFunds();
    void setFunds(double amt);
    double bet();
    double bet(double min);
    // void fold();
    // void check(); 
    void rakeIn(double amt);

    private:
    Card hand[HAND_SIZE];
    double funds;
};

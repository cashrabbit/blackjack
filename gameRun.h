class Card
{
    public:
    int getValue(Card get);
    char getSuit(Card get);
    Card();
    Card(int val, int suit);
    void setValue(Card set, int val);
    void setSuit(Card set, char suit);


    private: 
    int value;
    char suit;
};

class Deck
{
    public:
    Card getCard(int a);
    Deck();

    private:
    Card deck[52];
 
};

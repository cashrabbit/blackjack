class Card
{
    public:
    Card getCard();
    Card(int val, char suit);
    int getValue(Card get);
    char getSuit(Card get);


    private: 
    int value;
    char suit;
};

class Deck
{
    public:
        Card deck[52];

    private:
        void shuffle(Deck deck); 
};

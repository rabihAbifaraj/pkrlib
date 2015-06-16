#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck
{
    Vector <Card> cards;
    int size;
public:
    
    deck();
    deck(int);
    ~deck();

    void shuffle();
    void removeCard(Card);
    void removeCard(int);
}


#endif

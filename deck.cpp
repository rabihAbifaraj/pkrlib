#include <stdlib>
#include <stdio>
#include <time.h>
#include "deck.h"
#include "card.h"

Deck:deck()
{
    for(int i = 0; i < VALS * SUITS; i++)
    {
        this.cards.push_back(card(i));
    }
    this.size = VALS * SUITS;
}

Deck::deck(int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < VALS * SUITS; j++)
        {
            this.cards.push_back(card(j));
        }
    }
    this.size = VALS * SUITS * num;
}

Deck::~deck(){}

Deck::shuffle()
{
    srand(time(NULL));
    int index = 0;
    Card tmp;

    for(int i = 0; i < this.size; i++)
    {
        tmp = this.cards(i); 
        index = rand() % this.size;

        this.cards(i) = this.cards(index);
        this.cards(index) = tmp;
   }
}

Deck::removeCard(Card& waste) // This is supposed to remove card "waste".
{                             // We'll see if it works
    Vector<Card>::iterator it = find(this.cards.begin(),this.cards.end(),waste);
    if(it != this.cards.end())
    {
        this.cards.erase(it);
        this.size -= 1;
    }
}

Deck::removeCard(int value)   // removes the first card in the deck with val = value
{
    for(int i = 0; i < this.size; i++)
    {
        if(this.cards[i].getVal() == value)
        {
            this.cards.remove(i);
            this.size -= 1;
            return;
        }
    }
}

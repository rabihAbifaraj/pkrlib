#ifndef CARD_H
#define CARD_H
using namespace std;

#define SUITS 4
#define VALS  13

class Card
{
    int val;            // Number between 0 and 12
    int suit;           // Number between 0 and 3
public:
    card(int,int);
	card(int);
	~card();
    int getVal();
	int getSuit();
	void setVal(int);
	void setSuit(int);
	void printVal();
	void printSuit();
}

#endif

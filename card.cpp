#include <stdio>
#include <stdlib>
#include "card.h"

Card::card(int val, int suit)
{
    this.val = val;
    this.suit = suit;
}

Card::card(int index)
{
    this.val = index % VALS;
    this.suit = index / SUITS;
}

Card::~card(){}

Card::getVal()
{
    return val;
}

Card::getSuit()
{
    return suit;
}

Card::setVal(int val)
{
    this.val = val;   
}

Card::setSuit(int suit)
{
    this.suit = suit;
}

Card::printVal()
{
    // [0-12]
    switch (this.val)
    {
		case 0:
            cout<<"A";
            break;
		case 1:
            cout<<"2";
            break;
		case 2:
            cout<<"3";
            break;
		case 3:
            cout<<"4";
            break;
		case 4:
            cout<<"5";
            break;
		case 5:
            cout<<"6";
            break;
		case 6:
            cout<<"7";
            break;
		case 7:
            cout<<"8";
            break;
		case 8:
            cout<<"9";
            break;
		case 9:
            cout<<"T";
            break;
		case 10:
            cout<<"J";
            break;
		case 11:
            cout<<"Q";
            break;
		case 12:
            cout<<"K";
            break;
        default:
            cout<<"wtf, mate\n";
            break;
    }
}

Card::printSuit()
{
    switch(this.suit)
    {
        case 0:
            cout<<"H";
            break;
        case 1:
            cout<<"S";
            break;
        case 2:
            cout<<"C";
            break;
        case 3:
            cout<<"D";
            break;
        default:
            cout<<"dafuq?";
            break;
    }
}

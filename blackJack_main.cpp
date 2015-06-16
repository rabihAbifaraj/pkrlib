#include <stdio>
#include <stdlib>
#include "card.h"
#include "deck.h"

int getScore(char * hand, int sizeOfHand)
{
    int myValueOfACard = 0;
    bool flagArray[sizeOfHand];
    std::fill_n(flagArray,sizeOfHand,false);
    int handVals[sizeOfHand];
    bool softFlag = false;
    for(int i=0; i<sizeOfHand; i++)
    {
        if( hand[i] != "A" && hand[i] != "K" && hand[i] != "Q" && hand[i] != "J" )
            myValueOfACard = atoi(cards[i])
            handVals[i] = myValueOfACard;
        else
        {
            switch(cards[i])
            {
                case "A":
                    // this one sucks
                    // soft. so counts as 11.
                    flagArray[i] = ~flagArray[i];
                    handVals[i] = 11;
                    // if greater than 21
                    // will change one at a time until sum is lt 21.
                    break;
                case "K":
                    handVals[i] = 10;
                    break;
                case "Q":
                    handVals[i] = 10;
                    break;
                case "J":
                    handVals[i] = 10;
                    break;
                default:
                    cout<<"this is a stupid message\n";
                    break;
            }
        }
    }
    // calculate sum total. If greater than 21 at first, flip Ace softness.
    myValueOfACard = 0;
    for(int i=0; i<sizeOfHand; i++)
    {
        myValueOfACard += handVals[i];
    }
    for(int i=0; i<sizeOfHand; i++)
    {
        if(myValueOfACard > 21 && flagArray[i])
        {
            myValueOfACard-=10;
        }
    }

    return myValueOfACard;

}



double scoreMeSomeGoodies(int scoreForNow, int goalValue, double currentProbs)
{
    // TODO: apply counting and index cleverness here.
    
}

double* calculateMyProbs( int argc, char **argv)
{
    double myProbs[6];
    int initialCount[VALS];
    std::fill_n(initialCount, VALS, SUITS*argv[1]);
    
    int daIndex=0;
    for(int i = 2; i<argc; i++)
    {
        switch(argv[i])
        {
            case "A":
                daIndex = 0;
                break;
            case "K":
                daIndex = 11;
                break;
            case "Q":
                daIndex = 10;
                break;
            case "J":
                daIndex = 9;
                break;
            default:
                daIndex = atoi(argv[i])-1;
                break;
        }

        // the index is for the value of the cards
        // we subtract from whatever we set the index 
        initialCount[daIndex] -= 1;
    }
    // time to score
    // all about dat count 
    int goalValue = 0;
    int handValIs = 0;
    double currentProb = 0.0;
    handValIs = getScore(argv[2],argv[3]);
    for(int i = 0; i <6; i++)
    {   
        goalValue = i+16;
        myProbs[i] = scoreMeSomeGoodies(handValIs,goalValue,currentProb);
    }


}


int main(int argc, char **argv)
{
    // argv[1] is # decks
    // argv[2:] is cards on field
    
    myProbs = calculateMyProbs(argc, argv);
    for (int i = 0; i<5; i++)
    {
        cout<<"probability for %d is %lf "<<i+16<<myProbs[i]<<endl;    
    }
    return;
}


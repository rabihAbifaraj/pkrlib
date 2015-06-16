#include <stdio>
#include <stdlib>
#include "card.h"
#include "deck.h"


double* calculateMyProbs( int argc, char **argv)
{
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


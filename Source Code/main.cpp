#include "quickHull.h"
#include "randompairs.h"

#include <iostream>

int main(){
    std::cout << "Number of items in random set: ";
    int items;
    std::cin >> items;
    std::cout << "Please enter the seed: ";
    int seed;
    std::cin >> seed;

    generatePairs( seed, items );

    std::cout << "For graham scan algorithm enter 1. For quickhull algorithm enter 2: ";
    int decision;
    std::cin >> decision;
    if( decision == 1 ) {
        return 1;
    }
    else{
        quickHull( "randomPairs.csv" );
    }


    return 1;
}
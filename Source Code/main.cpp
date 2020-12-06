//#include "graham.h"
#include "quickHull.h"
#include "randompairs.h"

#include <iostream>

int main(){

    std::cout << "Enter 'random' for a random set of numbers or enter the filepath of the csv file you wish to analyze: ";
    std::string decisionOrFile;
    std::cin >> decisionOrFile;

    if( decisionOrFile == "random" ) {
        std::cout << "Number of items in random set: ";
        int items;
        std::cin >> items;
        std::cout << "Please enter the seed: ";
        int seed;
        std::cin >> seed;

        generatePairs( seed, items );
        decisionOrFile = "randomPairs.csv";
    }

    std::cout << "For graham scan algorithm enter 1. For quickhull algorithm enter 2: ";
    int algorithm;
    std::cin >> algorithm;
    if( algorithm == 1 ) {
        //graham( decisionOrFile );
        return 1;
    }
    else{
        quickHull( decisionOrFile );
    }

    std::cout << "Depending on if you called graham scan or quickhull the output file will be named either XXX or quickhullPairs.csv" << std::endl;
    std::cout << "To visualize the data, run 'python3 visualization.py'. The file will ask for the name of the file you wish to analyze, see previous line." << std::endl;
    return 1;
}
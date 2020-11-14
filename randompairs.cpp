#include <utility>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

/**

This file will produce a inputted number of pairs

**/

std::vector< std::pair<int, int> > coordinatePairs;

void generatePairs( int seed, int cardinality ){
    srand(seed);
    for(int i = 0; i < cardinality; i++){
        std::pair<int, int> coordinate;
        // uncomment this if we will ever need x and y later
        //int x = rand() % 100;
        //int y = rand() % 100;
        coordinate.first = rand() % 100;
        coordinate.second = rand() % 100;
        coordinatePairs.push_back(coordinate);
    }

}

int main(int argc, char**argv) {
    int seed = std::stoi(argv[1]);
    int numPairs = std::stoi(argv[2]);
    generatePairs( seed, numPairs );
    for( int i = 0; i < numPairs; i++){
        std::cout << coordinatePairs[i].first << ", " << coordinatePairs[i].second << std::endl;
    }
}


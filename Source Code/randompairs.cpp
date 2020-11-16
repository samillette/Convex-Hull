#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

/**

This file will produce a inputted number of pairs

**/

void generatePairs( int seed, int cardinality ){

    std::ofstream outFile;
    outFile.open( "randomPairs.csv" );

    srand(seed);

    for(int i = 0; i < cardinality; i++){

        // uncomment this if we will ever need x and y later
        //int x = rand() % 100;
        //int y = rand() % 100;

        outFile << std::to_string( rand() % 100 ) + ",";
        outFile << std::to_string( rand() % 100 );

        outFile << "\n";
    }
    outFile.close();

}

int main(int argc, char**argv) {
    // gets user inputted randomization seed
    int seed = std::stoi(argv[1]);

    // gets user inputted number of vectors
    int numVec = std::stoi(argv[2]);

    //calls generatePairs
    generatePairs( seed, numVec );
}


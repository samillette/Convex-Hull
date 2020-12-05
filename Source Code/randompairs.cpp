#include "randompairs.h"

/**
    Samuel Millette
	12.3.2020
	For my CSC212 class take fall of 2020 at the University of Rhode Island
 */

/**

This file will produce a inputted number of pairs as a csv file by the form:
 x1,y1,x2,y2

 All pairs will have their x2 and y2 initialized as -1 and -1
 x1 and y1 will have positive values between 0 and 99

**/

//forward declared in randompairs.h
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
        outFile << ",-1,-1";

        outFile << "\n";
    }
    outFile.close();

}

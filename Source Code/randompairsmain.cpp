#include "randompairs.h" // needed for forward declaration of generatepairs function
#include <string>

//remember to compile both randompairs.cpp and grahamScan.cpp for this to work

int main(int argc, char**argv) {

    int seed = std::stoi(argv[1]);
    int numPairs = std::stoi(argv[2]);
    generatePairs( seed, numPairs );

}

#include "quickHull.h"
#include <iostream>

Point minX(100,100);
Point maxX(-1,-1);

std::vector< Point > csvToVector(std::string filePath){
    std::vector< Point > pointVec;

    int x;
    int y;

    std::ifstream file(filePath);
    std::string line;

    while( std::getline(file, line) ){

        std::stringstream linestream(line);
        std::string value;

        std::getline(linestream, value, ',');
        x = std::stoi (value);
        std::getline(linestream, value, ',');
        y = std::stoi (value);

        Point p(x, y);
        pointVec.push_back(p);

        if( p.getX() < minX.getX() ){
            minX = p;
        }
        if( p.getX() > maxX.getX() ){
            maxX = p;
        }
    }

    return pointVec;
}

int main () {
    //std::cout << std::to_string(p.getX()) << " " << std::to_string(p.getY()) << std::endl;

    //csvToVector("randomPairs.csv");

    Point p1(1, 6);
    Point p2(2, 11);

    Line line1(p1, p2);
    std::cout << std::to_string(line1.getYIntercept()) << " slope: " << std::to_string(line1.getSlope()) << std::endl;

}
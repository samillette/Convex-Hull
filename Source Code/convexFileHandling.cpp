#include "convexFileHandling.h"

/**
    Samuel Millette
	12.3.2020
	For my CSC212 class take fall of 2020 at the University of Rhode Island
 */

std::vector< Point > csvToVector(std::string filePath, Point & minX, Point & maxX){
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

        if( p.getX() < minX.getX() ){
            minX = p;
        }
        else if( p.getX() > maxX.getX() ){
            maxX = p;
        }
        //Only in the case where the point considered is not a max or min x point is it added to the vector of points
        //This is an important distinction because it ensures that minx and maxx are not considered in any comparisons
        else{
            pointVec.push_back(p);
        }
    }

    return pointVec;
}

void hullVectorToCSV(std::string filePath, std::vector< Point > hull, std::vector< Point > interior){
    std::ofstream outFile;
    outFile.open(filePath, std::ofstream::out | std::ofstream::trunc );

    int hullLength = hull.size();
    for( int i = 0; i < hullLength; i++ ){

        //In the case where there are two in bound indexes, i and i + 1
        if( i < hullLength - 1 ){

            //Add the two index to the output file referencing each other
            outFile << std::to_string(hull[i].getX()) << "," << std::to_string(hull[i].getY()) << ",";
            outFile << std::to_string(hull[i + 1].getX()) << "," << std::to_string(hull[i + 1].getY());
        }

        //In the case where the index being examined is the last in the array
        else if( i == hullLength - 1 ){

            //Add index i to the output file referencing the first item in the array
            outFile << std::to_string(hull[i].getX()) << "," << std::to_string(hull[i].getY()) << ",";
            outFile << std::to_string(hull[0].getX()) << "," << std::to_string(hull[0].getY());
        }
        outFile << "\n";
    }

    int interiorLength = interior.size();
    for( int i = 0; i < interiorLength; i++ ){

        //Add in the x and y coordinates of the interior point
        outFile << std::to_string(interior[i].getX()) << "," << std::to_string(interior[i].getY()) << ",";
        //Point references nothing
        outFile << "-1,-1\n";
    }

    outFile.close();

    return;
}
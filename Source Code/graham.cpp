/*  Author: Kang Liu
 *  Program: Graham Scan
 *  This program uses the Graham Scan algorithm to
 *  find the convex hull from a set of points.
 *  10 December, 2020
 */

#include "graham.h"

// Constructor
Graham::Graham(std::string fname)
{
    this->fname = fname;
    Graham_Scan_Algorithm();
}

// Destructor
Graham::~Graham()
{

}


void Graham::storePoints(std::string fname)
{

    std::ifstream input(fname);
    std::string line;

    // x- and y-values
    int x, y;


    Vertex tempP;                // temporary point
    std::vector<Vertex> tmpSet;  // A temporary vector to store points


    // Read the file
    while(std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string tmp;

        // Seperate the commas
        std::getline(ss, tmp, ',');
        x = std::stoi(tmp);

        std::getline(ss, tmp, ',');
        y = std::stoi(tmp);

        // Store the values into temporary point
        tempP.x = x;
        tempP.y = y;

        // Store the point to the vector
        tmpSet.push_back(tempP);

    }

    // Find the convex hull points using Graham Scan algorithm
    hullSet = Graham_Scan(tmpSet, hullSet);

    // Close the file
    input.close();
}

// Outputs the GrahamScan.csv file
void Graham::hullToCSV()
{
    // Output file name
    std::string filePath = "grahamPairs.csv";
    std::ofstream outFile;

    outFile.open(filePath, std::ofstream::out | std::ofstream::trunc);

    // Writes the convex hull points to the CSV file
    for(int i = 0; i < hullSet.size(); i++)
    {
        if(i < hullSet.size()-1)
        {
            outFile << std::to_string(hullSet[i].x) << "," << std::to_string(hullSet[i].y) << ",";
            outFile << std::to_string(hullSet[i+1].x) << "," << std::to_string(hullSet[i+1].y);
        }
        else if (i == hullSet.size()-1)
        {
            outFile << std::to_string(hullSet[i].x) << "," << std::to_string(hullSet[i].y) << ",";
            outFile << std::to_string(hullSet[0].x) << "," << std::to_string(hullSet[0].y);
        }
        outFile << "\n";
    }

    // Writes the concave points to the CSV file
    for(int j = 0; j < concaveSet.size(); j++)
    {
        outFile << std::to_string(concaveSet[j].x) << "," << std::to_string(concaveSet[j].y) << ",";
        outFile << "-1,-1\n";
    }

    // Close the file
    outFile.close();
}


// Finds the polar angle of three points
int Graham::polarAngle(Vertex P1, Vertex P2, Vertex P0)
{
    // Formula for computing the polar angle
    return ((P1.x - P0.x) * (P2.y - P0.y) - (P2.x - P0.x) * (P1.y - P0.y));
}

// Finds the distance of two points
int Graham::distance(Vertex P1, Vertex P2)
{

    // Formula for computing the distance
    int x_Distance = P1.x - P2.x;
    int y_Distance = P1.y - P2.y;
    return (x_Distance * x_Distance + y_Distance * y_Distance);
}

// Graham Scan Algorithm
std::vector<Vertex> Graham::Graham_Scan(std::vector<Vertex> pointSet, std::vector<Vertex> hullSet)
{
    int min_Y = 0;      // Minimum y-value

    int top = 2;        // Removing top points

    Vertex tmp;                  // temporary point
    int n = pointSet.size();    // the length of the vector

    // Less than 3 points (Not a convex hull)
    if (pointSet.size() < 3)
    {
        return hullSet;
    }

    int i, j;   // For-loop counter

    // Finds the lowest point (Y) and left-most (X)
    for(int i = 1; i < n; i++)
    {
        if( (pointSet[i].y < pointSet[min_Y].y) ||
        (pointSet[min_Y].y == pointSet[i].y && pointSet[i].x < pointSet[min_Y].x))
        {
            // Set min_Y to current i-value
            min_Y = i;
        }
    }

    // Set temporary point to the first point
    tmp = pointSet[0];

    // Swap places
    pointSet[0] = pointSet[min_Y];
    pointSet[min_Y] = tmp;

    // Sort from smallest to largest polar angle
    for(i = 1; i < n-1; i++)
    {
        // Set minimum y-value to i
        min_Y = i;

        for(j = i+1; j < n; j++)
        {
            // The current angle has value greater than or equal to 0
            if((polarAngle(pointSet[j], pointSet[min_Y], pointSet[0]) > 0)
            || ((polarAngle(pointSet[j], pointSet[min_Y], pointSet[0]) == 0)
            && (distance(pointSet[0], pointSet[j]) < distance(pointSet[0], pointSet[min_Y]))))
            {
                // minimum y-value's polar angle is stored in the minimum point
                min_Y = j;
            }
        }

        // Swap points again
        tmp = pointSet[i];
        pointSet[i] = pointSet[min_Y];
        pointSet[min_Y] = tmp;
    }

    // Push the three points into hull
    hullSet.push_back(pointSet[0]);
    hullSet.push_back(pointSet[1]);
    hullSet.push_back(pointSet[2]);

    // Find the rest of the points n-3
    for(i = 3; i < n; i++)
    {
        // Right-turn (clockwise) and collinear
        while(polarAngle(pointSet[i], hullSet[top], hullSet[top-1]) >= 0)
        {
                 // Push the pop_back value
                concaveSet.push_back(hullSet[top]);

                // If collinear, pop_back the point in the concave set
                if(polarAngle(pointSet[i], hullSet[top], hullSet[top-1]) == 0)
                {
                    concaveSet.pop_back();
                }

            top--;
            hullSet.pop_back();
            // Store the value before pop_back
        }

        // convex points
        hullSet.push_back(pointSet[i]);
        ++top;
    }

    return hullSet;
}

// Compile the Graham Scan Algorithm
void Graham::Graham_Scan_Algorithm()
{
    storePoints(fname);
    hullToCSV();
}
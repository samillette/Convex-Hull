#include "Graham.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>     // Convert string
#include <limits>       // Infinity
#include <algorithm>    // std::sort
#include <stack>

Graham::Graham(double x_Val, double y_Val)
{
    x = x_Val;
    y = y_Val;
}

void readFile(std::string fname, std::vector<std::vector<int>> & grid)
{
    // Open the file
    std::ifstream input(fname);
    std::string row;

    // Loop through the data row by row
    while(std::getline(input, row))
    {
        std::stringstream ss(row);      // Parsing the data --> turn it into string string
        std::vector< pair <double, double> > c_Points;   // Vector of pairs to store the data

        // Check 'auto' type
        double value1;
        double value2;

        // Inserting values into vector pairs
        while(ss >> value)
        {
            c_Points.push_back(make_pair(value1, value2))
        }
    }
}

double addPoint(stack<Point> & Stack)
{
    // Check number of points < 3 = no convex hull
    if(c_points.size() < 3)
    {
        return;
    }
    // Push the first three points
   stack.push(p0);
   stack.push(p1);
   stack.push(p2);

    for (int i = 3; i < c_points.size(); i++)
    {
        // Push the next point to the stack
        // Check the point
        // Remove if(clockwise) --> Left
        // Add to stack if(counterclockwise) --> Right
    }

}

double getCrossProduct(Point p, Point q, Point r)
{
    // If the result is negative, then the three points are rotating right in a clockwise direction.
    // Get rid of second point 'q', because it is inside the convex hull.

    return ((q[0]) - p[0])*r[1] - p[1])) - ((q[1] - p[1]) * (r[0] - p[0]));
}

double getSlope(p1, p2)
{
    if p1[0] == p2[0]
    {
        // Don't return 1 or 0 --> They are slopes
        // Return infinity
        return std::numeric_limits<double>::infinity();
    }
    else
    {
        return 1.0 * (p1[1] - p2[1]) / (p1[0]-p2[0]);
    }
    // Compare slope in unit circle

    // Recursively sort into orderly slope
    //std::sort(getSlope(p, start), (p[1],p[0]))

}
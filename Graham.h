/* Sort the points lexicograpphically by polar angle.
 * If there are three collinear points, disregard the middle point.
 * It cannot be part of the final convex hull so there is no point
 * in even considering it.
 */

//

#ifndef __GRAHAM_H__
#define __GRAHAM_H__

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>    // std::sort
#include <cmath>        // Mathematical operations and transformations


// Define a variable of a structure type
typedef struct Point
{
    // double angle;   // Polar angle
    int x;       // Check x-axis coordinate (left or right)
    int y;       // Check y-axis coordinate (up or down)

} Point;

class Graham
{
    private:

        std::string fname;  // File name

        // Vector to store the set of points and convex hull
        std::vector<Point> pointSet, hull, disregardSet;


    public:

        Graham(std::string fname);   // Constructor
        Graham();
        ~Graham();

        // // Find the polar angle between 3 points
        int polarAngle(Point P1, Point P2, Point P3);

        // // Find the distance
        int distance(Point P1, Point P2);

        // // Graham Scan Algorithm
        std::vector<Point> Graham_Scan(std::vector<Point> pointSet, std::vector<Point> hull);

        // Store points from read file
        void storePoints(std::string fname);

        // Write to CSV file
        void hullToCSV();
};

#endif /* __GRAHAM_H__ */
/*  Author: Kang Liu
 *  Program: Graham Scan
 *  This header file declares the functions, variables, and class for Graham.cpp
 *  10 December, 2020
 */

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

    int x;       // Check x-axis coordinate (left or right)
    int y;       // Check y-axis coordinate (up or down)

} Point;

class Graham
{
    private:

        std::string fname;  // File name

        // Vector to store the set of points, convex points, and concave points
        std::vector<Point> pointSet, hullSet, concaveSet;


    public:

        Graham(std::string fname);   // Constructor
        Graham();

        // Destructor
        ~Graham();

        // // Find the polar angle between 3 points
        int polarAngle(Point P1, Point P2, Point P3);

        // // Find the distance
        int distance(Point P1, Point P2);

        // // Graham Scan Algorithm
        std::vector<Point> Graham_Scan(std::vector<Point> pointSet, std::vector<Point> hullSet);

        // Store points from read file
        void storePoints(std::string fname);

        // Write to CSV file
        void hullToCSV();

        void Graham_Scan_Algorithm();
};

#endif /* __GRAHAM_H__ */
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
typedef struct Vertex
{
    int x;       // x-value
    int y;       // y-value

} Vertex;

class Graham
{
    private:

        std::string fname;  // File name

        // Vector to store the set of points, convex points, and concave points
        std::vector<Vertex> pointSet, hullSet, concaveSet;


    public:

        // Constructor
        Graham(std::string fname);
        Graham();

        // Destructor
        ~Graham();

        // // Find the polar angle between 3 points
        int polarAngle(Vertex P1, Vertex P2, Vertex P3);

        // // Find the distance
        int distance(Vertex P1, Vertex P2);

        // // Graham Scan Algorithm
        std::vector<Vertex> Graham_Scan(std::vector<Vertex> pointSet, std::vector<Vertex> hullSet);

        // Store points from read file
        void storePoints(std::string fname);

        // Write to CSV file
        void hullToCSV();

        // Run the algorithm
        void Graham_Scan_Algorithm();
};

#endif /* __GRAHAM_H__ */
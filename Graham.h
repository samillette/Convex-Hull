/* Sort the points lexicograpphically by polar angle.
 * If there are three collinear points, disregard the middle point.
 * It cannot be part of the final convex hull so there is no point
 * in even considering it.
 */

#ifndef __GRAHAM_H__
#define __GRAHAM_H__

#include <stdlib.h>
#include <stack>

// Define a variable of a structure type
struct point
{
    point *next;    // pointer to next node
    point *prev;    // Pointer to previous node
    
    double angle;   // Polar angle
    double x;       // Check x-axis coordinate (left or right)
    double y;       // Check y-axis coordinate (up or down)
};

class Graham
{
    private:
        point p0;      // Starting point --> Head (Bottom-most or left-most)
        point pN;      // Ending point --> Tail
        std::stack <double> stack;    // Create the stack
        bool show_Progress; // Show the status of the points

    public:

        Graham(double, double);


        double addpoint(std::stack<point> & Stack);  // Add the next CONNECTED point to the stack
        double Alignment(point p, point q, point r);
        double getCrossProduct(point p, point q, point r);  //(Positive or Negative) Area of Parallelogram
        double getSlope(point p, point q);    // sort points in counterclockwise order by their slope (2 points)
        double getDistance(point p, point q); // Get distance from two points

        // New work
        double polarAngle(point p, point q);    // Find polar angle
        double distance(point p, point q);      // Find distance
        double quicksort(double[]);             // Quick sort the points
        
        // From File
        void graham_Scan(point *P);     // Algorithm

        // Read File
        void readFile(std::string fname, std::vector< std::vector< std::pair <double, double>>>);

    // Output
 // (1,2,4,5) 
};

#endif /* __GRAHAM_H__ */
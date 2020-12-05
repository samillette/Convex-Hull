/* Sort the points lexicograpphically by polar angle.
 * If there are three collinear points, disregard the middle point.
 * It cannot be part of the final convex hull so there is no point
 * in even considering it.
 */

#ifndef __GRAHAM_H__
#define __GRAHAM_H__

// Define a variable of a structure type
struct Point
{
    double x;       // Check x-axis coordinate (left or right)
    double y;       // Check y-axis coordinate (up or down)
};

class Graham
{
    private:

        Point p0;      // Starting point --> Head (Bottom-most or left-most)
        Point pN;      // Ending point --> Tail

    public:

        double addPoint(stack<Point> & Stack);  // Add the next CONNECTED point to the stack
        double Alignment(Point p, Point q, Point r);
        double getCrossProduct(Point p, Point q, Point r);  //(Positive or Negative) Area of Parallelogram
        double getSlope(p1, p2);    // sort points in counterclockwise order by their slope (2 Points)
        double getDistance(p1, p2); // Get distance from two points
        void readFile(std::string fname, std::vector<std::vector<int>> & grid);

}

#endif /* __GRAHAM_H__ */
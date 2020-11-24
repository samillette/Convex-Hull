#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <cstdlib>

class Line{
    private:
        double slope;
        double yIntercept;

        double calculateYIntercept(Point p1, Point p2, double slope);
    public:
        Line(Point p1, Point p2);

        double getYIntercept();
        double getSlope();

        double calculateYFromX(int x);
};

#endif
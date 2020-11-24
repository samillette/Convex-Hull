#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <cstdlib>
#include <cmath>

class Line{
    private:
        //y = mx + b baby
        double slope;

        //intercept is intentionally ambiguous, it could either represent a y intercept or an x
        double intercept;

        //this function is only called in the case where the line is not infinite in slope
        double calculateYIntercept(Point p1, Point p2, double slope);

    public:
        Line(Point p1, Point p2);

        double getIntercept();
        double getSlope();

        double getDistanceToPoint(Point pExamined);
};

#endif
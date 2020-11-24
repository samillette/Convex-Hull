#include "line.h"

double Line::calculateYIntercept(Point p1, Point p2, double slope){
    int p1XAbsoluteVal = abs(p1.getX());
    int p2XAbsoluteVal = abs(p2.getX());

    Point closest = p1;

    if ( p1XAbsoluteVal > p2XAbsoluteVal ){
        closest = p2;
    }
    else{
        closest = p1;
    }

    //from here we have our slope, m, our y value being examined, closest.getY(), and our x value, closest.getX()
    //this is useful because we can plug those into our linear equation and by algebra obtain b, our y intercept

    double yIntercept = closest.getY() - (slope * closest.getX());
    return yIntercept;
}

Line::Line(Point p1, Point p2){
    this -> slope = (p2.getY() - p1.getY())/(p2.getX() - p1.getX());
    this -> yIntercept = calculateYIntercept(p1, p2, slope);
}

double Line::getYIntercept(){
    return yIntercept;
}

double Line::getSlope(){
    return slope;
}

double Line::calculateYFromX(int x){
    return 69.69;
}
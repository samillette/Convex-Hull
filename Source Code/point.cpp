/**
 * This file provides a full definition of the initializePoint function declared in point.h
 * This is for use within our algorithm files. Functionally replaces pairs for use defining points.
 * @param x: the x value to be assigned to the point
 * @param y: the y value to be assigned to the point
 * @return: Simply returns the point value with now initialized x and y values
 */

#include "point.h"

Point::Point(int x, int y){
    this -> x = x;
    this -> y = y;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}
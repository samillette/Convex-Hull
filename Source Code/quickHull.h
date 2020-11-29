#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "point.h"
#include "line.h"

#include <vector>
#include <string>

std::vector< Point > quickHullDivideBase(std::vector < Point > setOfPoints, Line dividingSegment);

std::vector< Point > quickHull(std::vector< Point > allPoints);

void quickHull( std::string inFilePath );

#endif
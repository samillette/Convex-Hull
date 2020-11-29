#ifndef CONVEXFILEHANDLING_H
#define CONVEXFILEHANDLING_H

#include "point.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector< Point > csvToVector(std::string filePath, Point & minX, Point & maxX);

void hullVectorToCSV(std::string filePath, std::vector< Point > hull, std::vector< Point > interior);

#endif
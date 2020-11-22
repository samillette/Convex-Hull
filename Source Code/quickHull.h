#ifndef QUICKHULL_H
#define QUICKHULL_H

#include "point.h"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector< Point > csvToVector(std::string filePath);

#endif
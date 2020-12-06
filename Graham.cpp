#include "Graham.h"

// Constructor
Graham::Graham(std::string fname)
{
    this->fname = fname;
    storePoints(fname);
    hullToCSV();
}

// Destructor
Graham::~Graham()
{

}

void Graham::storePoints(std::string fname)
{

    std::ifstream input(fname);
    std::string line;
    int x, y;
    Point tempP;
    std::vector<Point> dot;
    while(std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string tmp;

        std::getline(ss, tmp, ',');
        x = std::stoi(tmp);

        std::getline(ss, tmp, ',');
        y = std::stoi(tmp);

        tempP.x = x;
        tempP.y = y;

        dot.push_back(tempP);
        // hull = Graham_Scan(dot, hull);
    }
    hull = Graham_Scan(dot, hull);
    // for(int i = 0; i < hull.size(); i++)
    // {
    //     std::cout << "X:" << hull[i].x << "\tY:" << hull[i].y << std::endl;
    // }
    // std::cout << "\n***************************" << std::endl;
    // for(int i = 0; i < dot.size(); i++)
    // {
    //     std::cout << "\nX:" << dot[i].x << "\tY:" << dot[i].y;
    // }
        // printPoints();

    // Close the file
    input.close();
}

void Graham::hullToCSV()
{
    std::string filePath = "GrahamScan.csv";
    std::ofstream outFile;

    outFile.open(filePath, std::ofstream::out | std::ofstream::trunc);


    for(int i = 0; i < hull.size(); i++)
    {
        if(i < hull.size()-1)
        {
            outFile << std::to_string(hull[i].x) << "," << std::to_string(hull[i].y) << ",";
            outFile << std::to_string(hull[i+1].x) << "," << std::to_string(hull[i+1].y);
        }
        else if (i == hull.size()-1)
        {
            outFile << std::to_string(hull[i].x) << "," << std::to_string(hull[i].y) << ",";
            outFile << std::to_string(hull[0].x) << "," << std::to_string(hull[0].y);
        }
        outFile << "\n";
    }

    // std::vector<Point> temp;
    // temp.reserve(hull.size() + disregardSet.size());
    // temp.insert(temp.end(), hull.begin(), hull.end());
    // temp.insert(temp.end(), disregardSet.begin(), disregardSet.end());

    // std::sort(temp.begin(), temp.end());
    // auto it = std::unique(temp.begin(), temp.end());
    // bool wasUnique = (it == temp.end());

    for(int i = 0; i < disregardSet.size(); i++)
    {
        std::cout << "X:" << disregardSet[i].x << "\tY:" << disregardSet[i].y << std::endl;
    }

    for(int j = 0; j < disregardSet.size(); j++)
    {
        outFile << std::to_string(disregardSet[j].x) << "," << std::to_string(disregardSet[j].y) << ",";
        outFile << "-1, -1\n";
    }

    outFile.close();
}



// Finds the polar angle of three points
int Graham::polarAngle(Point P1, Point P2, Point P0)
{

    return ((P1.x - P0.x) * (P2.y - P0.y) - (P2.x - P0.x) * (P1.y - P0.y));
}

// Finds the distance of two points
int Graham::distance(Point P1, Point P2)
{
    int x_Distance = P1.x - P2.x;
    int y_Distance = P1.y - P2.y;
    return (x_Distance * x_Distance + y_Distance * y_Distance);
}


std::vector<Point> Graham::Graham_Scan(std::vector<Point> pointSet, std::vector<Point> hull)
{

    int i, j , k = 0;
    int top = 2;

    Point tmp;  // temporary point
    int n = pointSet.size();

    // Less than 3 points
    if (pointSet.size() < 3)
    {
        return hull;
    }

    // Finds the lowest point (Y) and left-most (X)
    for(int i = 1; i < n; i++)
    {
        if(pointSet[i].y < pointSet[k].y || pointSet[i].y == pointSet[k].y && pointSet[i].x < pointSet[k].x)
        {
            // Set k to minimum point
            k = i;
        }
    }

    // Set temporary point to the first point
    tmp = pointSet[0];

    // Swap places
    pointSet[0] = pointSet[k];
    pointSet[k] = tmp;

    // Sort from smallest to largest polar angle
    for(i = 1; i < n-1; i++)
    {
        k = i;

        for(j = i+1; j < n; j++)
        {
            int angle1 = polarAngle(pointSet[j], pointSet[k], pointSet[0]);
            int angle2 = polarAngle(pointSet[j], pointSet[k], pointSet[0]);
            // Current polar angle > the previous polar angle
            if(angle1 > 0  || angle2 == 0 && distance(pointSet[0], pointSet[j]) < distance(pointSet[0], pointSet[k]))
            {
                // k-> polar angle is stored in the minimum point
                // or the same distance from the nearest origin
                k = j;
            }
        }

        // Swap points again
        tmp = pointSet[i];
        pointSet[i] = pointSet[k];
        pointSet[k] = tmp;
    }


    // Push the three points into hull
    hull.push_back(pointSet[0]);
    hull.push_back(pointSet[1]);
    hull.push_back(pointSet[2]);

    // Find the rest of the points n-3
    for(i = 3; i < n; i++)
    {
        // Not left-turn
        while(polarAngle(pointSet[i], hull[top], hull[top-1]) >= 0)
        {
            top--;
            if(polarAngle(pointSet[i], hull[top], hull[top-1]) <  0)
            {
                disregardSet.push_back(pointSet[i]);
            }
            hull.pop_back();

        }

        // Point connecting the current point to the all points
        hull.push_back(pointSet[i]);

        ++top;

    }
    // for(int i = 0; i < disregardSet.size(); i++)
    // {
    //     std::cout << "X:" << disregardSet[i].x << "\tY:" << disregardSet[i].y << std::endl;
    // }
    return hull;
}


int main(int argc, char* argv[])
{
    std::string fname(argv[1]);

    Graham Algorithm(fname);

    return 0;
}
#ifndef LAB4_PARALLELOGRAM_H
#define LAB4_PARALLELOGRAM_H

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class Parallelogram {
private:
    vector<Point> *points;
    float perimeter;
    float square;

public:
    Parallelogram();
    float get_perimeter();
    float get_square();
    friend ostream &operator<<(ostream &, Parallelogram &);
    ~Parallelogram();
};


#endif

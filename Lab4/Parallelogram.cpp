#include <vector>
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Parallelogram.h"

using namespace std;

float calculate_perimeter(vector<Point> &points) {
    return 2 * (
            hypot(points[0].x - points[1].x, points[0].y - points[1].y) +
            hypot(points[2].x - points[1].x, points[2].y - points[1].y)
            );
}

float calculate_square(vector<Point> &points) {
    float v1[2] = {points[1].x - points[0].x, points[1].y - points[0].y};
    float v1m = hypot(v1[0], v1[1]);
    float v2[2] = {points[3].x - points[0].x, points[3].y - points[0].y};
    float v2m = hypot(v2[0], v2[1]);
    return v1m * v2m * sin(acos((v1[0] * v2[0] + v1[1] * v2[1]) / v1m / v2m));
}

Parallelogram::Parallelogram() {
    points = new vector<Point>();
    for (int i = 0; i < 4; i++) {
        float x, y;
        cout << "p[" << i << "].x: ";
        cin >> x;
        cout << "p[" << i << "].y: ";
        cin >> y;
        points->push_back(Point(x, y));
    }
    perimeter = calculate_perimeter(*points);
    square = calculate_square(*points);
}

float Parallelogram::get_perimeter() {
    return perimeter;
}

float Parallelogram::get_square() {
    return square;
}

ostream &operator<<(ostream &out, Parallelogram &parallelogram) {
    out << "Parallelogram:\n + points:";
    for (Point point: *parallelogram.points) {
        out << " (" << point.x << ", " << point.y << ")";
    }
    out << "\n + perimeter: " << parallelogram.perimeter << endl;
    out << " + square: " << parallelogram.square << endl;
    return out;
}

Parallelogram::~Parallelogram() {
    delete points;
}

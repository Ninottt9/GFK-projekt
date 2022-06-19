#pragma once

/**
* @brief Punkt w przestrzeni
*/
struct Point {
    float x, y, z;
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    void operator+=(const Point& point) {
        x += point.x;
        y += point.y;
        z += point.z;
    }
    friend Point operator+(Point& point1, Point& point2);
};
inline Point operator+(Point& point1, Point& point2) {
    return Point(point1.x + point2.x, point1.y + point2.y, point1.z + point2.z);
}

/**
* @brief Kolor RGB
*/
struct Color {
    double R, G, B;
    Color(double _R, double _G, double _B) : R(_R), G(_G), B(_B) {}
};

/**
* @brief Odcinek w przestrzeni
*/
struct Segment {
    Point begin, end;
    Color color;
    Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
    void operator+=(const Point& point) {
        begin += point;
        end += point;
    }
};
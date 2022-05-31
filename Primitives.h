#pragma once

struct Point {
    float x, y, z;
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    void operator+=(const Point& point) {
        x += point.x;
        y += point.y;
        z += point.z;
    }
};

struct Color {
    int R, G, B;
    Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
};

struct Segment {
    Point begin, end;
    Color color;
    Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
    void operator+=(const Point& point) {
        begin += point;
        end += point;
    }
};
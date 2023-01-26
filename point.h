#ifndef _POINT_H
#define _POINT_H

#include <iostream>

using namespace std;

class Point{
public:
    Point(){}
    Point(int x_in, int y_in): x(x_in), y(y_in){};
    Point(const Point& p_in): x(p_in.x), y(p_in.y){};
    friend ostream& operator<<(ostream& out, Point p){
        out <<"("<<p.x<<", "<<p.y<<")";
        return out;
    }
    Point operator=(Point p){
        x = p.x;
        y = p.y;
        return *this;
    }
    Point operator+(Point p){
        Point ans;
        ans.x = x + p.x;
        ans.y = y + p.y;
        return ans;
    }
    Point operator+=(Point p){
        x += p.x;
        y += p.y;
        return *this;
    }
    int x;
    int y;
};

#endif
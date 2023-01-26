#ifndef _RGB_H_
#define _RGB_H_
#include <iostream>

using namespace std;

class RGB{
public:
    RGB(){}
    RGB(const RGB& rgb): r(rgb.r), g(rgb.g), b(rgb.b){};
    RGB(int rgb_r, int rgb_g, int rgb_b): r(rgb_r), g(rgb_g), b(rgb_b){};
    friend ostream& operator<<(ostream& out, RGB rgb){
        out <<"("<<rgb.r<<", "<<rgb.g<<", "<<rgb.b<<")";
        return out;
    }
    RGB operator+(RGB rgb){
        RGB ans;
        ans.r = r+rgb.r;
        ans.g = g+rgb.g;
        ans.b = b+rgb.b;
        return ans;
    }
    RGB operator-(RGB rgb){
        RGB ans;
        ans.r = r-rgb.r;
        ans.g = g-rgb.g;
        ans.b = b-rgb.b;
        return ans;
    }
    int r;
    int g;
    int b;
};
#endif
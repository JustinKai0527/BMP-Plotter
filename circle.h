#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <iostream>
#include "base.h"
using namespace std;

class Circle: public Base{
public: 
    friend class Handle;
    Circle(){}
    Circle(Point a, int _radius, RGB rgb): radius(_radius){
        this->ref = a;
        this->color = rgb;
    };
    void operator*= (double scale){                 //函數裡面要delete
        radius*=scale;  
    };
    void draw(Bitmap& map, int method) const{
        map.drawSolidCircle(this->ref,radius,this->color,method);
    };
    Base* copy() const{
        Base* c = new Circle(this->ref,radius,this->color);
        return c;
    };
private:
    int radius;
};




#endif
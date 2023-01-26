#ifndef _RECT_H_
#define _RECT_H_
#include <iostream>
#include "base.h"
#include "point.h"
#include "rgb.h"
#include "bitmap.h"
using namespace std;

class Rect: public Base{
public:
    friend class Handle;
    Rect(){}
    Rect(Point a,int _width,int _height,RGB r):width(_width),height(_height){
        this->ref = a;
        this->color = r;
    };
    void operator*= (double scale) {
        this->width *=scale;
        this->height *=scale;
    };
    void draw(Bitmap& map, int method) const {
        map.drawSolidRect(ref,width,height,color,method);
    };
    Base* copy() const {
        Base* rect = new Rect(this->ref,width,height,color);
        return rect;
    };
private:
    int width;
    int height;
};




#endif
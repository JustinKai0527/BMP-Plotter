#ifndef _TRI_H_
#define _TRI_H_
#include <iostream>
#include "base.h"
using namespace std;

class Tri: public Base{
public:
    friend class Handle;
    Tri(){}
    Tri(Point a,int _left,int _right,int _height,RGB _rgb): left(_left),right(_right),height(_height){
        this->color = _rgb;
        this->ref = a;
    };
    void operator*= (double scale){
        left*=scale;
        right*=scale;
        height*=scale;
    };
    void draw(Bitmap& map, int method) const{
        map.drawSolidTriangle(this->ref,left,right,height,this->color,method);
    };
    Base* copy() const{
        Base* t = new Tri(this->ref,left,right,height,this->color);
        return t;
    };
private:
    int left;
    int right;
    int height;
};




#endif
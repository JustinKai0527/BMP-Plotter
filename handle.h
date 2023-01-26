#ifndef _HANDLE_H_
#define _HENDLE_H_
#include <iostream>
#include "base.h"
#include "rgb.h"
#include "point.h"
#include "circle.h"
#include "rect.h"
#include "tri.h"
// #include "desktop.h"
using namespace std;

class Handle{
    // friend class Desktop;
    // friend Desktop& operator<< (Desktop& o, const Handle& h);
public:
    // Handle(){}
    Handle(){};       //why要new
    Handle(const Handle& h): p(h.p) {
        ++(p->count);
    }                                //為甚麼是傳Handle&   因為我不是要他的值，是她這個記憶體裡面的東西
    Handle(Point a,int _radius,RGB _rgb): p(new Circle(a,_radius,_rgb)){};
    Handle(Point a,int width,int height,RGB _rgb): p(new Rect(a,width,height,_rgb)){};
    Handle(Point a,int left,int right,int height,RGB _rgb): p(new Tri(a,left,right,height,_rgb)){};
    ~Handle() {
        unhook();
    }
    void draw(Bitmap& map,int method) const {
        // this->p->draw(map,method);
        // map.setPixel(p->ref,p->color,method);
        this->p->draw(map,method);
    }
    Handle operator=(Handle h){
        if(p == NULL){
            p = h.p;
            ++(p->count);
        }
        else if (p != h.p) {
            unhook();
            p = h.p;
            ++(p->count);
        }
        // this->p = NULL;
        // this->p = h.p;
        return *this;
        // this->p = NULL;
        // Handle newH;
        // newH.p=h.p->copy();
        // *this = newH;
        // return *this;
    }
    Handle operator+(Point a){
        Handle newH;
        newH.p=this->p->copy();
        newH.p->ref += a;
        return newH;
    }
    Handle operator+=(Point a){
        if (p->count > 1) {
            Base* other = p->copy(); 
            unhook();
            p = other;
        }
        this->p->ref += a;
        return *this;
    }
    Handle operator*(double scale){
        Handle h;
        h.p = this->p->copy();
        h.p->operator*=(scale);
        return h;
    }
    Handle operator*=(double scale){
        if (p->count > 1) {
            Base* other = p->copy(); 
            unhook();
            p = other;
        }
        this->p->operator*=(scale);
        return *this;
    }
    Handle setColor(RGB rgb){
        if (p->count > 1) {
            Base* other = p->copy(); 
            unhook();
            p = other;
        }
        this->p->setColor(rgb);
        return *this;
    }

private:
    void unhook() {
        --(p->count);
        if (p->count == 0) 
            delete p;
    }
    Base* p = NULL;
};
#endif


// #ifndef _HANDLE_H_
// #define _HENDLE_H_
// #include <iostream>
// #include "base.h"
// #include "rgb.h"
// #include "point.h"
// #include "circle.h"
// #include "rect.h"
// #include "tri.h"
// // #include "desktop.h"
// using namespace std;

// class Handle{
//     // friend class Desktop;
//     // friend Desktop& operator<< (Desktop& o, const Handle& h);
// public:
//     Handle(){}
//     Handle(const Handle& h): p(h.p) {
//         ++(p->count);
//     }                                //為甚麼是傳Handle&   因為
//     Handle(Point a,int _radius,RGB _rgb): p(new Circle(a,_radius,_rgb)){};
//     Handle(Point a,int width,int height,RGB _rgb): p(new Rect(a,width,height,_rgb)){};
//     Handle(Point a,int left,int right,int height,RGB _rgb): p(new Tri(a,left,right,height,_rgb)){};
//     ~Handle() {}
//     void draw(Bitmap& map,int method) const {
//         // this->p->draw(map,method);
//         // map.setPixel(p->ref,p->color,method);
//         this->p->draw(map,method);
//     }
//     Handle operator=(Handle h){
//         this->p = NULL;
//         this->p = h.p;
//         return *this;
//         // this->p = NULL;
//         // Handle newH;
//         // newH.p=h.p->copy();
//         // *this = newH;
//         // return *this;
//     }
//     Handle operator+(Point a){
//         Handle newH;
//         newH.p=this->p->copy();
//         newH.p->ref += a;
//         return newH;
//     }
//     Handle operator+=(Point a){
//         Handle newH;
//         newH.p=this->p->copy();
//         newH.p->ref += a;
//         *this = newH;
//         return *this;
//     }
//     Handle operator*(double scale){
//         Handle h;
//         h.p = this->p->copy();
//         h.p->operator*=(scale);
//         return h;
//     }
//     Handle operator*=(double scale){
//         this->p->operator*=(scale);
//         return *this;
//     }
//     Handle setColor(RGB rgb){
//         this->p->setColor(rgb);
//         return *this;
//     }

// private:
//     Base* p = NULL;
// };
// #endif


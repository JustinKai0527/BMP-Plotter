
#ifndef _BASE_H_
#define _BASE_H_

#include "point.h"
#include "bitmap.h"

class Base {
protected:
    Base():count(1) {}
    Base(const Point& _ref, const RGB& _color): count(1), ref(_ref), color(_color) {}
public:
    virtual ~Base() {}
    void setColor(const RGB& c) {
        color = c;
    }
    virtual void operator*= (double scale) = 0;
    void operator+= (const Point& p) {
        ref += p;
    }
    virtual void draw(Bitmap& map, int method) const=0;     //NULL
    virtual Base* copy() const = 0;
    int count;

    Point ref;
    RGB color;
};

#endif // _BASE_H_

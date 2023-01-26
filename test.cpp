#include <iostream>
#include "desktop.h"
using namespace std;
int main() {
    // Circle
    Handle a(Point(-50,-50), 100, RGB(128,0,0));
    // Rect
    Handle b(Point(0,0), 100, 50, RGB(0,128,0));
    // Triangle
    Handle c(Point(-30,-30), 50, 150, 50, RGB(0,0,128));
    Desktop desk(400,400);
    desk << a << b << c;
    desk.save("1.bmp");
    desk.clear();
    desk + a + b + c;
    desk.save("2.bmp");
    // shallow copy
    b = a;
    // copy-on-write
    b += Point(50,0);
    b *= 1.2;
    c *= 0.5;
    c.setColor(RGB(255,0,0));
    desk.clear();
    desk + a + b - c;
    desk.save("3.bmp");
    // No problem with using array
    desk.clear();
    int num = 30;
    Handle *list = new Handle[num];
    list[0] = Handle(Point(0,0), 190, RGB(255,0,0));
    double u = 255.0;
    for (int i=1; i<num; ++i) {
    list[i] = list[i-1] * 0.9;
    u *= 0.9;
    list[i].setColor(RGB(int(u),0,0));
    }
    for (int i=0; i<num; ++i)
    desk + list[i] - (list[i]*0.95);
    desk.save("tunnel.bmp");
    delete []list;
    return 0;
}
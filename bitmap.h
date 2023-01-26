#ifndef _BITMAP_H_
#define _BITMAP_H_
#include <iostream>
#include "bitmapbase.h"
using namespace std;

class Bitmap: public BitmapBase{
public:
    Bitmap(int x,int y){  
        xSize=x;
        ySize=y;
        image = new unsigned char[3*xSize*ySize];
    };
    ~Bitmap(){delete[] image;}
    void drawSolidTriangle(const Point& ref, int left, int right, int height, const RGB& c, int m){
        float l = left;
        float h = height;
        float r = right;
        for(int i=-(l-1); i<0; i++){
            for(float j=0; j<(h/l)*(i+l); j++){
                int k = j;
                Point a(i,k);
                a+=ref;
                this->setPixel(a,c,m);
            }
        }
        for(int i=0; i<r; i++){
            for(float j = (float)h-(h/r)*i; j>=0; j--){
                int k = j;
                Point a(i,k);
                a+=ref;
                this->setPixel(a,c,m);
            }
        }
        
    };
    void drawSolidRect(const Point& base, int width, int height, const RGB& c, int m){
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                Point a(j,i);
                a+=base;
                this->setPixel(a,c,m);
            }
        }
    };
    void drawSolidCircle(const Point& center, int radius, const RGB& c, int m){
        int r = radius;
        for(int i=-r; i<=0; i++){
            for(int j=0; j<=sqrt(r*r-i*i); j++){
                if(j==0){
                    Point a(i,j);
                    a+=center;
                    this->setPixel(a,c,m);
                }
                else{
                    Point a(i,j);
                    a+=center;
                    this->setPixel(a,c,m);
                    Point b(i,-j);
                    b+=center;
                    this->setPixel(b,c,m);
                }
            }
        }     
        for(int i=1; i<=r; i++){
            for(int j=0; j<=sqrt(r*r-i*i); j++){
                if(j==0){
                    Point a(i,j);
                    a+=center;
                    this->setPixel(a,c,m);
                }
                else{
                    Point a(i,j);
                    a+=center;
                    this->setPixel(a,c,m);
                    Point b(i,-j);
                    b+=center;
                    this->setPixel(b,c,m);
                }
            }
        }
    };

private:
    
};

#endif
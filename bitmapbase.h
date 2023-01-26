
#ifndef _BITMAPBASE_H_
#define _BITMAPBASE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "point.h"
#include "rgb.h"

class BitmapBase {
public:
    virtual void drawSolidTriangle(const Point& ref, int left, int right, int height, const RGB& c, int m) = 0;
    virtual void drawSolidRect(const Point& base, int width, int height, const RGB& c, int m) = 0;
    virtual void drawSolidCircle(const Point& center, int radius, const RGB& c, int m) = 0;
    
    BitmapBase(){};

    void setPixel(const Point& p, const RGB& c, int method) {
        setPixel(p.x, p.y, c, method);
    }

    void setPixel(int x, int y, const RGB& c, int method) {
        unsigned char r, g, b;

        x += xSize / 2;
        y += ySize / 2;

        if (x<0) return;
        if (y<0) return;
        if (x>xSize) return;
        if (y>ySize) return;

        int offset = (y * xSize + x) * 3;
        b = image[offset];
        g = image[offset+1];
        r = image[offset+2];
        if (method < 0) {
            b = (b >= c.b)? (unsigned char)(b-c.b): '\0';
            g = (g >= c.g)? (unsigned char)(g-c.g): '\0';
            r = (r >= c.r)? (unsigned char)(r-c.r): '\0';
        }
        else if (method > 0) {
            b = (b <= 255-c.b)? (unsigned char)(b+c.b): (unsigned char)(255);
            g = (g <= 255-c.g)? (unsigned char)(g+c.g): (unsigned char)(255);
            r = (r <= 255-c.r)? (unsigned char)(r+c.r): (unsigned char)(255);
        }
        else {
            b = c.b;
            g = c.g;
            r = c.r;
        }
        image[offset]  = b;
        image[offset+1]  = g;
        image[offset+2]  = r;
    }

    void clear() {
        memset(image, '\0', 3*xSize*ySize);
    }
    int save(const char* filename) const {
        unsigned char header[54] = {
            0x42, 0x4d, 0, 0, 0, 0, 0, 0, 0, 0,
            54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0
        };

        long file_size = (long)xSize * (long)ySize * 3 + 54;
        header[2] = (unsigned char)(file_size &0x000000ff);
        header[3] = (file_size >> 8) & 0x000000ff;
        header[4] = (file_size >> 16) & 0x000000ff;
        header[5] = (file_size >> 24) & 0x000000ff;

        long width = xSize;
        header[18] = width & 0x000000ff;
        header[19] = (width >> 8) &0x000000ff;
        header[20] = (width >> 16) &0x000000ff;
        header[21] = (width >> 24) &0x000000ff;

        long height = ySize;
        header[22] = height &0x000000ff;
        header[23] = (height >> 8) &0x000000ff;
        header[24] = (height >> 16) &0x000000ff;
        header[25] = (height >> 24) &0x000000ff;

        FILE *fp;
        if (!(fp = fopen(filename, "wb")))
            return -1;

        fwrite(header, sizeof(unsigned char), 54, fp);
        fwrite(image, sizeof(unsigned char), (size_t)(long)xSize * ySize * 3, fp);

        fclose(fp);
        return 0;
    }

protected:
    int xSize;
    int ySize;
    unsigned char *image;
};

#endif // _BITMAPBASE_H_ 

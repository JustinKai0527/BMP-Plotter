#ifndef _DESKTOP_H_
#define _DESKTOP_H_

#include "bitmap.h"
#include "handle.h"

class Desktop {
public:
    Desktop(int width, int height): map(width, height) {}
    Desktop& operator<< (const Handle& h) {
        h.draw(map, 0);
        return *this;
    }
    Desktop& operator+ (const Handle& h) {
        h.draw(map, 1);
        return *this;
    }
    Desktop& operator- (const Handle& h) {
        h.draw(map, -1);
        return *this;
    }
    void clear() {
        map.clear();
    }
    void save(const char* filename) const {
        map.save(filename);
    }

protected:
    Bitmap map;

};


#endif // _DESKTOP_H_


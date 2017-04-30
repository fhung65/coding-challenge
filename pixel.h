#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
  public:
    Pixel* right;
    Pixel* down;
    Pixel(char v);
    char val;
};

#endif

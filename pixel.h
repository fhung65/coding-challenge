#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
  private:
  public:
    Pixel* right;
    Pixel* down;
    Pixel(char v);
    char val;
    Pixel* mesh(int nrows, int ncols);
};

#endif

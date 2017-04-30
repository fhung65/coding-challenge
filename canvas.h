#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "pixel.h"

class Canvas {
  private:
    vector<Pixel*> Cols;
    vector<Pixel*> Rows;
  public:
    Canvas(int nrows, int ncols);
    Canvas(const char* filename);
    void add_row(int before);
    void add_col(int before);
    void set_char(int row, int col);
    void draw();
};

#endif

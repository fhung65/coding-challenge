#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "pixel.h"

class Canvas {
  private:
    std::vector<Pixel*> m_Cols;
    std::vector<Pixel*> m_Rows;
  public:
    Canvas(unsigned nrows, unsigned ncols, char v);
        // v is by default '\0'
    Canvas(const char* filename);
    void add_row(unsigned pos, char v);
    void add_col(unsigned pos, char v);
    void set_char(unsigned row, unsigned col);
    void draw();
};

#endif

#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

class Canvas {
  private:
    std::vector< std::vector<char> > m_Rows;
    std::vector<int> m_Rmap;
    std::vector<int> m_Cmap;
  public:
    Canvas(unsigned nrows, unsigned ncols, char v);
        // v is by default '\0'
    Canvas(const char* filename);
    void add_row(unsigned pos, char v);
        // v is by default '\0'
    void add_col(unsigned pos, char v);
        // v is by default '\0'
    bool set(unsigned row, unsigned col, char v);
    void draw();
};

#endif

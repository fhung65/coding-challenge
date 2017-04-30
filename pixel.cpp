#include "pixel.h"
#include <stddef.h>

Pixel::Pixel(char v)
: val(v),
  right(NULL),
  down(NULL)
{}

Pixel* Pixel::mesh(int nrows, int ncols) {

    Pixel* p;
    Pixel** current_row = new Pixel*[ncols];

    current_row[0] = this;
    for (int i = 0; i < ncols - 1; i++) {
        p = new Pixel('0');
        current_row[i]->right = p;
        current_row[i+1] = p;
    }

    for (int i = 0; i < nrows-1; i++) {

        p = new Pixel('0');
        current_row[0]->down = p;
        current_row[0] = p;

        for (int j = 1; j < ncols; j++) {
            p = new Pixel('0');
            current_row[j-1]->right = p;
            current_row[j]->down = p;
            current_row[j] = p;
        }
    }

    return this;
}

#include "pixel.h"
#include <stddef.h>

Pixel::Pixel(char v)
: val(v),
  right(NULL),
  down(NULL)
{}

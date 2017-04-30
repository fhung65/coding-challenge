#include canvas.h

Canvas::Canvas(int nrows, int ncols) {
	this->Rows = vector<Pixel*>(nrows);
	this->Cols = vector<Pixel*>(ncols);
}

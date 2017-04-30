#include "pixel.h"
#include "canvas.h"
#include <vector>
#include <stddef.h>
#include <iostream>

Canvas::Canvas(unsigned nrows, unsigned ncols, char v='\0') {
	/*
     * nrows - number of rows in total grid created
     *
     * ncols - number of cols in total grid created
     *
     * v     - value to be filled into the grid
	 */

	if (nrows <= 0 || ncols <= 0)
		return;

	m_Rows = std::vector<Pixel*>(nrows);
	m_Cols = std::vector<Pixel*>(ncols);

	Pixel* p = new Pixel(v);
    Pixel** current_row = new Pixel*[ncols];

    current_row[0] = p;
	m_Cols[0] = p;

    for (int i = 0; i < ncols - 1; i++) {
        p = new Pixel(v);
        current_row[i]->right = p;
        current_row[i+1] = p;

		// fill in the columns vector
        m_Cols[i+1] = p;
    }

    for (int i = 0; i < nrows-1; i++) {

        p = new Pixel(v);
        current_row[0]->down = p;
        current_row[0] = p;

        for (int j = 1; j < ncols; j++) {
            p = new Pixel(v);
            current_row[j-1]->right = p;
            current_row[j]->down = p;
            current_row[j] = p;
        }
    }

	// fill in the rows vector
	p = m_Cols[0];
	for (int i = 0; i < nrows; i++) {
		m_Rows[i] = p;
		p = p->down;
	}
}

void Canvas::draw() {

	Pixel* c = m_Cols[0];
	Pixel* r = m_Cols[0];

	while (r != NULL) {
		c = r;
		while (c != NULL) {
				std::cout << c->val;
			c = c->right;
		}
		std::cout << '\n';
		r = r->down;
	}
}

void Canvas::add_col(unsigned pos, char v='\0') {
	/*
	 * put new pixel at pos
	 * if after > number of columns, just adds at end
	 *
	 */

	Pixel* p1;
	Pixel* p2;

	if (pos > m_Cols.size()) {
		pos = m_Cols.size();
	}
	m_Cols.insert(m_Cols.begin() + pos, new Pixel(v));

	// add the new column
	p1 = m_Cols[pos];
	for (int i = 1; i < m_Rows.size(); i++) {
		p1->down = new Pixel(v);
		p1 = p1->down;
	}

	if (pos < m_Cols.size()-1) {
		// if new pixels aren't last column,
		// update right pointers of new pixels
		p1 = m_Cols[pos];
		p2 = m_Cols[pos+1];

		for (int i = 0; i < m_Rows.size(); i++) {

			p1->right = p2;
			p1 = p1->down;
			p2 = p2->down;
		}
	}

	if (0 < pos) {
		// if new pixels aren't the first column,
		// update right pointers of pixels to the left
		p1 = m_Cols[pos-1];
		p2 = m_Cols[pos];

		for (int i = 0; i < m_Rows.size(); i++) {

			p1->right = p2;
			p1 = p1->down;
			p2 = p2->down;
		}
	} else {
		// if they are the new first column,
		// also need to update the vector
		p1 = m_Cols[pos];
		for (int i = 0; i < m_Rows.size(); i++) {
			m_Rows[i] = p1;
			p1 = p1->down;
		}
	}
}

void Canvas::add_row(unsigned pos, char v) {
	/*
	 * put new pixel at pos
	 * if after > number of columns, just adds at end
	 *
	 */

	Pixel* p1;
	Pixel* p2;

	if (pos > m_Rows.size()) {
		pos = m_Rows.size();
	}
	m_Rows.insert(m_Rows.begin() + pos, new Pixel(v));

	// add the new row
	p1 = m_Rows[pos];
	for (int i = 1; i < m_Cols.size(); i++) {
		p1->right = new Pixel(v);
		p1 = p1->right;
	}

	if (pos < m_Rows.size()-1) {
		// if new pixels aren't last row,
		// update down pointers of new pixels
		p1 = m_Rows[pos];
		p2 = m_Rows[pos+1];

		for (int i = 0; i < m_Cols.size(); i++) {

			p1->down = p2;
			p1 = p1->right;
			p2 = p2->right;
		}
	}

	if (0 < pos) {
		// if new pixels aren't the first row,
		// update down pointers of pixels to the left
		p1 = m_Rows[pos-1];
		p2 = m_Rows[pos];

		for (int i = 0; i < m_Cols.size(); i++) {

			p1->down = p2;
			p1 = p1->right;
			p2 = p2->right;
		}
	} else {
		// if they are the new first row,
		// also need to update the vector
		p1 = m_Rows[pos];
		for (int i = 0; i < m_Cols.size(); i++) {
			m_Cols[i] = p1;
			p1 = p1->right;
		}
	}
}

#include "canvas.h"
#include <vector>
#include <stddef.h>
#include <iostream>

Canvas::Canvas(unsigned nrows, unsigned ncols, char v='\0') {
	/*
	 * An Ascii canvas
	 *
	 * nrows - number of rows of the canvas
	 * ncols - number of columns of the canvas
	 * v	 - the character to initialise the canvas to; '\0' by default
	 *
	 *	Runs in nrows * time required to allocate new vector and initialize
	 *	values to v
	 *
	 *	Uses up:
	 *	  nrows * ncols chars worth of memory,
	 *	    (primary memory sink)
	 *	  nrows worth of vector class member metadata
	 *	  nrows + ncols ints 
	 *
	 *	time and space - O(nrows * ncols)
	 */

	for (int i = 0; i < nrows; i++)
		m_Rows.push_back(std::vector<char>(ncols, v));

	m_Rmap = std::vector<int>(nrows);
	m_Cmap = std::vector<int>(ncols);

	for (int i = 0; i < nrows; i++)
		m_Rmap[i] = i;

	for (int i = 0; i < ncols; i++)
		m_Cmap[i] = i;
}

void Canvas::draw() {
	/*
	 * Prints the Ascii grid to screen
	 *
	 * Runs in nrows * ncols complexity
	 *
	 * Uses up:
	 *   (excluding data held by this class)
	 *   O(1) for variables on the runtime stack
	 *
	 * time  - O(nrows * ncols)
	 * space - O(1)
	 *
	 */

	for (int i = 0; i < m_Rmap.size(); i++) {
		for (int j = 0; j < m_Cmap.size(); j++) {
			std::cout << m_Rows[m_Rmap[i]][m_Cmap[j]];
		}
		std::cout << '\n';
	}
}

bool Canvas::set(unsigned row, unsigned col, char v) {
	/*
	 * Writes a character to a location on the canvas
	 *
	 * row - the 0-indexed row to write the character to
	 * col - the 0-indexed column to write to
	 * v   - the character to write
	 *
	 * returns false on invalid parameters
	 *
	 * time  - O(1)
	 * space - O(1)
	 *
	 */

	if (!(row < m_Rmap.size() && col < m_Cmap.size()))
		return false;

	m_Rows[m_Rmap[row]][m_Cmap[col]] = v;
	return true;
}

void Canvas::add_row(unsigned pos, char v='\0') {
	/*
	 * Inserts a straight row across the canvas at a specified height
	 *
	 * pos - the 0-indexed position/height of the new row
	 * v   - the character to fill the row with; by default '\0'
	 *
	 * Runs in O(ncols + nrows) time complexity
	 *   to write the value into a row
	 *   and to update the mapping between stored rows and drawn rows
	 *
	 * Uses up
	 *   (other than the O(ncols) new values being added to the canvas,
	 *    and the O(nrows) new values potentially added to the resizing array)
	 *   O(1) space
	 *
	 */

	if (m_Rmap.size() < pos)
		pos = m_Rmap.size();

	m_Rows.push_back(std::vector<char>(m_Cmap.size(), v));
	m_Rmap.insert(m_Rmap.begin() + pos, m_Rmap.size());
}

void Canvas::add_col(unsigned pos, char v='\0') {
	/*
	 * Inserts a straight column down the canvas at a specified horizontal displacement
	 *
	 * pos - the 0-indexed position/horizontal indec of the new column
	 * v   - the value to fill the column with; by default '\0'
	 *
	 * Runs in O(nrows + ncols) complexity like add_row
	 *   to write new values to each of the rows (this may cause row vectors to resize, but the ammortized cost is O(1))
	 *   and to update the column translation map
	 *
	 * Uses up O(1) space
	 *
	 */
	
	for (int i = 0; i < m_Rmap.size(); i++)
		m_Rows[i].push_back(v);

	if (m_Cmap.size() < pos)
		pos = m_Cmap.size();

	m_Cmap.insert(m_Cmap.begin() + pos, m_Cmap.size());
}

void Canvas::clean() {
	/*
	 * For slightly better memory locality, this reorganizes the data in
	 *   each row and resets the translation map to a 0-ncols range
	 * This only really comes into play for large rows
	 *
	 * Runs in O(nrows * ncols) complexity, because it rewrites all the values
	 *
	 * uses up O(ncols) space for temporary storage
	 *
	 */

	char* temp = new char[m_Cmap.size()];
	for (int i = 0; i < m_Rmap.size(); i++) {

		for (int j = 0; j < m_Cmap.size(); j++)
			temp[j] = m_Rows[i][m_Cmap[j]];

		for (int j = 0; j < m_Cmap.size(); j++)
			m_Rows[i][j] = temp[j];
	}

	for (int j = 0; j < m_Cmap.size(); j++)
		m_Cmap[j] = j;

	delete temp;

}

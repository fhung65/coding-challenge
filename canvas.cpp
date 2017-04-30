#include "canvas.h"
#include <vector>
#include <stddef.h>
#include <iostream>

Canvas::Canvas(unsigned nrows, unsigned ncols, char v='\0') {
	/*
	 *
	 *
	 *	Runs in nrows * time required to allocate new vector and initialize
	 *	values to v
	 *
	 *	O(nrows * ncols)
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

	for (int i = 0; i < m_Rmap.size(); i++) {
		for (int j = 0; j < m_Cmap.size(); j++) {
			std::cout << m_Rows[m_Rmap[i]][m_Cmap[j]];
		}
		std::cout << '\n';
	}
}

bool Canvas::set(unsigned row, unsigned col, char v) {
	/*
	 * returns false on invalid parameters
	 *
	 *
	 */

	if (!(row < m_Rmap.size() && col < m_Cmap.size()))
		return false;

	m_Rows[m_Rmap[row]][m_Cmap[col]] = v;
	return true;
}

void Canvas::add_row(unsigned pos, char v='\0') {

	if (m_Rmap.size() < pos)
		pos = m_Rmap.size();

	m_Rows.push_back(std::vector<char>(m_Cmap.size(), v));
	m_Rmap.insert(m_Rmap.begin() + pos, m_Rmap.size());
}

void Canvas::add_col(unsigned pos, char v='\0') {
	
	for (int i = 0; i < m_Rmap.size(); i++)
		m_Rows[i].push_back(v);

	if (m_Cmap.size() < pos)
		pos = m_Cmap.size();

	m_Cmap.insert(m_Cmap.begin() + pos, m_Cmap.size());
}

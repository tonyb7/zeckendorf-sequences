#ifndef PREPARE_GRID_H
#define PREPARE_GRID_H

#include <vector>
#include <set>
#include <utility>
#include "grid.h"

// @author bait
bool updateCache(Grid &grid, int x, int y) {
	int height = grid.getHeight();
	int width = grid.getWidth();

	if (x < height && y < width) {
		return true;
	}

	grid.setPrevHeight(height);
	grid.setPrevWidth(width);

	Displacements displacements;
	std::vector<Displacements> row;

	if (x >= height) {
		grid.setHeight(x + 1);
		for (int i = height; i < x + 1; ++i) {
			grid.pushRow(row);
		}
	}

	if (y >= width) {
		grid.setWidth(y + 1);
		for (auto& row : grid.getGrid()) {
			while (row.size() < y + 1) {
				row.push_back(displacements);
			} 
		}
	}

	return false;
}

// TODO: Bad contract?
void fillGrid(Grid &grid) {
	std::vector<std::vector<Displacements>>& the_grid = grid.getGrid(); 
	for (int i = grid.getPrevHeight(); i < grid.getHeight(); ++i) {
		Displacements displacements;
		std::pair<int, int> pair = { i, 0 };
		displacements.insert(pair);
		the_grid[i][0] = displacements;
	}
}

#endif

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
	for (int i = 0; i < grid.getHeight(); ++i) {
		for (int j = 0; j < grid.getWidth(); ++j) {
			if (!the_grid[i][j].displacements.size()) {
				if (i == 0 || j == 0) {
					std::pair<int, int> a_pair = std::make_pair(i, j);
					std::cout << "Adding " << i << ", " << j << std::endl;
					the_grid[i][j].displacements.insert(a_pair);
				} else {
					for (int x = 0; x < i; ++x) {
						for (int y = 0; y < j; ++y) {
							std::pair<int, int> a_pair = std::make_pair(i - x, j - y);
							std::cout << "Adding " << i - x << ", " << j - y << std::endl;
							the_grid[i][j].displacements.insert(a_pair);
						}
					}
				}
			}
		}
	}
}

#endif

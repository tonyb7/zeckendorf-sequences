#ifdef GRID_H
#else
#define GRID_H

#include <vector>
#include <set>
#include <utility>

// TODO: comparator for multiset to make it sorted
struct Displacements {
	std::multiset<std::pair<int, int>> displacements;
};

class Grid {
public:
	Grid() {
		height = 0;
		width = 0;
		prev_height = -1;
		prev_width = -1;
	}

	int getHeight() { return height; }
	int getWidth() { return width; }
	int getPrevHeight() { return prev_height; }
	int getPrevWidth() { return prev_width; }
	std::vector<std::vector<Displacements>>& getGrid() { return grid; }

	void setHeight(int x) { this->height = x; }
	void setWidth(int y) { this->width = y; }
	void setPrevHeight(int x) { this->prev_height = x; }
	void setPrevWidth(int y) { this->prev_width = y; }

	void pushRow(std::vector<Displacements> row) { 
		grid.push_back(row);
	}

private:
	int prev_height;
	int prev_width;
	int height;
	int width;
	std::vector<std::vector<Displacements>> grid;

};

#endif
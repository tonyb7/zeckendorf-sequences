#include "input_output.h"
#include "cache.h"

using namespace std;

int main() {
	
	cout << "Welcome. This program will give you displacements.\n";

	Grid grid;

  	int x, y;
  	while (readInput(x, y)) {
  		if (updateCache(grid, x, y)) {
			printDisplacements(grid.getGrid()[x][y]);
  		} else {
  			fillGrid(grid);
  			printDisplacements(grid.getGrid()[x][y]);
  		}
  	}

	return 0;
}

